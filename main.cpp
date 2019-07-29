#include <iostream>
#include <string>
#include <vector>
#include <ctime>

//card library 
#include "drawfour.h"
#include "colorcard.h"
#include "drawtwo.h"
#include "reverse.h"
#include "skip.h"
#include "number.h"
#include "zero.h"
#include "seven.h"

//deck library 
#include "hand.h"
#include "draw.h"
#include "discard.h"

//core and player
#include "core.h"
#include "player.h"

//test
#include "test.h"

//UI
#include "interface.h"

using namespace std;

//extern function
extern vector<string> startMenu();


//main program
int main()
{
	::clearConsole();

	//game modes
	bool stacking = true;		
	bool ohSeven = false;			//0-7 rule, pronouce oh-seven
	bool noBluffing = false;		
	bool jumpIn = false;

	vector<string> gameMode = startMenu();
	for (int i=0; i<gameMode.size(); i++) {
		if (gameMode[i] == "1") {
			stacking = false;
			cout << "Stacking mode disabled" << endl;
		} else if (gameMode[i] == "2") {
			ohSeven = true;
			cout << "0-7 rule enabled" << endl;
		} else if (gameMode[i] == "4") {
			noBluffing = true;
			cout << "No bluffing mode enabled" << endl;
		} else {
			cout << "Game mode " << gameMode[i] << " unknown" << endl;
		}
	}
	cout << "Game modes are set" << endl;
	::animationDelay(1000);
	::clearConsole();

		


	//create the deck (create card vector and assign cards into it) 
	vector<Card*> cardList(108);
	int cardQty = 4;		//how many of each card will have 

	for (int i=0; i<cardQty; i++) {
		//4 cards
		cardList[i] = new Drawfour(5);		//draw four card
		cardList[i + cardQty] = new Colorcard(5);		//color change wildcard 

		for (int m=0; m<2; m++) {			//8 cards
			cardList[i + cardQty*(3+m)] = new Drawtwo(i+1);	        //color starts from 1, not 0
			cardList[i + cardQty*(5+m)] = new Reverse(i+1);		//reverse card 
			cardList[i + cardQty*(7+m)] = new Skip(i+1);			//skip card
		}

		if (ohSeven == false) {									//oh seven rule = false -> everything is number
			cardList[i + cardQty*2] = new Number(i+1, 0);				
			for (int m=0; m<9; m++) {
				cardList[i+cardQty*(9+m*2)] = new Number(i+1, m+1);
				cardList[i+cardQty*(10+m*2)] = new Number(i+1, m+1);
			}
		} else if (ohSeven == true) {
			cardList[i + cardQty*2] = new Zero(i+1);	
			for (int m=0; m<9; m++) {
				if (m != 6) {				//since m+1 -> m=6 will get card 7
					cardList[i+cardQty*(9+m*2)] = new Number(i+1, m+1);			//everything else except 0 and 7 are numbers. those 2 are actions
					cardList[i+cardQty*(10+m*2)] = new Number(i+1, m+1);
				} else if (m == 6) {
					cardList[i+cardQty*(9+m*2)] = new Seven(i+1);
					cardList[i+cardQty*(10+m*2)] = new Seven(i+1);
				}
			}
		}
	}
	/*
	0-3: drawfour; 4-7: wildcard
	8-11: zero
	12-19 drawtwo
	20-27: reverse
	28-35: skip
	the rest: number
	84-91: seven
	*/
	




	//hand and players 
	int noOfPlayer = 4;
	vector<Hand*> hand(noOfPlayer);
	vector<Player*> players(noOfPlayer);
	for (int i=0; i<noOfPlayer; i++) {
		hand[i] = new Hand();
		players[i] = new Player(hand[i]);
	}
	players[0]->setBotPlayer();

	//players[0]->setName("vanoss");
	//players[1]->setName("terroriser");
	//players[2]->setName("basically");
	//players[3]->setName("moo");
	
	cout << "Enter players' name here. the first player by default will player, and the other 3 will be bots" << endl;
	string pName;					//set the player name, i'll only use it in the official release
	for (int i=0; i<noOfPlayer; i++) {
		cout << "Player " << i << " name: ";
		cin >> pName;
		players[i]->setName(pName);
	}


	//draw and discard
	Draw *draw = new Draw(cardList);
	draw->shuffle();

	Discard *discard = new Discard(draw->getDeck());
	discard->setLastCard();

	draw->shuffle();		//shuffle again due to discard setLastCard function



	//core 
	Core *core = new Core();
	core->setPlayers(players);
	core->setDraw(draw);
	core->setDiscard(discard);
	if (stacking == false) {
		core->setStackingMode();
	}
	if (noBluffing == true) {
		core->setNoBluffingMode();
	}

	for (int i=0; i<noOfPlayer; i++) {
		players[i]->setCore(core);
	}

	//these parts are completely unecessary, but it makes up for the asthetic of the game
	::clearConsole();										
	cout << "Loading..." << endl;
	cout << endl;
	cout << endl;
	cout << "No the game is not actually loading, i just want to waste your time xD" << endl;
	cout << "Though i've wasted mine more than you, waiting for this animation to get over, which lasts 2 seconds (i set it to 2 seconds in the code)" << endl;
	cout << "But since you're here, checkout Vanossgaming and Pewdiepie" << endl;
	cout << "Then go back and thank me later" << endl;
	cout << "WHAT?" << endl;
	//you've never played Tuber Simulator?
	//pssssst!
	//you know it's fun, right?
	//i'm not supposed to give my opinion
	//but give it a try
	//then you can tell me if it's good or not
	//not convinced yet?
	//okay, i'll cut you a deal
	//this game is available for free
	//and that's a great price!
	//(dadada dada da dadada) - tuber simulator outro play. imaigne it
	::animationDelay(2000);
	::clearConsole();
	cout << "Drawing cards..." << endl;
	core->beginGameDraw();
	

	//test function 
	//Test *test = new Test();
	
	//test->setCard(cardList);
	//test->setDeck(cardList, 0);
	//test->setCore(core);
	//test->printCardList();
	//test->printDeckList();
	//test->testCardName();
	//test->testCardColor();
	//test->testDeckTransfer(draw, hand[0], cardList[26]);
	//test->testReverse(cardList[22]);
	//test->testSkip(cardList[30]);
	//test->testDrawCard(cardList[1]);			
	//test->testSeven(cardList[85]);			
	//test->testZero(cardList[9]);				
	//test->testNoBluffing();


	srand(time(0));			//for random
	::clearConsole();
	core->turnCycle();		//the game itself 
	cout << endl;





	//delete cards
	for (int i=0; i<cardList.size(); i++) {
		delete cardList[i];
	}

	//delete test;
	delete draw, discard;
	for (int i=0; i<noOfPlayer; i++) {
		delete hand[i], players[i];
	}
	delete core;
	return 0;
}