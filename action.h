#ifndef ACTION_H
#define ACTION_H

#include "card.h"

class Action : public Card 
{
protected: 
	virtual void setName() =0;
	
public: 
	Action();
	Action(int cColor);
	
	virtual void effect(Core* core) =0;

	~Action();
};

#endif