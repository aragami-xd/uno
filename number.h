#ifndef NUMBER_H
#define NUMBER_H

#include "card.h"

class Number : public Card
{
private:
	virtual void setName();
public: 
	Number();
	Number(int cColor, int cNumber);

	
	virtual void effect(Core* core);

	~Number();
};

#endif