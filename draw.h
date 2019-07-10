#ifndef DRAW_H
#define DRAW_H

#include "deck.h"

class Draw : public Deck 
{
public: 
	Draw();
	Draw(std::vector<Card*> deck);

	void shuffle();

	~Draw();
};

#endif
