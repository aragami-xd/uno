#ifndef REVERSE_H
#define REVERSE_H

#include "action.h"

class Reverse : public Action
{
public: 
	Reverse();
	Reverse(int cColor);

	virtual void setName();
	virtual void effect(Core* core);	

	~Reverse();
};

#endif

