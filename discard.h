#ifndef DISCARD_H
#define DISCARD_H

#include "deck.h"

class Discard : public Deck
{
private: 
	Card* lastCard;
	int lastCardColor;			//color and number are mostly for convenient sake, doesn't really do much 
	int lastCardNumber;			//these variables will be used quite a lot, so it's better off using variables than call functions
	std::string lastCardName;			//multiple times 

	

public: 
	Discard();
	Discard(std::vector<Card*> deck);

	
	Card* getLastCard();
	int getLastCardNumber();
	int getLastCardColor();
	std::string getLastCardName();

	void setLastCard();
	
	//no pushCard here, since you cannot push card from the discarded deck 
	virtual void pullCard(Card* transferCard);

	~Discard();
};

#endif