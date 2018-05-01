//ParaviaHelp file is used to define all varaibles used in the game
//Along with helper functions for the operations of the game

#pragma once

#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<curses.h>


struct PlayerHelp
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

    //Runninng Random Ingrations in the game
    int Random(int Hi)
    {
    	float RanNum;
    	Randnum = (float)rand();
    	Randnum /= (float)RAND_MAX;
    	Randnum *= (float)Hi;
    	return ((int)Randnum);
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
    	cout << Me->DeadSerfs << " serfs die this year.\n";
    	return 0;
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
		cout << Me->NewSerfs << " serfs born this year.\n";
		return 0;
    }

    int limit(int num, int demon)
    {
    	int val;
    	val = num / demon;
    	return(val > 10 ? 10 : val);
    }
};














