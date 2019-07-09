#include "test.h"

using namespace std;

//implement the default test constructor
Test::Test()
{
	/*
	//if no deck is passed into the class, a default one will be created
	Card *drawFour = new Drawfour(5);
	Card *colorCard = new Colorcard(5);
	Card *drawTwo = new Drawtwo(1);

	card.push_back(drawFour);
	card.push_back(colorCard);
	card.push_back(drawTwo);
	*/
}

//implement the test (cardList) constructor
Test::Test(vector<Card*> cardList) 
{
	card = cardList;
}

//implement the test testCardName function
void Test::testCardName(string cardName, int index)
{
	if (cardName == card[index]->getName())	{
		cout << "Card name test PASSED" << endl;
	} else {
		cout << ">> " << cardName << endl;
		cout << "<< " << card[index]->getName() << endl;
	}
}

//implement the test testCardColor function
void Test::testCardColor(int cardColor, int index)
{
	if (cardColor == card[index]->getColor())  {
		cout << "Card color test PASSED" << endl;
	} else {
		cout << ">> " << cardColor << endl;
		cout << "<< " << card[index]->getColor() << endl;
	}
}

//implement the test printCardList function
void Test::printCardList()
{
	for (int i=0; i<card.size(); i++) {
		cout << i << ". " << card[i]->getName() << endl;
	}
}

//implement the test destructor
Test::~Test()
{
}
