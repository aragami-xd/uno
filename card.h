#ifndef CARD_H
#define CARD_H

#include <string>
#include "interface.h"

class Core;			//this single line solves everything (literally) 

class Card
{
protected:
	int color;		//card color. 1 = red, 2 = green, 3 = blue, 4 = yellow, 5 = wildcard, which will be set later using function
	std::string name;
	int cardNumber;		//0-9, 10=reverse, 11=skip, 12=drawtwo, 13=colorchange, 14=drawfour

	virtual void setName() =0;

public:
	Card();
	Card(int cColor);

	int getColor();			//only wildcards can setColor
	std::string getName();	
	int getNumber();
	
	virtual void effect(Core* core) =0;		//card effect, used for action and wildcards
	~Card();
};

#endif