#ifndef ACTION_H
#define ACTION_H

#include "card.h"

class Action : public Card 
{
public: 
	Action();
	Action(int cColor);

	virtual void setName() =0;
	virtual void effect(Core* core) =0;

	~Action();
};

#endif