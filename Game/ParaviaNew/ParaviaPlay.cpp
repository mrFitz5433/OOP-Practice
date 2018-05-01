//ParaviaPlay.cpp file is used to define the functions from the header file

#include"ParaviaPlay.hpp"
#include"ParaviaHelp.hpp"

#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<curses.h>

using namespace std;

void ParaviaPlay::AddRevenue(player *Me)
{
	Me->Treasury += (Me->JusticeRevenue + Me->CustomsDutyRevenue);
	Me->Treasury += (Me->IncomeTaxRevenue + Me->SalesTaxRevenue);
	if(Me->Treasury < 0)
		Me->Treasury = (int)((float)Me->Treasury * 1.5);
	if(Me->Treasury < (-10000 * Me->TitleNum))
		Me->IsBankrupt = True;
	return 0;
}

int ParaviaPlay::AttackNeighbor(player *Me, player *Him)
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
	cout << "\n" << Me->Title << " " << Me->Name << " invades and seizes " << Me->City << " hectares of land!\n";
	deadsoldiers = Random(40);
	if(deadsoldiers > (Him->Soldiers - 15))
		deadsoldiers = Him->Soldiers - 15;
	Him->Soldiers -= deadsoldiers;
	cout << Him->Title << " " << Him->Name << " loses " << deadsoldiers << " soliders in battle.\n";
	return LandTaken;
}