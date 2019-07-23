#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void startMenu()
{
	//main menu screen, asking if you want to play a new game or not. Just for fun, doesn't really do anything since you'll have to start new game no matter what
	cout << "Welcome to Uno on Console!";
	cout << "New game?" << endl;
	cout << "Yes - y" << endl;
	cout << "No - n" << endl;
	string newGame;
	cin >> newGame;
	if (newGame == "y") {
		cout << "Okay, new game" << endl;
	} else if (newGame == "n") {
		cout << "Then why are you here? New game" << endl;
	} else if (newGame != "n" || newGame != "y") {
		cout << "Errr, waht? Yes? Okay, new game it is" << endl;
	}
	cout << endl;

	//the real startMenu program, containing gameplay options
	//game mode and descriptions
	cout << "Choose game rules: " << endl;
	cout << endl;

	cout << "1. No Stacking" << endl;
	cout << "Thank god I won't get 'no U-ed' by stacking 4 draw 4s anymore" << endl;	    //you can stack draw +4 or +2 cards 
	cout << endl;

	cout << "2. The 7-0 Rule" << endl;
	cout << "7 to swap hand with someone else, 0 to force everyone swap clockwise (not yet available)" << endl;
	cout << endl;

	cout << "3. Jump-in" << endl;
	cout << "You can jump in whenever you want if you got the exact same card as on the discarded deck (not yet available)" << endl;
	cout << endl;

	cout << "4. No bluffing" << endl;
	cout << "If you have a card with the same color or number as the discarded pile, you cannot play wildcards anymore (not yet available)" << endl;
	cout << endl;

	cout << "Choose all the game mode you want to play, then enter them here, separated by a whitespace. Leave empty for no mod" << endl;

	//choose a type 
	string gameModeString;
	int gameMode;
	//return gameMode;	
}