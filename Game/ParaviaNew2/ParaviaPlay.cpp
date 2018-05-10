//ParaviaPlay File is used for defining fucntions used for the actual game play
//includes starting the game and running the game loop

#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>

#include "ParaviaHelp.hpp"

using namespace std;

void ParaviaHelp::AddRevenue(player *Me)
{
	Me->Treasury += (Me->JusticeRevenue + Me->CustomsDutyRevenue);
	Me->Treasury += (Me->IncomeTaxRevenue + Me->SalesTaxRevenue);
	if(Me->Treasury < 0)
		Me->Treasury = (int)((float)Me->Treasury * 1.5);
	if(Me->Treasury < (-10000 * Me->TitleNum))
		Me->IsBankrupt = true;
}



void ParaviaHelp::PrintGrain(player *Me)
{
	switch(Me->Harvest)
	{
		case 1: cout << "Drought. Famine Threatens. "; 
			break;
		case 2: cout << "Bad Weather. Poor Harvest. ";
			break;
		case 3: cout << "Normal Weather. Average Harvest. "; 
			break;
		case 4: cout << "Good Weather. Fine Harvest. "; 
			break;
		case 5: cout << "Excellent Weather. Great Harvest! "; 
			break;
	}
}

void ParaviaHelp::PrintInstructions()
{
    //char string[256];
    
    cout << "Santa Paravia and Fiumaccio\n\n";
    cout <<"You are the ruler of a 15th century Italian city state.\n";
    cout << "If you rule well, you will receive higher titles. The\n";
    cout << "first player to become king or queen wins. Life expectancy\n";
    cout << "then was brief, so you may not live long enough to win.\n";
    cout << "The computer will draw a map of your state. The size\n";
    cout << "of the area in the wall grows as you buy more land. The\n";
    cout << "size of the guard tower in the upper left corner shows\n";
    cout << "the adequacy of your defenses. If it shrinks, equip more\n";
    cout << "soldiers! If the horse and plowman is touching the top of the wall,\n";
    cout << "all your land is in production. Otherwise you need more\n";
    cout << "serfs, who will migrate to your state if you distribute\n";
    cout << "more grain than the minimum demand. If you distribute less\n";
    cout << "grain, some of your people will starve, and you will have\n";
    cout << "a high death rate. High taxes raise money, but slow down\n";
    cout << "economic growth. (Press ENTER to begin game)\n";
    //fgets(string, 255, stdin);
}





void ParaviaHelp::BuySellGrain(player *Me)
{
    bool Finished;
    char string[256];
    Finished = false;
    while(Finished == false)
    {
        cout << "\nYear " << Me->Year << " \n", Me->Year;
        cout << "\n" << Me->Title << " " << Me->Name << "\n\n";
        cout << "Rats ate " << Me->Rats << " of your grain reserves.\n";
        PrintGrain(Me);
        cout << "(" << Me-RatsAte << " steres)\n\n";
        cout << "Grain\tGrain\tPrice of\tPrice of\tTreasury\n";
        cout << "Reserve\tDemand\tGrain\t\tLand\n";
        cout << Me->GrainReserve << "\t" << Me->GrainDemand << "\t" << Me->GrainPrice << "\t" << Me->LandPrice << "\t\t" << Me->Treasury << "\n";
        cout << "steres\tsteres\t1000 st.\thectare\t\tgold florins\n";
        cout << "\nYou have " << Me->Land << " hectares of land.\n";
        cout << "\n1. Buy grain, 2. Sell grain, 3. Buy land,";
        cout << " 4. Sell land\n(Enter q to continue): ";
        fgets(string, 255, stdin);
        if(string[0] == 'q')
            Finished = true;
        if(string[0] == '1')
            BuyGrain(Me);
        if(string[0] == '2')
            SellGrain(Me);
        if(string[0] == '3')
            BuyLand(Me);
        if(string[0] == '4')
            SellLand(Me);
    }
}

void ParaviaHelp::AdjustTax(player *Me)
{
    char string[256];
    int val = 1, duty = 0;
    string[0] = '\0';
    while(val != 0 || string[0] != 'q')
    {
        cout << "\n" << Me->Title << " " << Me->Name << "\n\n";
		GenerateIncome(Me);
        cout << Me->CustomsDuty << "\t\t" << Me->SalesTax << "\t\t" << Me->IncomeTax;
    	cout << "\n1. Customs Duty, 2. Sales Tax, 3. Wealth Tax, ";
        cout << "4. Justice\n";
        cout << "Enter tax number for changes, q to continue: ";
        fgets(string, 255, stdin);
        val = (int)atoi(string);
        switch(val)
        {
            case 1: cout << "New customs duty (0 to 100): ";
                fgets(string, 255, stdin);
                duty = (int)atoi(string);
                if(duty > 100) duty = 100;
                if(duty < 0) duty = 0;
                Me->CustomsDuty = duty;
                break;
            case 2: cout << "New sales tax (0 to 50): ";
                fgets(string, 255, stdin);
                duty = (int)atoi(string);
                if(duty > 50) duty = 50;
                if(duty < 0) duty = 0;
                Me->SalesTax = duty;
                break;
            case 3: cout << "New wealth tax (0 to 25): ";
                fgets(string, 255, stdin);
                duty = (int)atoi(string);
                if(duty > 25) duty = 25;
                if(duty < 0) duty = 0;
                Me->IncomeTax = duty;
                break;
            case 4: cout << "Justice: 1. Very fair, 2. Moderate";
                cout << " 3. Harsh, 4. Outrageous: ";
                fgets(string, 255, stdin);
                duty = (int)atoi(string);
                if(duty > 4) duty = 4;
                if(duty < 1) duty = 1;
                Me->Justice = duty;
                break;
        }
    
    }
    AddRevenue(Me);
    if(Me->IsBankrupt == true)
    SeizeAssets(Me);
}

void ParaviaHelp::StatePurchases(player *Me, int HowMany, player MyPlayers[6])
{
	char string[256];
    int val = 1;
    string[0] = '\0';
    while(val != 0 || string[0] != 'q')
    {
        cout << "\n\n" << Me->Title << " " << Me->Name << " \nState purchases.\n";
        cout << "\n1. Marketplace (" << Me->Marketplaces << ")\t\t\t\t1000 florins\n";
        cout << "2. Woolen mill (" << Me->Mills << ")\t\t\t\t2000 florins\n";
        cout << "3. Palace (partial) (" << Me->Palace << ")\t\t\t\t3000 florins\n";
        cout << "4. Cathedral (partial) (" << Me->Cathedral << ")\t\t\t5000 florins\n";
        cout << "5. Equip one platoon of serfs as soldiers\t500 florins\n";
        cout << "\nYou have " << Me->Treasury << " gold florins.\n";
        cout << "\nTo continue, enter q. To compare standings, enter 6\n";
        cout << "Your choice: ";
        fgets(string, 255, stdin);
        val = (int)atoi(string);
        switch(val)
        {
            case 1: BuyMarket(Me); break;
            case 2: BuyMill(Me); break;
            case 3: BuyPalace(Me); break;
            case 4: BuyCathedral(Me); break;
            case 5: BuySoliders(Me); break;
            case 6: ShowStats(MyPlayers, HowMany);
            }
    }
}

void ParaviaHelp::ShowStats(player MyPlayers[6], int HowMany)
{
    int i = 0;
    char string[256];
    cout << "Nobles\tSoldiers\tClergy\tMerchants\tSerfs\tLand\tTreasury\n";
    for(; i < HowMany; i++)
        cout << "\n" << MyPlayers[i].Title << " " << MyPlayers[i].Name << "\n" << MyPlayers[i].Nobles
             << "\t" << MyPlayers[i].Soldiers << "\t\t" << MyPlayers[i].Clergy << "\t" <<  MyPlayers[i].Merchants
             << "\t\t" << MyPlayers[i].Serfs << "\t" << MyPlayers[i].Land << "\t" << MyPlayers[i].Treasury << "\n";
    cout << "\n(Press ENTER): ";
    fgets(string, 255, stdin);
}

void ParaviaHelp::ImDead(player *Me)
{
    char string[256];
    int why;
    
    cout <<"\n\nVery sad news.\n" << Me->Title << " " << Me->Name << " has just died\n";
    
    if(Me->Year > 1450)
        cout << "of old age after a long reign.\n";
    else
    {
        why = Random(8);
        switch(why)
        {
            case 0:
            case 1:
            case 2:
            case 3: cout << "of pneumonia after a cold winter in a drafty castle.\n"; break;
            case 4: cout << "of typhoid after drinking contaminated water.\n"; break;
            case 5: cout << "in a smallpox epidemic.\n"; break;
            case 6: cout << "after being attacked by robbers while travelling.\n"; break;
            case 7:
            case 8: cout << "of food poisoning.\n"; break;
        }
    }
    Me->IsDead = true;
    printf("\n(Press ENTER): ");
    fgets(string, 255, stdin);
}

//start the next turn
    void ParaviaHelp::NewTurn(player *Me, int HowMany, player MyPlayers[6], player *Baron)
    {
    int i;
    GenerateHarvest(Me);
    NewLandAndGrainPrices(Me);
    BuySellGrain(Me);
    ReleaseGrain(Me);
    if(Me->InvadeMe == true)
    {
        for(i = 0; i < HowMany; i++)
            if(i != Me->WhichPlayer)
                if(MyPlayers[i].Soldiers > (Me->Soldiers * 2.4))
                {
                    AttackNeighbor(&MyPlayers[i], Me);
                    i = 9;
                }
        if(i != 9)
            AttackNeighbor(Baron, Me);
    }
    AdjustTax(Me);
    //DrawMap(Me);
    StatePurchases(Me, HowMany, MyPlayers);
    CheckNewTitle(Me);
    
    Me->Year++;
    if(Me->Year == Me->YearOfDeath)
        ImDead(Me);
    if(Me->TitleNum >= 7)
        Me->IWon = true;
    }
    //loop for the entire game
    void ParaviaHelp::PlayGame(player MyPlayers[6], int NumOfPlayers)
    {
        bool AllDead, Winner;
        int i, WinningPlayer = 0;
        player Baron;
        AllDead = false;
        Winner = false;
        InitializePlayer(&Baron, 1400, 6, 4, "Peppone", true);
        while(AllDead == false && Winner == false)
        {
            for(i = 0; i < NumOfPlayers; i++)
                if(MyPlayers[i].IsDead == false)
                    NewTurn(&MyPlayers[i], NumOfPlayers, MyPlayers,
                            &Baron); 
            AllDead = true;
            for(i = 0; i < NumOfPlayers; i++)
                if(AllDead == true && MyPlayers[i].IsDead == false)
                    AllDead = false;
            for(i = 0; i < NumOfPlayers; i++)
                if(MyPlayers[i].IWon == true)
                {
                    Winner = true;
                    WinningPlayer = i;
                }
        }
        if(AllDead == true)
        {
            cout << "The game has ended.\n";
        }
        cout << "Game Over. " << MyPlayers[WinningPlayer].Title << " " <<  MyPlayers[WinningPlayer].Name << " wins.\n";
    }

    //attacking your neighbor
    int ParaviaHelp::AttackNeighbor(player *Me, player *Him)
    {
        int LandTaken;
        int deadsoldiers = 0;
        if(Me->WhichPlayer == 7)
            LandTaken = Random(9000) + 1000;
        else
            LandTaken = (Me->Soldiers * 1000) - (Me->Land / 3);
        if(LandTaken > (Him->Land - 5000))
            LandTaken = (Him->Land - 5000) / 2;
        Me->Land += LandTaken;
        Him->Land -= LandTaken;
        std::cout << "\n" << Me->Title << " " << Me->Name << " invades and seizes " << Me->City << " hectares of land!\n";
        deadsoldiers = Random(40);
        if(deadsoldiers > (Him->Soldiers - 15))
            deadsoldiers = Him->Soldiers - 15;
        Him->Soldiers -= deadsoldiers;
        std::cout << Him->Title << " " << Him->Name << " loses " << deadsoldiers << " soliders in battle.\n";
        return LandTaken;
    }