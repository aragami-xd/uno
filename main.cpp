#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <ctime>

//card library 
#include "drawfour.h"
#include "colorcard.h"
#include "drawtwo.h"
#include "reverse.h"
#include "skip.h"
#include "number.h"

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
extern int startMenu();


//main program
int main()
{

	//int menuOption = startMenu();

	//create the deck (create card vector and assign cards into it) 
	vector<Card*> cardList;
	int cardQty = 4;		//how many of each card will have 

	
	Card *drawFour[cardQty];		//4 of each wildcard
	Card *colorCard[cardQty];	
	Card *drawTwo[cardQty * 2];		//8 of each action card 
	Card *reverse[cardQty * 2];
	Card *skip[cardQty * 2]; 
	Card *number[cardQty *19];		//0 x 4, 1->9 x 8 == 19 * qty

	for (int i=0; i<cardQty; i++) {
		//4 cards
		drawFour[i] = new Drawfour(5);		//draw four card
		cardList.push_back(drawFour[i]);

		colorCard[i] = new Colorcard(5);		//color change wildcard 
		cardList.push_back(colorCard[i]);

		number[i*19] = new Number(i+1, 0);			//number 0 card, separeted 18 iterations from each other 
		cardList.push_back(number[i*19]);

		for (int m=0; m<2; m++) {			//8 cards
			drawTwo[i + m*cardQty] = new Drawtwo(i+1);	//color starts from 1, not 0
			cardList.push_back(drawTwo[i + m*cardQty]);

			reverse[i + m*cardQty] = new Reverse(i+1);		//reverse card 
			cardList.push_back(reverse[i + m*cardQty]);

			skip[i + m*cardQty] = new Skip(i+1);			//skip card
			cardList.push_back(skip[i + m*cardQty]);

			for (int n=1; n<=9; n++) {			//number 1->9 cards = 72 in total 
				number[i*19 + n + m*9] = new Number(i+1, n);		//thank god this shit is complicated AF: i loops between 19 iterations (0,1,2...1,2...9,0,1...)
				cardList.push_back(number[i*19 + n + m*9]);			//m loops through 9 iterations (0,1.....1....0,1.....) and n loop in between m
			}
		}
	}	
	/* Loop analysis
	loop: red -> green -> blue ->yellow
	loop content: drawfour, colorcard, 0, drawtwo, reverse, skip, 1, 2....9, drawtwo, reverese, skip, drawfour, 1, 2...
	-> loop e.g. run this line: test->printCardList();
	*/ 
	


	//hand and players 
	int noOfPlayer = 4;
	vector<Hand*> hand(noOfPlayer);
	vector<Player*> players(noOfPlayer);
	for (int i=0; i<noOfPlayer; i++) {
		hand[i] = new Hand();
		players[i] = new Player(hand[i]);
	}


	Draw *draw = new Draw(cardList);
	draw->shuffle();
	//draw->pushCard(2, hand);

	Discard *discard = new Discard(cardList);
	discard->setLastCard();


	Core *core = new Core();
	core->setPlayers(players);
	core->setDraw(draw);
	core->setDiscard(discard);

	for (int i=0; i<noOfPlayer; i++) {
		players[i]->setCore(core);
	}
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
	//test->testDeckTransfer(draw, hand, cardList[26]);
	//test->testReverse(reverse[0]);
	//test->testSkip(skip[0]);
	//test->testDrawCard(drawFour[0]);
	
	/*
	core->setPlayerXTurn(0);
	skip[0]->effect(core);
	drawFour[0]->effect(core);
	*/
	
	srand(time(0));			//for random
	cout << endl;
	core->turnCycle();
	//core->turnTimer();
	cout << endl;







	//delete drawFour, colorCard, drawTwo;
	for (int i=0; i<cardQty; i++) {
		delete drawFour[i], colorCard[i];
	}
	for (int i=0; i<cardQty * 2; i++) {
		delete drawTwo[i], reverse[i], skip[i];
	}
	for (int i=0; i<76; i++) {
		delete number[i];
	}

	//delete test;
	delete draw, discard;
	for (int i=0; i<noOfPlayer; i++) {
		delete hand[i], players[i];
	}
	delete core;
	return 0;
}