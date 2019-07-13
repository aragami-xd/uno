#include "draw.h"
#include "algorithm"
using namespace std;

//implement the default draw constructor
Draw::Draw()
{
	deckType = 2;
}

//implement the draw (deck) constructor
Draw::Draw(vector<Card*> deck) : Deck(deck)
{
	deckType = 2;
}

//implement the draw sortDeck function
void Draw::shuffle()
{
	random_shuffle(deckList.begin(), deckList.end()); 
}

//implement the draw destructor
Draw::~Draw()
{
}
