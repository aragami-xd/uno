#include "hand.h"
#include <iostream>
using namespace std;

//implement the default hand constructor
Hand::Hand()
{
	deckType = 1;
}

//may not be important, since vector deck will not be pre-assignned. A series of for loop will assign it later on
//when the match starts (each player gets 7 cards, which run a 7 iterations for loop) 
//implement the hand (deck) constructor
Hand::Hand(vector<Card*> deck) : Deck(deck)
{
	deckType = 1;	//1 for hand, 2 for draw, 3 for discarded
}


//implement the hand sortHand function
void Hand::sortHand()
{
	//sort the deck by number first, then sort by color after that
	for (int i=0; i<deckList.size(); i++) {		//selection sort
		int min = i;
		for (int m=i+1; m<deckList.size(); m++) {
			if (deckList[m]->getNumber() < deckList[min]->getNumber()) {
				min = m;
			}
		}
		if (min != i) {
			swap(deckList[i], deckList[min]);
		}
	}

	
	//sort by color
	vector<Card*> tempColorSort;			
	for (int i=1; i<=5; i++) {				//loop through color
		for (int m=0; m<deckList.size(); m++) {			//insert at the front based on their value 
			if (deckList[m]->getColor() == i) {
				tempColorSort.push_back(deckList[m]);
			}
		}
	}
	deckList = tempColorSort;
}

//implement the hand pullCard function
void Hand::pullCard(Card * transferCard) 
{
	Deck::pullCard(transferCard);

}

//implement the hand destructor
Hand::~Hand()
{
}



