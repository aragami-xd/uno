#include "draw.h"
#include "algorithm"
using namespace std;

//implement the default draw constructor
Draw::Draw()
{
}

//implement the draw (deck) constructor
Draw::Draw(vector<Card*> deck)
{
	deckList = deck;
	deckType = 2;
}

//implement the draw shuffle function
void Draw::shuffle()
{
	random_shuffle(deckList.begin(), deckList.end()); 
}

//implement the draw destructor
Draw::~Draw()
{
}
