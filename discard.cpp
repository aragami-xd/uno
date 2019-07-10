#include "discard.h"
using namespace std;

//implement the default discard constructor
Discard::Discard()
{
}

//may not be important either, since discard starts empty
//implement the discard (deck) constructor
Discard::Discard(vector<Card*> deck) : Deck(deck)
{
}

//implement the discard setLastCard function
void Discard::setLastCard()
{
	lastCard = deckList.end();
}

//implement the discard getLastCard function
Card* Discard::getLastCard()
{
	return lastCard;
}

//implement the discard destructor
Discard::~Discard()
{
}
