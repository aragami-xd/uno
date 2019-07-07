#ifndef CARD_H
#define CARD_H

#include <string>

class Card
{
protected:
	int color;		//card color. 1 = red, 2 = green, 3 = blue, 4 = yellow, 5 = wildcard, which will be set later using function
	std::string name;
	int cardType;		//card type. 1 for normal, 2 for action, 3 for wildcard

public:
	Card();
	Card(int cColor);

	virtual void effect() =0;		//card effect, used for action and wildcards
	int getColor();			//only wildcards can setColor

	virtual void setName() =0;		//basically combine effect & color, but each card type does it differently 
	std::string getName();

	~Card();
};

#endif