#ifndef HAND_H
#define HAND_H

#include "deck.h"

class Hand : public Deck 
{
public: 
	Hand();
	Hand(std::vector<Card*> deck);

	void sortHand();

	~Hand();
};

#endif