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


//test the cards 
//implement the test getCard function
void Test::setCard(vector<Card*> cardList) 
{
	card = cardList;
}

//implement the test testCardName function
void Test::testCardName()
{
	string cardName;
	int index;
	cout << "Card name: ";
	cin.ignore();
	getline(cin, cardName);
	cout << "Index: ";
	cin >> index;

	if (cardName == card[index]->getName())	{
		cout << "Card name test PASSED" << endl;
	} else {
		cout << ">> " << cardName << endl;
		cout << "<< " << card[index]->getName() << endl;
	}
}

//implement the test testCardColor function
void Test::testCardColor()
{
	int cardColor, index;
	cout << "Card color: ";
	cin >> cardColor;
	cout << "Index: ";
	cin >> index;

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
	cout << "Print card list: " << endl;
	for (int i=0; i<card.size(); i++) {
		cout << i << ". " << card[i]->getName() << endl;
	}
	cout << endl;
}



//test the decks
//implement the void getDeck function
void Test::setDeck(vector<Card*> deckList, int deckNumber)
{
	deck[deckNumber] = deckList;
}

//implement the void printDeckList function
void Test::printDeckList()
{
	cout << "Print deck list: " << endl;
	for (int i=0; i<3; i++) {
		cout << "Deck number " << i << endl;
		for (int m=0; m<deck[i].size(); i++) {
			cout << ". " << deck[i][m]->getName() << endl;
		}
		cout << endl;
	}
	cout << "3 Decks printed" << endl;
	cout << endl;
}

//implement the test destructor
Test::~Test()
{
}
