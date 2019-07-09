#ifndef CARD_H
#define CARD_H

#include <string>

class Card
{
protected:
	int color;		//card color. 1 = red, 2 = green, 3 = blue, 4 = yellow, 5 = wildcard, which will be set later using function
	std::string name;
	int cardType;		//card type. 1 for normal, 2 for action, 3 for wildcard
	int cardNumber;		//0-9, 11=reverse, 12=skip, 13=drawtwo, 14=colorchange, 15=drawfour

public:
	Card();
	Card(int cColor);

	virtual void effect() =0;		//card effect, used for action and wildcards
	int getColor();			//only wildcards can setColor
	std::string getName();
	int getNumber();

	~Card();
};

#endif