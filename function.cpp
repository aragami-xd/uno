#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>

#include "interface.h"

using namespace std;

vector<string> startMenu()
{
	//main menu screen, asking if you want to play a new game or not. Just for fun, doesn't really do anything since you'll have to start new game no matter what
	cout << "\e[94mWelcome to Uno on Console!\e[0m" << endl;
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
	//::animationDelay(1000);
	//::clearConsole();

	//the real startMenu program, containing gameplay options
	//game mode and descriptions
	cout << "Choose game rules: " << endl;
	cout << endl;

	cout << "\e[91m1. No Stacking\e[0m" << endl;
	cout << "Now you won't get 'no U-ed' by stacking 4 draw 4s anymore" << endl;	    //you can stack draw +4 or +2 cards 
	cout << endl;

	cout << "\e[92m2. The 7-0 Rule\e[0m" << endl;
	cout << "7 to swap hand with someone else, 0 to force everyone swap directionwise" << endl;
	cout << endl;

	cout << "\e[93m3. Jump-in\e[0m" << endl;
	cout << "You can jump in whenever you want if you got the exact same card as on the discarded deck (not yet available)" << endl;
	cout << endl;

	cout << "\e[94m4. No bluffing\e[0m" << endl;
	cout << "If you can play a non-wildcard card, you cannot play wildcards anymore" << endl;
	cout << endl;

	cout << "Choose all the game mode you want to play, then enter them here, separated by a whitespace. Leave empty for no mod" << endl;

	//choose a type 
	string gameModeString;
	cout << flush;
	cin.ignore();
	getline(cin, gameModeString);			//input the whole line of text as a string
	istringstream iss(gameModeString);					//convert a 'phrase' into separate 'words'
	vector<string> gameMode(istream_iterator<string>{iss}, istream_iterator<string>());		
	return gameMode;
}