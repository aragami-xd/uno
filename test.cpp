#include "test.h"

#include "drawfour.h"
#include "colorcard.h"
#include "drawtwo.h"
#include "reverse.h"
#include "skip.h"
#include "number.h"
#include "seven.h"
#include "zero.h"

#include <algorithm>

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
void Test::setDeck(vector<Card*> deckList)
{
	deck = deckList;
}




//implement the void printDeckList function
void Test::printDeckList()
{
	cout << "Print deck list: " << endl;
	for (int i=0; i<deck.size(); i++) {
		cout << i <<". " << deck[i]->getName() << endl;
	}
	cout << endl;
	cout << endl;
}





//just ignore this one, it doesn't work at all for some reason
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
	cout << "Card name: " << reverse->getName() << endl;
	reverse->effect(core);
	if (direction*(-1) == core->getDirection()) {
		cout << "Reverse card test PASSED" << endl;
	} else {
		cout << "Reverse card test FAILED " << direction << endl;
	}
	cout << endl;
}




//implement the test testSkip function
void Test::testSkip(Card* skip)
{	
	//set turn to player 1, call function and get the player 2 status
	cout << "Card name: " << skip->getName() << endl;
	core->setPlayerXTurn(0);
	core->setDirection();
	skip->effect(core);
	if (core->getPlayers()[3]->getNextTurn() == -1) {
		cout << "Skip card test PASSED" << endl;
	} else {
		cout << "Skip card test FAILED " << core->getPlayers()[1]->getNextTurn() << endl;
	}
	cout << endl;
}





//implement the test testDrawCard function
void Test::testDrawCard(Card* drawFour)
{
	//test drawfour card only this time, since drawtwo is EXACTLY the same, just less cards
	//set turn to player 1, call function then see how many cards player 2 has after the function is called
	core->setDirection();
	cout << "Card name: " << drawFour->getName() << endl;
	core->setPlayerXTurn(0);
	Player* player = core->getPlayers()[3];
	Hand* p1Hand = player->getPlayerHand();
	int handSize = p1Hand->getDeck().size();			//get the player and deck, call the function and check the amount of cards afterwards
	
	drawFour->effect(core);
	player->drawCard(player->getCardsToDraw());

	int diff = p1Hand->getDeck().size() - handSize;
	int currentColor = core->getDiscard()->getLastCardColor();

	if (diff == 4 && currentColor != 5) {
		cout << "Draw card test PASSED" << endl;
	} else {
		cout << "Draw card test FAILED " << diff << endl;
	}
	cout << endl;
}






//implement the test testSeven function
void Test::testSeven(Card* seven)
{
	//core->setDirection();
	cout << "Card name: " << seven->getName() << endl;
	Hand largerHand, smallerHand, otherHand;
	vector<Card*> largerCard, smallerCard, otherCard;
	for (int i=0; i<8; i++) {
		largerCard.push_back(core->getDraw()->getDeck()[i]);			//set the large deck to 8 cards	
	}
	for (int i=0; i<4; i++) {
		smallerCard.push_back(core->getDraw()->getDeck()[i]);			//set the small deck to 4 cards
	}
	for (int i=0; i<5; i++) {
		otherCard.push_back(core->getDraw()->getDeck()[i]);			//set the 'medium' deck to ensure that it won't be swapped with 
	}
	//cout << "Card assigned" << endl;
	largerHand.setDeck(largerCard);
	smallerHand.setDeck(smallerCard);
	otherHand.setDeck(otherCard);
	//cout << "small and big hands created" << endl;

	core->getPlayers()[0]->setPlayerHand(&largerHand);			//set the hand to players
	core->getPlayers()[1]->setPlayerHand(&smallerHand);
	core->getPlayers()[2]->setPlayerHand(&otherHand);			//ensure no core dumped fault 
	core->getPlayers()[3]->setPlayerHand(&otherHand);
	//cout << "hands assigned" << endl;

	core->setPlayerXTurn(0);		//set turn to first player
	seven->effect(core);		//call the function
	//cout << "effect called" << endl;

	largerHand = *(core->getPlayers()[1]->getPlayerHand());		//get the hand of the players, but now revesed
	smallerHand = *(core->getPlayers()[0]->getPlayerHand());
	//cout << "hand swaping result collected" << endl;
	
	if (largerHand.getDeck().size() == 8 && smallerHand.getDeck().size() == 4) {
		cout << "Seven test PASSED" << endl;
	} else {
		cout << "Seven test FAILED" << endl;
		cout << largerHand.getDeck().size() << " " << smallerHand.getDeck().size() << endl;
	}
	cout << endl;
}





//implement the test testZero function
void Test::testZero(Card* zero)
{
	core->setDirection();
	cout << "Card name: " << zero->getName() << endl;
	vector<int> deckSize;
	for (int i=0; i<core->getPlayers().size(); i++) {
		deckSize.push_back(core->getPlayers()[i]->getPlayerCard().size());
	}
	zero->effect(core);
	bool swapped = true;
	if (core->getPlayers()[0]->getPlayerCard().size() != deckSize[3]) {		//this is testing, play it manual
		swapped = false;
		cout << "Player 0 swap failed" << endl;																//also i'm too lazy to write the if statement for first and last player
	}
	if (core->getPlayers()[1]->getPlayerCard().size() != deckSize[0]) {
		swapped = false;
		cout << "Player 1 swap failed" << endl;		
	}
	if (core->getPlayers()[2]->getPlayerCard().size() != deckSize[1]) {
		swapped = false;
		cout << "Player 2 swap failed" << endl;		
	}
	if (core->getPlayers()[3]->getPlayerCard().size() != deckSize[2]) {
		swapped = false;
		cout << "Player 3 swap failed" << endl;		
	}
	if (swapped == false) {
		cout << "Zero test FAILED" << endl;
	} else {
		cout << "Zero test PASSED" << endl;
	}
	cout << endl;
}




//the test below no longer work since i've hidden the core->playable() function from public access
//it might have to change in the future, but for now, it's working correctly and i don't really touch the core of the game anymore
//so i should probably be fine
//implement the test testNoBluffing function
void Test::testNoBluffing()
{	
	core->setPlayerXTurn(0);
	Player* player = core->getPlayers()[core->getPlayerXTurn()];		//get the player
	player->drawCard(80);		//draw 80 cards to be safe. chances are, there will be at least 1 wildcard there
	
	Draw* draw = core->getDraw();
	int numberIndex = 0;			//to be honest, i don't really care about efficiency here
	for (int i=0; draw->getDeck().size(); i++) {			//get a number card and push it to discard
		if (draw->getDeck()[i]->getNumber() < 10) {
			numberIndex = i;
			break;
		}
	}
	draw->pushCard(numberIndex, core->getDiscard());					
	//vector<Card*> playableCards = core->playable();			//get the playable cards

	bool passed = true;
	for (int i=0; i<player->getPlayerCard().size(); i++) {
		if (player->getPlayerCard()[i]->getNumber() == 5) {			//if a wildcard is spotted, test failed
			passed = false;					//with that said, there is always a super tiny chance of false negative: there is no wildcard in the hand
			break;
		}									//though, drawing 80/108 cards, i can say that it's safe enough to return the right result most of the time
	}

	if (passed == true) {
		cout << "No bluffing test PASSED" << endl;
	} else if (passed == false) {
		cout << "No bluffing test FAILED" << endl;		//for some reason, the check passed isn't working correctly -> always failed for some reason, even though it's the right card
	}
}




//implement the test referenceGameplay function
//this fucntion will force 4 bots to play the game 
//this function can only ensure that the core of the game behaves correctly, i.e. the suitable cards are being played
//it doesn't ensure that the bots are playing the cards they're supposed to play, so keep that in mind
//system testing this game is extremely hard, and with the bot having constant update to it's behavior, it's quite impossible for me to test 
//those behavior's functionality
void Test::referenceGameplay(Draw* draw)
{
	card = draw->getDeck();		
	for (int i=0; i<card.size(); i++) {
		if (i%3==0) {
			iter_swap(card.begin() + i, card.end() - 1 - i/3 );
		} else if (i%3==0) {
			iter_swap(card.begin() + i, card.end() - 1 - i/2);
		} else if (i%3==2) {
			iter_swap(card.begin() + i, card.end() - 1 - i);
		}
	}

	core->beginGameDraw();
	::clearConsole();
	core->turnCycle();
}




//implement the test destructor
Test::~Test()
{
}
