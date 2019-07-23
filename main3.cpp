#include <iostream>
#include <string>
#include <vector>

//card library 
#include "drawfour.h"
#include "colorcard.h"
#include "drawtwo.h"
#include "reverse.h"
#include "skip.h"
#include "number.h"

using namespace std;


//main program
int main()
{


	//create the deck (create card vector and assign cards into it) 
	Card* blankCard;
	vector<Card*> cardList;
	for (int i=0; i<108; i++) {
		cardList.push_back(blankCard);
	}
	int cardQty = 4;		//how many of each card will have 

	for (int i=0; i<cardQty; i++) {
		//4 cards
		cardList[i] = new Drawfour(5);		//draw four card

		cardList[i + cardQty] = new Colorcard(5);		//color change wildcard 
		
		cardList[i + cardQty*2] = new Number(i+1, 0);			

		for (int m=0; m<2; m++) {			//8 cards
			cardList[i + cardQty*(3+m)] = new Drawtwo(i+1);	        //color starts from 1, not 0

			cardList[i + cardQty*(5+m)] = new Reverse(i+1);		//reverse card 

			cardList[i + cardQty*(7+m)] = new Skip(i+1);			//skip card

		}
		for (int m=0; m<9; m++) {
			cardList[i+cardQty*(9+m*2)] = new Number(i+1, m+1);
			cardList[i+cardQty*(10+m*2)] = new Number(i+1, m+1);
		}
	}	

	for (int i=0; i<108; i++) {
		cout << cardList[i]->getName() << endl;
	}
	




	//delete drawFour, colorCard, drawTwo;
	for (int i=0; i<cardList.size(); i++) {
        delete cardList[i];
    }

	return 0;
}