Santa Paravia

Their is only one file associated with the game.

The main abstractions of the game consist of the following:

The Games Initialization which consist of multiple member functions that make up the creation of the game.
  The first section of code after the prototype definitions, is the creation of the game and the players.
  Along with the InitialiePlayer and AddRevenues
  
  Problem: The first section of code is hard to understand and needs to broken up into its own class or function
           to have better understanding on how it operates.
           
2 - Buying, a major part of the game and will be used by player input.
    Void BuyCatherdral, void BuyGrain, void BuyLand, void buyMill, void BuySoliders.
    These function make up most of the buying portion of the game
    
    Thought: Break this seciton up into its own class and file.
    
3 - Game Interactions
    CheckNewTitles, GenerateHarvest, GenerateIncome, ChangeTitle, NewLandandGrainPrices, PrintGrain, ReleaseGrain, SeizeGrain
    SellGrain, SellLand
    Each of these are part of the main application of the game that the user will do throughout the game. 
   
    Thought: Create a new class and file for these functions to make them easier to understand what they are doing.
    
4 - The Game Function to allow the game to Operate
    PrintInstructions, PlayGame, BuySellGrain, AdjustTax, StatePurchases, ShowStats, ImDead
    Each of these functions run the programs throughout the game ending with ImDead (Ends the Game)
    
    Thougth: Create a new class to the operations of the game
    Problem: BuySellGrain hard to understand and will maybe need to be broken up into two functions.
    
The main objective thus far is to break the one file into multiple files and classes, once this is accomplished, the reimplementation of the C code to modern C++ will occur.
