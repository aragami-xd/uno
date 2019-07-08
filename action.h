#ifndef ACTION_H
#define ACTION_H

#include "card.h"

class Action : public Card 
{
public: 
	Action();
	Action(int cColor);

	~Action();
};

#endif