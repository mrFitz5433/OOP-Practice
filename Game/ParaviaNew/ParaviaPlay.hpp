//ParaviaPlay header file will delcare the functions for playing the game

#pragma once

#include"ParaviaHelp.hpp"

#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<curses.h>

struct ParaviaPlay : ParaviaHelp
{
	//function to show how much you have and if you are broke
	void AddRevenue(player *Me);
	//function for attacking other players
	int AttackNeighor(player *Me, player *Him);
	//function to print how much grain you have
	void PrintGrain(player *Me);
	//function to print the instructions of the game
	void PrintInstructions();
	//function to loop for the entire game play
	void PlayGame(player MyPlayers[6], int NumOfPlayers);
	//function for each turn
	void NewTurn(player *Me, int HowMany, player Myplayers[6], player *Baron);
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
}