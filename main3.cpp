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

//core and player
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
    //for (int i=0; i<cardQty * 27; i++) {
       //cardList.push_back();
    //}

	for (int i=0; i<cardQty; i++) {
		//4 cards
		cardList[i] = new Drawfour(5);		//draw four card

		cardList[i + cardQty] = new Colorcard(5);		//color change wildcard 

		cardList[i + cardQty*2] = new Number(i+1, 0);			

		for (int m=0; m<2; m++) {			//8 cards
			cardList[i + cardQty*(3+m)] = new Drawtwo(i+1);	        //color starts from 1, not 0

			cardList[i + cardQty*(5+m)] = new Reverse(i+1);		//reverse card 

			cardList[i + cardQty*(7+m)] = new Skip(i+1);			//skip card

			for (int n=1; n<10; n++) {			//number 1->9 cards = 72 in total 
				cardList[i + cardQty*(9+m+n*2)] = new Number(i+1, n);
			}
		}
	}	

    
    
	


	//hand, temp only. full game may use array of hands, array length 4 = 4 hands = 4 players 
	Hand *hand = new Hand(cardList);
	hand->sortHand();

	Draw *draw = new Draw(cardList);
	draw->shuffle();

	//draw->pushCard(2, hand);

	Discard *discard = new Discard(cardList);
	discard->setLastCard();
	


	//test function 
	Test *test = new Test();
	
	test->setCard(cardList);
	test->setDeck(cardList, 0);
	test->printCardList();
	test->printDeckList();
	//test->testCardName();
	//test->testCardColor();
	//test->testDeckTransfer(draw, hand, cardList[26]);





	//delete drawFour, colorCard, drawTwo;
	for (int i=0; i<cardList.size(); i++) {
        delete cardList[i];
    }

	delete test;
	delete hand, draw, discard;

	return 0;
}