#include "deck.h"
using namespace std;

//implement the default class constructor
Deck::Deck()
{
}

//implement the deck (deck) constructor
Deck::Deck(vector<Card*> deck)
{
	deckList = deck;
}

//implement the deck pullCard function
void Deck::pullCard(Card* transferCard)
{	
	deckList.push_back(transferCard);
}

//implement the deck pushCard function
void Deck::pushCard(int transferCardIndex, Deck* transferDeck)
{
	transferDeck->pullCard(deckList[transferCardIndex]);
	deckList.erase(deckList.begin() + transferCardIndex);
}

//implement the deck getDeckType function
int Deck::getDeckType()
{
	return deckType;
}

//implement the deck getDeck function
vector<Card*> Deck::getDeck()
{
	return deckList;
}

//implement the deck destructor
Deck::~Deck()
{
}
