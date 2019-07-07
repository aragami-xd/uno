#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int startMenu()
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
		cout << "Then why are you here? New game god damm... Ahem, sorry, Christian channel. New game!" << endl;
	} else if (newGame != "n" || newGame != "y") {
		cout << "Errr, waht? Yes? Okay, new game it is" << endl;
	}
	cout << endl;

	//the real startMenu program, containing gameplay options
	//game mode and descriptions
	cout << "1. Classic Uno" << endl;
	cout << "If you don't know how to play, then pleaase reconsider your life and search Google" << endl;
	cout << endl;

	cout << "3. The 7-0 Rule" << endl;
	cout << "7 to swap hand with someone else, 0 to force everyone swap clockwise" << endl;
	cout << endl;

	cout << "4. Jump-in" << endl;
	cout << "You can jump in whenever you want if you got the exact same card as on the discarded deck" << endl;
	cout << endl;

	cout << "2. Stacking" << endl;
	cout << "Ready to get 'no u'ed when you got stacked to draw 16 cards" << endl;	    //you can stack draw +4 or +2 cards 
	cout << endl;

	cout << "5. No bluffing" << endl;
	cout << "If you have a card with the same color as the discarded pile, you cannot play wildcards anymore" << endl;
	cout << endl;

	//choose a type 
	string gameModeString;
	int gameMode;
	while (gameMode < 1 || gameMode > 4) {	
		cout << "Made up your mind yet? ";
		cin >> gameModeString;
		istringstream iss(gameModeString);			//input as string and convert to int in case user mashes the keyboard 
		iss >> gameMode;
		if (gameMode < 1 || gameMode > 4) {
			cout << "Who are you? President of South Africa? Don't know how to count?" << endl;		//reference to pewdiepie's video 'the president of south africa - he can't cout'
		}
	}
	if (gameMode >= 1 && gameMode <= 4) {
		cout << "LETS GO BOIIISSS!" << endl;
	}
	return gameMode;	
}