#ifndef DECK_H
#define DECK_H

#include "card.h"

#include <string>
#include <vector>

class Deck
{
protected: 
	std::vector<Card*> deckList;

public: 
	Deck();
	Deck(std::vector<Card*> deck);

	void pushCard(int transferCardIndex, Deck* transferDeck);		//push card to other deck. call pullcard at the end 
	virtual void pullCard(Card* transferCard);		//on hand class, it''ll call some extra functions -> use virtual 

	void setDeck(std::vector<Card*> deck);
	std::vector<Card*> getDeck();

	~Deck();
};

#endif