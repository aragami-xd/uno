//stl 
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

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

//core and player library
#include "core.h"
#include "player.h"

//test
#include "test.h"

using namespace std;

//extern function
extern int startMenu();


//main program
int main()
{
	//int menuOption = startMenu();
	//this_thread::sleep_for(chrono::seconds(1));


	//create the deck (create card vector and assign cards into it) 
	vector<Card*> cardList;
	int cardQty = 4;		//how many of each card will have 

	Card *drawFour = new Drawfour[cardQty];		//4 of each wildcard
	Card *colorCard = new Colorcard[cardQty];	
	Card *drawTwo = new Drawtwo[cardQty * 2];		//8 of each action card 
	Card *reverse = new Reverse[cardQty * 2];
	Card *skip = new Skip[cardQty * 2]; 
	Card *number = new Number[cardQty *19];		//0 x 4, 1->9 x 8 == 19 * qty

	for (int i=0; i<cardQty; i++) {
		//4 cards
		drawFour[i].setColor(5);		//draw four card
		drawFour[i].setName();

		colorCard[i].setColor(5);		//color change wildcard 
		colorCard[i].setName();

		number[i*19].setColor(i+1);			//number 0 card, separeted 18 iterations from each other 
		number[i*19].setNumber(0);
		number[i*19].setName();
		
		for (int m=0; m<2; m++) {			//8 cards
			drawTwo[i + m*cardQty].setColor(i+1);	//color starts from 1, not 0
			drawTwo[i + m*cardQty].setName();

			reverse[i + m*cardQty].setColor(i+1);		//reverse card 
			reverse[i + m*cardQty].setName();
			
			skip[i + m*cardQty].setColor(i+1);			//skip card
			skip[i + m*cardQty].setName();

			for (int n=1; n<=9; n++) {			//number 1->9 cards = 72 in total 
				number[i*19 + n + m*9].setColor(i+1);		//thank god this shit is complicated AF: i loops between 19 iterations (0,1,2...1,2...9,0,1...)				
				number[i*19 + n + m*9].setNumber(n);		//m loops through 9 iterations (0,1.....1....0,1.....) and n loop in between m
				number[i*19 + n + m*9].setName();
			}															
		}
	}	
	/* Loop analysis
	loop: red -> green -> blue ->yellow
	loop content: drawfour, colorcard, 0, drawtwo, reverse, skip, 1, 2....9, drawtwo, reverese, skip, drawfour, 1, 2...
	-> loop e.g. run this line: test->printCardList();

	


	/*
	//dummy card deck 
	Card *drawFour = new Drawfour(5);
	Card *skip = new Skip(2);
	Card *number = new Number(3,6);
	cardList.push_back(drawFour);
	cardList.push_back(skip);
	cardList.push_back(number);
	*/

	/* 
	cardList.push_back(drawFour);
	cardList.push_back(colorCard);
	cardList.push_back(number);
	cardList.push_back(drawTwo);
	cardList.push_back(reverse);
	cardList.push_back(skip);
	cardList.push_back(number);
	*/


	//hand, temp only. full game may use array of hands, array length 4 = 4 hands = 4 players 
	//Hand *hand = new Hand(cardList);
	//hand->sortHand();

	//Draw *draw = new Draw(cardList);
	//draw->shuffle();

	//draw->pushCard(2, hand);

	//Discard *discard = new Discard(cardList);
	//discard->setLastCard();
	//cout << discard->getLastCardName() << endl;
	
	//cout << cardList[2]->getName() << endl;

	//test function 
	Test *test = new Test();
	
	test->setCard(cardList);
	test->setDeck(cardList, 0);
	test->printCardList();
	test->printDeckList();
	//test->testCardName();
	//test->testCardColor();
	//test->testDeckTransfer(draw, hand, cardList[26]);





	//delete cards
	delete[] drawFour, colorCard, drawTwo, skip, reverse, number;
	
	delete test;
	//delete hand, draw, discard;

	return 0;
}