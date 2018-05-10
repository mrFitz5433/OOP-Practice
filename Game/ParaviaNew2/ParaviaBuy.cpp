//ParaviaBuy cpp file is for defining the fucntions used for user
//buying different items inside the game

#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>

#include "ParaviaHelp.hpp"

using namespace std;

void ParaviaHelp::BuyCathedral(player* Me)
{
	Me->Cathedral += 1;
	Me->Clergy += Random(6);
	Me->Treasury -= 5000;
	Me->PublicWorks += 1.0;

}

void ParaviaHelp::BuyGrain(player* Me)
{
	char str[256];
	int HowMuch;
	cout << "How much Grain do you want to buy? (0 to specify a total) ";
	fgets(str, 255, stdin);
	HowMuch = (int)atoi(str);
	if(HowMuch == 0)
	{
		cout << "How much grain do you wish to buy? ";
		fgets(str, 255, stdin);
		HowMuch = (int)atoi(str);
		HowMuch -= Me->GrainReserve;
		if(HowMuch < 0)
		{
			cout << "Invalid total amount.\n\n";
		}
	}
	Me->Treasury -= (HowMuch * Me->GrainPrice / 1000);
	Me->GrainReserve += HowMuch;
}

void ParaviaHelp::BuyLand(player *Me)
{
	char string[256];
	int HowMuch;
	cout << "How much land do you want to buy? ";
	fgets(string, 255, stdin);
	HowMuch = (int)atoi(string);
	Me->Land += HowMuch;
	Me->Treasury -= (int)(((float)HowMuch * Me->LandPrice));
}

void ParaviaHelp::BuyMarket(player* Me)
{
	Me->Marketplaces += 1;
	Me->Merchants += 5;
	Me->Treasury -= 1000;
	Me->PublicWorks += 1.0;
}

void ParaviaHelp::BuyMill(player* Me)
{
	Me->Mills += 1;
	Me->Treasury -= 2000;
	Me->PublicWorks += 0.25;
}

void ParaviaHelp::BuyPalace(player* Me)
{
	Me->Palace += 1;
	Me->Nobles += Random(2);
	Me->Treasury -= 3000;
	Me->PublicWorks += 0.5;
}

void ParaviaHelp::BuySoliders(player* Me)
{
	Me->Soldiers += 20;
	Me->Serfs -= 20;
	Me->Treasury -= 500;
}