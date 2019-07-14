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


public: 
	Test();

	//test the card list
	void setCard(std::vector<Card*> CardList);		//get the cards
	void testCardName();			//test a card name 
	void testCardColor();			//test a card color 
	void printCardList();		//print everything out

	//test specific decks
	void setDeck(std::vector<Card*> deckList, int deckNumber);		//get a deck 
	void printDeckList();		//print out that deck 
	void testDeckTransfer(Deck* deckFrom, Deck* deckTo, Card* transferCard);		//push a specific card to other deck and test to see if it's there or not

	//test reverse card
	void testReverse();

	//test skip card
	void testSkip(Core* core);

	~Test();
};

#endif