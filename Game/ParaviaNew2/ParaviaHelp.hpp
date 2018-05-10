//ParaviaHelp file is used to store and define the main functions and
//varaiables for the game operations

#pragma once

#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
//#include<curses.h>

//create the main player
typedef struct ParaviaHelp player;

//Paravia Class to define and declare variables and functions
struct ParaviaHelp
{
    
	int Cathedral, Clergy, CustomsDuty, CustomsDutyRevenue, DeadSerfs;
	int Difficulty, FleeingSerfs, GrainDemand, GrainPrice, GrainReserve;
	int Harvest, IncomeTax, IncomeTaxRevenue, RatsAte;
	int Justice, JusticeRevenue, Land, Marketplaces, MarketRevenue;
	int Merchants, MillRevenue, Mills, NewSerfs, Nobles, OldTitle, Palace;
	int Rats, SalesTax, SalesTaxRevenue, Serfs, SoldierPay, Soldiers, TitleNum;
	int TransplantedSerfs, Treasury, WhichPlayer, Year, YearOfDeath;
	char City[15], Name[25], Title[15];
	float PublicWorks, LandPrice;
	bool InvadeMe, IsBankrupt, IsDead, IWon, MaleOrFemale, NewTitle;


	//List of Names of Cities
	char CityList[7][15] = {"Santa Paravia", "Fiumaccio", "Torricella", "Molinetto",
							"Fontanile", "Romanga", "Monterana"};

    //Male Titels
	char MaleTitles[8][15] = {"Sir", "Baron", "Count", "Marquis", "Duke",
 							  "Grand Duke", "Prince", "* H.R.H. King"};

 	//Female Titles
 	char FemaleTitles[8][15] = {"Lady", "Baroness", "Countess", "Marquise",
 								"Duchess", "Grand Duchess", "Princess",
            					"* H.R.H. Queen"};


    //The next feew functions are just used for basic game interactions and
    //Don't have a play in a differet cpp file.
    //Runninng Random Ingrations in the game
    int Random(int Hi)
    {
    	float RandNum;
    	RandNum = (float)rand();
    	RandNum /= (float)RAND_MAX;
    	RandNum *= (float)Hi;
    	return ((int)RandNum);
    }

    //Function to show how many serfs will die in the current year, randomly choosen
    void SerfsDecomposing(player *Me, float MyScale)
    {
    	int absc;
    	float ord;
    	absc = (int)MyScale;
    	ord = MyScale - (float)absc;
    	Me->DeadSerfs = (int)((((float)Random(absc) + ord) * (float)Me->Serfs) /
        						 100.0);
		Me->Serfs -= Me->DeadSerfs;
    	std::cout << Me->DeadSerfs << " serfs die this year.\n";
    }

    //Function to show how many serfs are added to the city
    void SerfsProcreating(player *Me, float MyScale)
    {
    	int absc;
    	float ord;
    	absc = (int)MyScale;
    	ord = MyScale - (float)absc;
		Me->NewSerfs = (int)((((float)Random(absc) + ord) * (float)Me->Serfs) /
        						100.0);
		Me->Serfs += Me->NewSerfs;
		std::cout << Me->NewSerfs << " serfs born this year.\n";
		
    }

    //user declared limits function for division
    int limit(int num, int demon)
    {
    	int val;
    	val = num / demon;
    	return(val > 10 ? 10 : val);
    }

    //Game Functions for running each aspect of the game
    //declared here and defined in other files
    //function to buy cathedral
	void BuyCathedral(player *Me);
	//function to buy grain
	void BuyGrain(player *Me);
	//function to buy land
	void BuyLand(player *Me);
	//function to buy market place
	void BuyMarket(player *Me);
	//function to buy a Mill
	void BuyMill(player *Me);
	//function to buy a palace
	void BuyPalace(player *Me);
	//function to buy soliders for the city
	void BuySoliders(player *Me);
	//funciton to create the player and starting stats
	void InitializePlayer(player *Me, int year, int city, int level, char *name, bool Morf);
	//function to check title for player difficulty
	bool CheckNewTitle(player *Me);
	//function to generate harverst for start
	void GenerateHarvest(player *Me);
	//function to generate income for start
	void GenerateIncome(player *Me);
	//function to change the title of the player
	void ChangeTitle(player *Me);
	//function to change the grain prices for each turn
	void NewLandAndGrainPrices(player *Me);
	//function to release grain, asks user how much they want to save and sell
	int ReleaseGrain(player *Me);
	//function to show how much you will loose from creditors
	void SeizeAssets(player *Me);
	//function for user to sell grain
	void SellGrain(player *Me);
	//function for user to sell Land
	void SellLand(player *Me);
	//function to show how much you have and if you are broke
	void AddRevenue(player *Me);
	//function for attacking other players
	int AttackNeighbor(player *Me, player *Him);
	//function to print how much grain you have
	void PrintGrain(player *Me);
	//function to print the instructions of the game
	void PrintInstructions();
	//function to loop for the entire game play
	void PlayGame(player MyPlayers[6], int NumOfPlayers);
	//function for each turn
	void NewTurn(player *Me, int HowMany, player MyPlayers[6], player *Baron);
	//function for buying and selling grain
	void BuySellGrain(player *Me);
	//function to adjust the tax for each city
	void AdjustTax(player *Me);
	//function to buy different buildings 
	void StatePurchases(player *Me, int HowMany, player MyPlayers[6]);
	//function to show the stats of players cities
	void ShowStats(player MyPlayers[6], int HowMany);
	//function to end the game
	void ImDead(player *Me);
};