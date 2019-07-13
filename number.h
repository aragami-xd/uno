#ifndef NUMBER_H
#define NUMBER_H

#include "card.h"

class Number : public Card
{
public: 
	Number();
	Number(int cColor, int cNumber);

	virtual void setName();
	virtual void effect();

	~Number();
};

#endif