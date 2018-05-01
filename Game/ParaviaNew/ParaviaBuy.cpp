//ParaviaBuy.cpp is a file to define the function from the header file

#include "ParaviaBuy.hpp"
#include "ParaviaHelp.hpp"

#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<curses.h>

using namespace std;

void ParaviaBuy::BuyCathedral
{
	Me->Cathedral += 1;
	Me->Clergy += Random(6);
	Me->Treasury -= 5000;
	Me->PublicWorks += 1.0;
	return 0;
}

void ParaviaBuy::BuyGrain
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
			return 0;
		}
	}
	Me->Treasury -= (HowMuch * Me->GrainPrice / 1000);
	Me->GrainReserve += HowMuch;
	return 0;
}

void ParaviaBuy::BuyLand(player *Me)
{
	char string[256];
	int HowMuch;
	cout << "How much land do you want to buy? ";
	fgets(string, 255, stdin);
	HowMuch = (int)atoi(string);
	Me->Land += HowMuch;
	Me->Treasury -= (int)(((float)HowMuch * Me->LandPrice));
	return 0;
}

void ParaviaBuy::BuyMarket
{
	Me->Marketplaces += 1;
	Me->Merchants += 5;
	Me->Treasury -= 1000;
	Me->PublicWorks += 1.0;
	return 0;
}

void ParaviaBuy::BuyMill
{
	Me->Mills += 1;
	Me->Treasury -= 2000;
	Me->PublicWorks += 0.25;
	return 0;
}

void ParaviaBuy::BuyPalace
{
	Me->Palace += 1;
	Me->Nobles += Random(2);
	Me->Treasury -= 3000;
	Me->PublicWorks += 0.5;
	return 0;
}

void ParaviaBuy::BuySoliders
{
	Me->Soldiers += 20;
	Me->Serfs -= 20;
	Me->Treasury -= 500;
	return 0;
}










