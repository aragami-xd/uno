#ifndef DECK_H
#define DECK_H

/* 
#include "drawfour.h"
#include "colorcard.h"
#include "drawtwo.h"
#include "reverse.h"
#include "skip.h"
#include "number.h"
*/
#include "card.h"

#include <string>
#include <vector>

class Deck
{
protected: 
	std::vector<Card*> deckList;
	int deckType;		//which type of deck is that. 1 for hand, 2 for draw (undrawn deck), 3 for discarded

public: 
	Deck();
	Deck(std::vector<Card*> deck);

	void pushCard(int transferCardIndex, Deck* transferDeck);		//push card to other deck. call pullcard at the end 
	virtual void pullCard(Card* transferCard);		//on hand class, it''ll call some extra functions -> use virtual 

	void setDeck(std::vector<Card*> deck);
	std::vector<Card*> getDeck();

	int getDeckType();

	~Deck();
};

#endif