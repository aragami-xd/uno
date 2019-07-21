#ifndef WILDCARD_H
#define WILDCARD_H

#include "card.h"

class Wildcard : public Card
{
public: 
	Wildcard();
	Wildcard(int cColor);		//cardType is set to wildcard here
	//turns out you don't need to say that it'll copy the parent constructor here, do it later in the cpp file

	virtual void setName() =0;

	void setColor(Core* core);		//set the color after the player has played the card
	void playerSetColor();
	void botSetColor(Core* core, int playerXTurn);

	virtual void effect(Core* core);	//card effect, only +4 has it, typical wildcard (known as Colorcard here) doesn't have it, leave it blank

	~Wildcard();
};

#endif