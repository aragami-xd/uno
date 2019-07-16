#include "core.h"
using namespace std;

//implement the default core constructor
Core::Core()
{
	vector<Player*> playerList;
	players = playerList;
	turnDirection = 1;
	endGame = false;
}

//implement the core setPlayer function
void Core::setPlayers(vector<Player*> playerList)
{
	players = playerList;
	turnDirection = 1;
	endGame = false;
}

//implement the core getPlayer function
vector<Player*> Core::getPlayers()
{
	return players;
}

//implement the core setDirection function
void Core::setDirection()
{
	turnDirection = turnDirection * (-1);
}

//implement the core getDirection function
int Core::getDirection()
{
	return turnDirection;
}

//implement the core setPlayerXTurn function
void Core::setPlayerXTurn(int turn)
{
	playerXTurn = turn;
	if (turn < 0) {
		turn = 3;
	}
}

//implement the core getPlayerXTurn function
int Core::getPlayerXTurn()
{
	return playerXTurn;
}

//implement the core setDraw function
void Core::setDraw(Draw *drawDeck)
{
	draw = drawDeck;
}

//implement the coire getDraw function
Draw* Core::getDraw()
{
	return draw;
}

//implement the core setDiscard fucntion
void Core::setDiscard(Discard *discardDeck)
{
	discard = discardDeck;
}

//implement the core getDiscard function 
Discard* Core::getDiscard()
{
	return discard;
}



//implement the core turnCycle function
void Core::turnCycle()
{
	while (endGame == false) {
		if (players[playerXTurn]->getNextTurn() == 1) {
			//call functions
		} else if (players[playerXTurn]->getNextTurn() == -1) {
			players[playerXTurn]->setNextTurn();
		}
		//end of a cycle 
		playerXTurn++;
	}
}

//implement the core beginGameDraw function
void Core::beginGameDraw()
{
	for (int i=0; i<7; i++) {			//each player gets 7 cards at the begin of the game
		for (int m=0; m<players.size(); m++) {
			players[m]->drawCard(1);
			//::animationDelay(400);
		}
	}
}

//implement the core canPlay function
bool Core::canPlay()
{
	int currentColor = discard->getLastCardColor();
	int currentNumber = discard->getLastCardNumber();

	vector<Card*> playerHand =  players[playerXTurn]->getPlayerHand()->getDeck();
	for (int i=0; i<playerHand.size(); i++) {
		if (playerHand[i]->getColor() == currentColor || playerHand[i]->getColor() == 5) {		//5 is wildcard color, can be played any time
			return true;
		} else if (playerHand[i]->getNumber() == currentNumber) {			//no need to check for same wildcard number, it's checked above
			return true;
		}
	}
	return false;			//return false at the end if there is no matching color or number
}

//implement the core forceDraw function
void Core::forceDraw()
{
	if (canPlay() == false) {
		bool compatibleCard = false;
		while (compatibleCard == false) {			//while the card is incompatible, continue to draw 
			players[playerXTurn]->drawCard(1);
			vector<Card*> newCard = players[playerXTurn]->getPlayerHand()->getDeck();	
			Card* lastNewCard = newCard[newCard.size() - 1];

			if (lastNewCard->getColor() == discard->getLastCardColor() || lastNewCard->getColor() == 5 || lastNewCard->getNumber() == discard->getLastCardNumber()) {		
				//i code at 2am and don't want to think anymore. so we only talk wooden pickaxe efficiency i here, no diamond pickaxe efficiency v - unbreaking iv - mending i
				//i.e. there are repetitive code
				cout << "Compatible card. Play or keep?" << endl;		//ask if player wants to keep or play the card
				cout << "1. Play" << endl;
				cout << "2. Keep" << endl;
				string choice;
				cin >> choice;
				if (choice == "1") {
					players[playerXTurn]->playCard(newCard.size() - 1);		//play the last card
				} else if (choice != "2" || choice != "1") {
					cout << "Don't mess around. Card will be kept" << endl;		//if player decides to be a dickhead, show them who is a dickhead by keep the card and have 1 more card in the hand (which is not fun)
				}
			}
		}
	}
}

//implement the core destructor
Core::~Core()
{
}