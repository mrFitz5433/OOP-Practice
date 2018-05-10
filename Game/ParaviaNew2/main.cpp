//Main file for calling the fucntion in ParaviaPlay to run the game and
//determine when the game is going to end

#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>

#include "ParaviaHelp.hpp"


using namespace std;

int main()
{
	ParaviaHelp P;
	player MyPlayers[6];
	int NumOfPlayers, i, level;
	char string[255], name[25];
	bool MorF;
	//Initialize the random number generator seed.
	srand(time(NULL));
	// Start the game.
	cout << "Santa Paravia and Fiumaccio\n";
	cout << "\nDo you wish instructions (Y or N)? ";
	fgets(string, 254, stdin);
	if(string[0] == 'y' || string[0] == 'Y')
	    P.PrintInstructions();
	cout << "How many people want to play (1 to 6)? ";
	fgets(string, 254, stdin);
	NumOfPlayers = (int)atoi(string);
	if(NumOfPlayers < 1 || NumOfPlayers > 6)
		{
			cout << "Thanks for playing.\n";
			return 0;
		}
	cout << "What will be the difficulty of this game:\n1. Apprentice\n";
	cout << "2. Journeyman\n3. Master\n4. Grand Master\n\nChoose: ";
	fgets(string, 254, stdin);
	level = (int)atoi(string);
	if(level < 1)
		level = 1;
	if(level > 4)
		level = 4;
	for(i = 0; i < NumOfPlayers; i++)
	{
		cout << "Who is the ruler of " << P.CityList[i] << "? ";
		fgets(name, 24, stdin);
		    /* Strip off the trailing \n. */
		    name[strlen(name) - 1] = '\0';
		cout << "Is " << name << " a man or a woman (M or F)? ";
		fgets(string, 3, stdin);
		if(string[0] == 'm' || string[0] == 'M')
			MorF = true;
		else
			MorF = false;
		P.InitializePlayer(&MyPlayers[i], 1400, i, level, name, MorF);
	}
	//Enter the main game loop.
	P.PlayGame(MyPlayers, NumOfPlayers);
	return 0;
}