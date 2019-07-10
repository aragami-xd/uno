#include "discard.h"
using namespace std;

//implement the default discard constructor
Discard::Discard()
{
	deckType = 3;
}

//may not be important either, since discard starts empty
//implement the discard (deck) constructor
Discard::Discard(vector<Card*> deck) : Deck(deck)
{
	deckType = 3;
}

//implement the discard setLastCard function
void Discard::setLastCard()
{
	lastCard = deckList[deckList.size() - 1];
	lastCardColor = lastCard->getColor();
	lastCardNumber = lastCard->getNumber();
	lastCardName = lastCard->getName();
}

//implement the discard getLastCard function
Card* Discard::getLastCard()
{
	return lastCard;
}

//implement the discard getLastCardColor function
int Discard::getLastCardColor()
{
	return lastCardColor;
}

//implement the discard getLastCardNumber function
int Discard::getLastCardNumber()
{
	return lastCardNumber;
}

//implement the discard getLastCardName function
string Discard::getLastCardName()
{
	return lastCardName;
}

//implement the discard destructor
Discard::~Discard()
{
}
