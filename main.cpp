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

using namespace std;

extern int startMenu();

int main()
{
	int menuOption = startMenu();

	vector<Card*> cardList;
	Card *drawFour = new Drawfour(5);
	Card *colorCard = new Colorcard(5);
	Card *drawTwo = new Drawtwo(1); 
	
	cardList.push_back(drawFour);
	cardList.push_back(colorCard);
	cardList.push_back(drawTwo);

	cout << cardList[2]->getName() << endl;

	delete drawFour, colorCard, drawTwo;

	return 0;
}