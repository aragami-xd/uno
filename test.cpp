#include "test.h"

#include "drawfour.h"
#include "colorcard.h"
#include "drawtwo.h"
#include "reverse.h"
#include "skip.h"
#include "number.h"
#include "seven.h"
#include "zero.h"

using namespace std;

//implement the default test constructor
Test::Test()
{
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
	string cardName;	//get the name and index data
	int index;
	cout << "Card name: ";
	getline(cin, cardName);
	cout << "Index: ";
	cin >> index;

	if (cardName == card[index]->getName())	{			
		cout << "Card name test PASSED" << endl;
	} else {
		cout << ">> " << cardName << endl;
		cout << "<< " << card[index]->getName() << endl;
	}
	/* 
	I give up on this one...
	Card name: Index: >> Blue 4
	<< Blue 4
	Wtf?
*/
}

//implement the test testCardColor function
void Test::testCardColor()
{
	int cardColor, index;		//get the color and index data
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
		for (int m=0; m<deck[i].size(); m++) {
			cout << m <<". " << deck[i][m]->getName() << endl;
		}
		cout << endl;
	}
	cout << "3 Decks printed" << endl;
	cout << endl;
}

/* */
//implement the test testDeckTransfer function
void Test::testDeckTransfer(Deck* deckFrom, Deck* deckTo, Card* transferCard)
{
	cout << "Transfer " << transferCard->getName() << endl;
	int deckFromTotal, deckToTotal;		//see how many transferCard each deck has 
	int transferCardIndex;
	vector<Card*> deckFromDeck = deckFrom->getDeck(), deckToDeck = deckTo->getDeck();		//store the decks 

	for (int i=0; i<deckFromDeck.size(); i++) {		//check how many transferCard in deckFrom
		if (transferCard->getName() == deckFromDeck[i]->getName()) {
			deckFromTotal++;
			transferCardIndex = i;
		}
	}
	for (int i=0; i<deckToDeck.size(); i++) {		//check how many transferCard in deckTo
		if (transferCard->getName() == deckToDeck[i]->getName()) {
			deckToTotal++;
		}
	}
	
	deckFrom->pushCard(transferCardIndex, deckTo);

	for (int i=0; i<deckFromDeck.size(); i++) {		//check how many transferCard in deckFrom
		if (transferCard->getName() == deckFromDeck[i]->getName()) {
			deckFromTotal--;
		}
	}
	for (int i=0; i<deckToDeck.size(); i++) {		//check how many transferCard in deckTo
		if (transferCard->getName() == deckToDeck[i]->getName()) {
			deckToTotal--;
		}
	}

	if (deckFromTotal == 1 && deckToTotal == -1) {
		cout << "Test card transfer PASSED" << endl;
	} else {
		cout << "Test card transfer FAILED " << deckFromTotal << " " << deckToTotal << endl;
	}

}

//implement the test setCore function
void Test::setCore(Core* gameCore)
{
	core = gameCore;
}

//implement the test testReverse function
void Test::testReverse(Card* reverse)
{
	int direction = core->getDirection();			//get the direction, call the function and get the direction again
	reverse->effect(core);
	if (direction*(-1) == core->getDirection()) {
		cout << "Reverse card test PASSED" << endl;
	} else {
		cout << "Reverse card test FAILED " << direction << endl;
	}
}

//implement the test testSkip function
void Test::testSkip(Card* skip)
{	
	//set turn to player 1, call function and get the player 2 status
	core->setPlayerXTurn(0);
	skip->effect(core);
	if (core->getPlayers()[1]->getNextTurn() == -1) {
		cout << "Skip card test PASSED" << endl;
	} else {
		cout << "Skip card test FAILED" << core->getPlayers()[1]->getNextTurn() << endl;
	}
}

//implement the test testDrawCard function
void Test::testDrawCard(Card* drawFour)
{
	//test drawfour card only this time, since drawtwo is EXACTLY the same, just less cards
	//set turn to player 1, call function then see how many cards player 2 has after the function is called
	core->setPlayerXTurn(0);
	Player* player = core->getPlayers()[1];
	Deck* p1Hand = player->getPlayerHand();
	int handSize = p1Hand->getDeck().size();
	drawFour->effect(core);
	int diff = p1Hand->getDeck().size() - handSize;

	if (diff == 4) {
		cout << "Draw card test PASSED" << endl;
	} else if (diff != 4) {
		cout << "Draw card test FAILED " << diff << endl;
	}
}

//implement the test testSeven function
void Test::testSeven(Card* seven)
{
	Hand *largerHand, *smallerHand;
	vector<Card*> largerCard, smallerCard;
	for (int i=0; i<8; i++) {
		largerCard.push_back(core->getDraw()->getDeck()[i]);			//set the deck to 8 cards	
	}
	for (int i=0; i< 4; i++) {
		smallerCard.push_back(core->getDraw()->getDeck()[i]);			//set the deck to 4 cards
	}
	largerHand->setDeck(largerCard);
	smallerHand->setDeck(smallerCard);

	core->getPlayers()[0]->setPlayerHand(largerHand);			//set the hand to players
	core->getPlayers()[1]->setPlayerHand(smallerHand);
	core->getPlayers()[2]->setPlayerHand(largerHand);			//ensure no core dumped fault 
	core->getPlayers()[3]->setPlayerHand(largerHand);
	
	core->setPlayerXTurn(0);		//set turn to first player
	seven->effect(core);		//call the function

	largerHand = core->getPlayers()[1]->getPlayerHand();		//get the hand of the players, but now revesed
	smallerHand = core->getPlayers()[0]->getPlayerHand();
	
	if (largerHand->getDeck().size() == 8 && smallerHand->getDeck().size() == 4) {
		cout << "Seven test PASSED" << endl;
	} else {
		cout << "Seven test FAILED" << endl;
		cout << largerHand->getDeck().size() << " " << smallerHand->getDeck().size() << endl;
	}
}

//implement the test testZero function
void Test::testZero(Card* zero)
{
	vector<int> deckSize;
	for (int i=0; i<core->getPlayers().size(); i++) {
		deckSize.push_back(core->getPlayers()[i]->getPlayerHand()->getDeck().size());
	}
	zero->effect(core);
	bool swapped = true;
	if (core->getPlayers()[0]->getPlayerHand()->getDeck().size() != deckSize[3]) {		//this is testing, play it manual
		swapped = false;
		cout << "Player 0 swap failed" << endl;																//also i'm too lazy to write the if statement for first and last player
	}
	if (core->getPlayers()[1]->getPlayerHand()->getDeck().size() != deckSize[0]) {
		swapped = false;
		cout << "Player 1 swap failed" << endl;		
	}
	if (core->getPlayers()[2]->getPlayerHand()->getDeck().size() != deckSize[1]) {
		swapped = false;
		cout << "Player 2 swap failed" << endl;		
	}
	if (core->getPlayers()[3]->getPlayerHand()->getDeck().size() != deckSize[2]) {
		swapped = false;
		cout << "Player 3 swap failed" << endl;		
	}
	if (swapped == false) {
		cout << "Zero test FAILED" << endl;
	} else {
		cout << "Zero test PASSED" << endl;
	}
}

//implement the test destructor
Test::~Test()
{
}
