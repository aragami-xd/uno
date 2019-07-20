#include "discard.h"
using namespace std;

//implement the default discard constructor
Discard::Discard() : Deck()
{
}

//may not be important either, since discard starts empty
//implement the discard (deck) constructor
Discard::Discard(vector<Card*> deck)
{
	for (int i=0; i<deck.size(); i++) {
		if (deck[i]->getNumber() < 10) {		//artificially push the first number card to the back so that the first card of the game will be number card
			deckList.push_back(deck[i]);
			break;
		}
	}
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

//implement the discard pullCard function
void Discard::pullCard(Card* transferCard)
{
	Deck::pullCard(transferCard);
	setLastCard();
}

//implement the discard destructor
Discard::~Discard()
{
}
