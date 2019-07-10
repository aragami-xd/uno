#ifndef DISCARD_H
#define DISCARD_H

#include "deck.h"

class Discard : public Deck
{
private: 
	Card* lastCard;
	int lastCardColor;
	int lassCardNumber;

public: 
	Discard();
	Discard(std::vector<Card*> deck);

	void setLastCard();
	Card* getLastCard();


	virtual void pushCard();
	virtual void pullCard();
	
	~Discard();
};

#endif