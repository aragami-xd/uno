//this class is used for test the program 
#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <vector>
#include <string>

//card library 
#include "card.h"

//deck library 
#include "deck.h"

#include "core.h"
#include "player.h"

class Test
{
private: 
	std::vector<Card*> card;
	std::vector<Card*> deck[3];			//3 decks: hand(0), draw(1) and discard(2)
	Core* core;

public: 
	Test();

	//setup the test class
	void setCard(std::vector<Card*> CardList);		//get the cards
	void setDeck(std::vector<Card*> deckList, int deckNumber);		//get a deck 
	void setCore(Core* gameCore);
	
	//test the card list
	void testCardName();			//test a card name 
	void testCardColor();			//test a card color 
	void printCardList();		//print everything out

	//test specific decks
	void printDeckList();		//print out that deck 
	void testDeckTransfer(Deck* deckFrom, Deck* deckTo, Card* transferCard);		//push a specific card to other deck and test to see if it's there or not

	//test reverse card
	void testReverse(Card* reverse);

	//test skip card
	void testSkip(Card* skip);

	//test drawTwo or drawFour card
	void testDrawCard(Card* drawFour);

	~Test();
};

#endif