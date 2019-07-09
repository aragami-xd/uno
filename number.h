#ifndef NUMBER_H
#define NUMBER_H

#include "card.h"

class Number : public Card
{
private: 
	int cardNumber;
public: 
	Number();
	Number(int cColor, int cNumber);

	virtual void effect();

	~Number();
};

#endif