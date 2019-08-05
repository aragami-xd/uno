#ifndef REVERSE_H
#define REVERSE_H

#include "action.h"

class Reverse : public Action
{
private:
	virtual void setName();
public: 
	Reverse();
	Reverse(int cColor);

	
	virtual void effect(Core* core);	

	~Reverse();
};

#endif

