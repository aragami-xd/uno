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

	//the real startMenu program, containing gameplay options
	//game mode and descriptions
	cout << "1. Classic Uno" << endl;
	cout << "Self-explanatory enough. If you don't know how to play Uno, then I suggest you quit this game, reconsider your life, search google for the instruction, then come back, say nothing and just play the game" << endl;
	cout << endl;

	cout << "2. The 7-0 Rule" << endl;
	cout << "The bullshit rule where 7, is you swapping card with another opponent, and 0 is everyone swapping card with the next person. Imagine you've just pressed 'Uno', and someone take your card. Yeah, I know that feeling... 'Vanoss intensifies'..." << endl;
	cout << endl;

	cout << "3. Jump-in" << endl;
	cout << "Alright, so you don't want to swap card, fine. The person you hate only has one card left. You placed down a blue 3. 'Fortunately for him', he's holding the blue 3. Jump that card in, and win. Enjoy getting shit on by your teammates as you say 'I made a severe and continuous lapse in my judement, and I don't expected to be forgiven...' - Logan Paul 2018" << endl;
	cout << endl;

	cout << "4. Both" << endl;
	cout << "Now you can play the ultimate 'no u' as you play a yellow 7 card and swap it with the opponent... but you're holding only 2 yellow 7s and he jumps in that yellow 7. Yeah... basically what Nogla does every videos" << endl;
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
			cout << "Who are you? President of South Africa?" << endl;		//reference to pewdiepie's video 'the president of south africa - he can't cout'
		}
	}
	if (gameMode >= 1 && gameMode <= 4) {
		cout << "Kay, lets play! Ready to get yo ass kicked" << endl;
	}
	return gameMode;

	
}