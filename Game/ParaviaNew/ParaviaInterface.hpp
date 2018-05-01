//ParaviaInterface.hpp file is for teh game interface of the game

#pragma once

#include"ParaviaHelp.hpp"

#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<curses.h>

struct ParaviaInterface : ParaviaHelp
{
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
	//

};


