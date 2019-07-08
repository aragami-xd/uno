#include <iostream>
#include <string>
#include <vector>

//class library 
#include "card.h"
#include "wildcard.h"
#include "drawfour.h"
#include "colorcard.h"
#include "action.h"
#include "drawtwo.h"
#include "reverse.h"
#include "skip.h"

#include "test.h"

using namespace std;

extern int startMenu();

int main()
{
	//int menuOption = startMenu();

	//create the deck
	vector<Card*> cardList;
	int cardQty = 4;		//how many of each card will have 

	Card *drawFour[cardQty];
	Card *colorCard[cardQty];
	Card *drawTwo[cardQty * 2];
	Card *reverse[cardQty * 2];
	Card *skip[cardQty * 2]; 

	for (int i=0; i<cardQty; i++) {
		drawFour[i] = new Drawfour(5);
		cardList.push_back(drawFour[i]);

		colorCard[i] = new Colorcard(5);
		cardList.push_back(colorCard[i]);

		for (int m=0; m<2; m++) {
			drawTwo[i+m*cardQty] = new Drawtwo(i);
			cardList.push_back(drawTwo[i+m*cardQty]);

			reverse[i+m*cardQty] = new Reverse(i);
			cardList.push_back(reverse[i+m*cardQty]);

			skip[i+m*cardQty] = new Skip(i);
			cardList.push_back(skip[i+m*cardQty]);
		}
	}	
	/* Loop analysis
	loop: red -> green -> blue ->yellow
	loop content: drawfour, colorcard, drawtwo, drawtwo, reverse, reverse, skip, skip
	-> loop e.g. draw4.5, color.5, draw2.1, draw2.1, reverse.1,...
	*/


	//test function 
	Test *test = new Test(cardList);
	test->testCardName("Draw 4 Wildcard", 0);
	test->testCardName("Blue Reverse", 24);
	test->testCardColor(2, 11);


	//delete drawFour, colorCard, drawTwo;
	for (int i=0; i<cardQty; i++) {
		delete drawFour[i], colorCard[i];
	}
	for (int i=0; i<cardQty * 2; i++) {
		delete drawTwo[i], reverse[i], skip[i];
	}
	delete test;

	return 0;
}