//ParaviaInterface.cpp is the file to define the functions from the header file

#include"ParaviaInterface.hpp"
#include"ParaviaHelp.hpp"

#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<curses.h>

using namespace std;

void ParaviaInterface::InitializaPlayer(player *Me, int year, int city, int level, char *name, bool Morf)
{
	Me->Cathedral = 0;
	strcpy(Me->City, CityList[city]);
	Me->Clergy = 5;
	Me->CustomsDuty = 25;
	Me->Difficulty = level;
	Me->GrainPrice = 25;
	Me->GrainReserve = 5000;
	Me->IncomeTax = 5;
	Me->IsBankrupt = False;
	Me->IsDead = False;
	Me->IWon = False;
	Me->Justice = 2;
	Me->Land = 10000;
	Me->LandPrice = 10.0;
	Me->MaleOrFemale = MorF;
	Me->Marketplaces = 0;
	Me->Merchants = 25;
	Me->Mills = 0;
	strcpy(Me->Name, name);
	Me->Nobles = 4;
	Me->OldTitle = 1;
	Me->Palace = 0;
	Me->PublicWorks = 1.0;
	Me->SalesTax = 10;
	Me->Serfs = 2000;
	Me->Soldiers = 25;
	Me->TitleNum = 1;
	if(Me->MaleOrFemale == True)
	strcpy(Me->Title, MaleTitles[0]);
	else
	strcpy(Me->Title, FemaleTitles[0]);
	if(city == 6) strcpy(Me->Title, "Baron");
	Me->Treasury = 1000;
	Me->WhichPlayer = city;
	Me->Year = year;
	Me->YearOfDeath = year + 20 + Random(35);
	return 0;
}

bool ParaviaInterface::CheckNewTitle(player *Me)
{
	int Total;
	Total = limit(Me->Marketplaces, 1);
	Total += limit(Me->Palace, 1);
	Total += limit(Me->Cathedral, 1);
	Total += limit(Me->Mills, 1);
	Total += limit(Me->Treasury, 5000);
	Total += limit(Me->Land, 6000);
	Total += limit(Me->Merchants, 50);
	Total += limit(Me->Nobles, 5);
	Total += limit(Me->Soldiers, 50);
	Total += limit(Me->Clergy, 10);
	Total += limit(Me->Serfs, 2000);
	Total += limit((int)(Me->PublicWorks * 100.0), 500);
	Me->TitleNum = (Total / Me->Difficulty) - Me->Justice;
	if(Me->TitleNum > 7)
	Me->TitleNum = 7;
	if(Me->TitleNum < 0)
	Me->TitleNum = 0;
	/* Did we change (could be backwards or forwards)? */
	if(Me->TitleNum > Me->OldTitle)
	{
		Me->OldTitle = Me->TitleNum;
		ChangeTitle(Me);
		cout << "Good News " << Me->Name << " has achieved the rank of " << Me->Title << "\n\n";
		return True;
	}
	Me->TitleNum = Me->OldTitle;
	return False;
}

void ParaviaInterface::GenerateHarvest(player *me)
{
	Me->Harvest = (Random(5) + Random(6)) / 2;
	Me->Rats = Random(50);
	Me->GrainReserve = ((Me->GrainReserve * 100) - (Me->GrainReserve * Me->Rats)) / 100;
	return 0;
}

void ParaviaInterface::GenerateIncome(player *Me)
{
	float y;
	int revenues = 0;
	char str[256];
	Me->JusticeRevenue = (Me->Justice * 300 - 500) * Me->TitleNum;
	switch(Me->Justice)
	{
	    case 1: strcpy(string, "Very Fair"); 
	    	break;
	    case 2: strcpy(string, "Moderate"); 
	    	break;
	    case 3: strcpy(string, "Harsh"); 
	    	break;
	    case 4: strcpy(string, "Outrageous");
	}
	y = 150.0 - (float)Me->SalesTax - (float)Me->CustomsDuty -
	    (float)Me->IncomeTax;
	if(y < 1.0)
		y = 1.0;
	y /= 100.0;
	Me->CustomsDutyRevenue = Me->Nobles * 180 + Me->Clergy * 75 +
	     Me->Merchants * 20 * y;
	Me->CustomsDutyRevenue += (int)(Me->PublicWorks * 100.0);
	Me->CustomsDutyRevenue = (int)((float)Me->CustomsDuty / 100.0 *
	         (float)Me->CustomsDutyRevenue);
	Me->SalesTaxRevenue = Me->Nobles * 50 + Me->Merchants * 25 +
	     (int)(Me->PublicWorks * 10.0);
	Me->SalesTaxRevenue *= (y * (5 - Me->Justice) * Me->SalesTax);
	Me->SalesTaxRevenue /= 200;
	Me->IncomeTaxRevenue = Me->Nobles * 250 + (int)(Me->PublicWorks * 20.0);
	Me->IncomeTaxRevenue += (10 * Me->Justice * Me->Nobles * y);
	Me->IncomeTaxRevenue *= Me->IncomeTax;
	Me->IncomeTaxRevenue /= 100;
	revenues = Me->CustomsDutyRevenue + Me->SalesTaxRevenue +
	    Me->IncomeTaxRevenue + Me->JusticeRevenue;
	cout << "State revenuse " << revenues << " gold florins.\n";
	cout << "Customs Duty\t Sales Tax\t Income Tax\t Justice\n "
		 << Me->CustomsDutyRevenue << "\t\t"
		 << Me->SalesTaxRevenue << "\t\t"
		 << Me->IncomeTaxRevenue << "\t\t"
		 << Me->JusticeRevenue << "\t\t"
		 << str << "\n";
	return 0;
}

void ParaviaInterface::ChangeTitle(player *Me)
{
	if(Me->MaleOrFemale == True)
		strcpy(Me->Title, MaleTitles[Me->TitleNum]);
	else
		strcpy(Me->Title, FemaleTitles[Me->TitleNum]);
	if(Me->TitleNum == 7)
	{
		Me->IWon = True;
		return 0;
	}
	return 0;
}

void ParaviaInterface::NewLandAndGrainPrices(player *Me)
{
	float x, y, MyRandom;
	int h;
	MyRandom = (float)((float)rand() / (float)RAND_MAX);
	/* If you think this C code is ugly, you should see the original BASIC. */
	x = (float)Me->Land;
	y = (((float)Me->Serfs - (float)Me->Mills) * 100.0) * 5.0;
	if(y < 0.0)
		y = 0.0;
	if(y < x)
		x = y;
	y = (float)Me->GrainReserve * 2.0;
	if(y < x)
		x = y;
	y = (float)Me->Harvest + (MyRandom - 0.5);
	h = (int)(x * y);
	Me->GrainReserve += h;
	Me->GrainDemand = (Me->Nobles * 100) + (Me->Cathedral * 40) + (Me->Merchants * 30);
	Me->GrainDemand += ((Me->Soldiers * 10) + (Me->Serfs * 5));
	Me->LandPrice = (3.0 * (float)Me->Harvest + (float)Random(6) + 10.0) / 10.0;
	if(h < 0)
	    h *= -1;
	if(h < 1)
		y = 2.0;
	else
	{
		y = (float)((float)Me->GrainDemand / (float)h);
		if(y > 2.0)
			y = 2.0;
	}
	if(y < 0.8)
		y = 0.8;
	Me->LandPrice *= y;
	if(Me->LandPrice < 1.0) Me->LandPrice = 1.0;
		Me->GrainPrice = (int)(((6.0 - (float)Me->Harvest) * 3.0 + (float)Random(5)
	            + (float)Random(5)) * 4.0 * y);
	Me->RatsAte = h; 
	return 0;
}

int ParaviaInterface::ReleaseGrain(player *Me)
{
	double xp, zp;
	float x, z;
	char string[256];
	int HowMuch, Maximum, Minimum;
	bool IsOK;
	IsOK = False;
	Minimum = Me->GrainReserve / 5;
	Maximum = (Me->GrainReserve - Minimum);
	while(IsOK == False)
	{
		cout << "How much grain will you release for consumption?\n";
		cout << "1 - Minimun " << Minimun << ", 2 - Maximum " << Maximum << ", or enter a value: ";
		fgets(string, 255, stdin);
		HowMuch = (int)atoi(string);
		if(HowMuch == 1)
		   HowMuch = Minimum;
		   if(HowMuch == 2)
		    	HowMuch = Maximum;
		   if(HowMuch < Minimum)
		cout << "You must release at least 20% of your reserves.\n";
		   else if(HowMuch > Maximum)
		cout << "You must keep at least 20%.\n";
		   else
		IsOK = True;
	}
	Me->SoldierPay = Me->MarketRevenue = Me->NewSerfs = Me->DeadSerfs = 0;
	Me->TransplantedSerfs = Me->FleeingSerfs = 0;
	Me->InvadeMe = False;
	Me->GrainReserve -= HowMuch;
	z = (float)HowMuch / (float)Me->GrainDemand - 1.0;
	if(z > 0.0)
		z /= 2.0;
	if(z > 0.25)
		z = z / 10.0 + 0.25;
	zp = 50.0 - (double)Me->CustomsDuty - (double)Me->SalesTax -
	    (double)Me->IncomeTax;
	if(zp < 0.0)
		zp *= (double)Me->Justice;
	zp /= 10.0;
	if(zp > 0.0)
		zp += (3.0 - (double)Me->Justice);
	z += ((float)zp / 10.0);
	if(z > 0.5)
		z = 0.5;
	if(HowMuch < (Me->GrainDemand - 1))
	{
		x = ((float)Me->GrainDemand - (float)HowMuch) /
		    (float)Me->GrainDemand * 100.0 - 9.0;
		xp = (double)x;
		if(x > 65.0)
			x = 65.0;
		if(x < 0.0)
		{
			xp = 0.0;
			x = 0.0;
		}
		SerfsProcreating(Me, 3.0);
		SerfsDecomposing(Me, xp + 8.0);
	}
	else
	{
		SerfsProcreating(Me, 7.0);
		SerfsDecomposing(Me, 3.0);
		if((Me->CustomsDuty + Me->SalesTax) < 35)
			Me->Merchants += Random(4);
		if(Me->IncomeTax < Random(28))
		{
			Me->Nobles += Random(2);
			Me->Clergy += Random(3);
		}
		if(HowMuch > (int)((float)Me->GrainDemand * 1.3))
		{
			zp = (double)Me->Serfs / 1000.0;
			z = ((float)HowMuch - (float)(Me->GrainDemand)) /
			(float)Me->GrainDemand * 10.0;
			z *= ((float)zp * (float)Random(25));
			z += (float)Random(40);
			    Me->TransplantedSerfs = (int)z;
			    Me->Serfs += Me->TransplantedSerfs;
			    cout << Me->TransplantedSerfs << " serfs move to the city\n";
			zp = (double)z;
			z = ((float)zp * (float)rand()) / (float)RAND_MAX;
			if(z > 50.0)
				z = 50.0;
			Me->Merchants += (int)z;
			Me->Nobles++;
			Me->Clergy += 2;
		}
	}
	if(Me->Justice > 2)
	{
		Me->JusticeRevenue = Me->Serfs / 100 * (Me->Justice - 2) *
		     (Me->Justice - 2);
		Me->JusticeRevenue = Random(Me->JusticeRevenue);
		Me->Serfs -= Me->JusticeRevenue;
		Me->FleeingSerfs = Me->JusticeRevenue;
		cout << Me->FleeingSerfs << "serfs flee harsh justice.\n";
	}
	Me->MarketRevenue = Me->Marketplaces * 75;
	if(Me->MarketRevenue > 0)
	{
		Me->Treasury += Me->MarketRevenue;
	    cout << "Your market earned " << Me->MarketRevenue << " florins.\n";
	}
	Me->MillRevenue = Me->Mills * (55 + Random(250));
	if(Me->MillRevenue > 0)
	{
		Me->Treasury += Me->MillRevenue;
	    cout << "Your woolen mill earned " << Me->MillRevenue << " florins.\n";
	}
	Me->SoldierPay = Me->Soldiers * 3;
	Me->Treasury -= Me->SoldierPay;
	cout << "You paid your soldiers " << Me->SoldierPay << " florins.\n";
	cout << "You have " << Me->Serfs << " serfs in your city.\n";
	cout << "Please Enter: ";
	fgets(string, 255, stdin);
	if((Me->Land / 1000) > Me->Soldiers)
	{
		Me->InvadeMe = True;
		return 3;
	}
	if((Me->Land / 500) > Me->Soldiers)
	{
		Me->InvadeMe = True;
		return 3;
	}
	return 0;
}

void ParaviaInterface::SeizeAssets(player *Me)
{
	char string[256];
	Me->Marketplaces = 0;
	Me->Palace = 0;
	Me->Cathedral = 0;
	Me->Mills = 0;
	Me->Land = 6000;
	Me->PublicWorks = 1.0;
	Me->Treasury = 100;
	Me->IsBankrupt = False;
	cout << "\n\n" << Me->Title << " " << Me->Name << " is bankrupt.\n";
	cout << "\nCreditors have seized much of your assets.\n";
	cout << "\nPress Enter: ";
	fgets(string, 255, stdin);
	return 0;
}

void ParaviaInterface::SellGrain(player *Me)
{
	char string[256];
	int HowMuch;
	cout << "How much grain do you want to sell? ";
	fgets(string, 255, stdin);
	HowMuch = (int)atoi(string);
	if(HowMuch > Me->GrainReserve)
	{
	    cout << "Your don't have it.\n";
		return 0;
	}   
	Me->Treasury += (HowMuch * Me->GrainPrice / 1000);
	Me->GrainReserve -= HowMuch;
	return 0;
}

void ParaviaInterface::SellLand(player *Me)
{
	char string[256];
	int HowMuch;
	cout << "How much land do you want to sell? ";
	fgets(string, 255, stdin);
	HowMuch = (int)atoi(string);
	if(HowMuch > (Me->Land - 5000))
	{
	    cout << "You can't sell that much\n";
		return 0; 
	}
	Me->Land -= HowMuch;
	Me->Treasury += (int)(((float)HowMuch * Me->LandPrice));
	return 0;
}











