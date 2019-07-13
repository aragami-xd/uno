#ifndef DRAW_H
#define DRAW_H

#include "deck.h"

class Draw : public Deck 
{
public: 
	Draw();
	Draw(std::vector<Card*> deck);

	virtual void shuffle();
	//draw doesn't have pullCard since it doesn't pull from anywhere at all

	~Draw();
};

#endif
