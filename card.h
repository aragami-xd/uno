#ifndef CARD_H
#define CARD_H

#include <string>

class Card
{
protected:
	int color;		//card color. 1 = red, 2 = green, 3 = blue, 4 = yellow, 5 = wildcard, which will be set later using function
	std::string name;
	int cardType;		//card type. 1 for normal, 2 for action, 3 for wildcard
	int cardNumber;		//0-9, 10=reverse, 11=skip, 12=drawtwo, 13=colorchange, 14=drawfour

public:
	Card();
	Card(int cColor);
	
	virtual void effect() =0;		//card effect, used for action and wildcards

	void setColor(int cColor);
	int getColor();			//only wildcards can setColor

	virtual void setName() =0;
	std::string getName();

	void setNumber(int cNumber);
	int getNumber();

	~Card();
};

#endif