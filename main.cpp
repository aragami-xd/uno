#include <iostream>
#include <string>
#include <vector>

//class library 
#include "card.h"
#include "wildcard.h"
#include "drawfour.h"

using namespace std;

extern int startMenu();

int main()
{
	int menuOption = startMenu();

	vector<Card> *cardList = new vector<Card>;
	


	delete cardList;

	return 0;
}