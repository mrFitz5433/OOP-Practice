//ParaviaBuy header file deals with all the game funcions of purchases

#pragma once

#include"ParaviaHelp"

#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<curses.h>


struct ParaviaBuy : ParaviaHelp
{
	//function to buy cathedral
	void BuyCathedral(player *Me)
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
};