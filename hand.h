#ifndef HAND_H
#define HAND_H

#include "deck.h"
//#include "discard.h"

class Hand : public Deck 
{
public: 
	Hand();
	Hand(std::vector<Card*> deck);

	void sortHand();
	virtual void pullCard(Card* transferCard);

	~Hand();
};

#endif