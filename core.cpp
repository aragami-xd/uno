#include "core.h"
#include <sstream>
#include <thread>
using namespace std;

//implement the default core constructor
Core::Core()
{
	turnDirection = 1;
	endGame = false;
	stackingMode = true;
}

//implement the core setPlayer function
void Core::setPlayers(vector<Player*> playerList)
{
	players = playerList;
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

/*
//implement the core getPlayersCard function
vector<Card*> Core::getPlayersCard()
{
	return players[playerXTurn]->getPlayerHand()->getDeck();
}
*/

//implement the core getHandSize function
int Core::getHandSize(int playerNo)
{
	return players[playerNo]->getPlayerHand()->getDeck().size();
}

//implement the core setStackingMode function
void Core::setStackingMode()
{
	stackingMode = false;
}

//implement the core setNoBluffingMode function
void Core::setNoBluffingMode()
{
	noBluffingMode = true;
}


//implement the core setOhSeven function
void Core::setOhSeven()
{
	ohSevenMode = true;
}

//implement the core getOhSeven function
bool Core::getOhSeven()
{
	return ohSevenMode;
}


//i really want to call these 3 together in a function, but you have to check it individually

//implement the core getNextPlayerTurn function
int Core::getNextPlayerTurn()
{
	int nextTurn = playerXTurn + turnDirection;
	if (turnDirection == 1) {
		if (nextTurn >= players.size()) {			//reset turn to 0
			nextTurn = 0;
		} else if (nextTurn < 0) {
			nextTurn = players.size()-1;				//reset turn to the last player
		}
	} else if (turnDirection == -1) {
		if (nextTurn >= players.size()) {			
			nextTurn = players.size()-1;
		} else if (nextTurn < 0) {
			nextTurn = 0;				
		}
	}
	return nextTurn;
}

//implement the core getLastPlayerTurn function
int Core::getLastPlayerTurn()
{
	int lastPlayer = playerXTurn - turnDirection;
	if (turnDirection == 1) {
		if (lastPlayer >= players.size()) {			//reset turn to 0
			lastPlayer = 0;
		} else if (lastPlayer < 0) {
			lastPlayer = players.size()-1;				//reset turn to the last player
		}
	} else if (turnDirection == -1) {
		if (lastPlayer >= players.size()) {			
			lastPlayer = players.size()-1;
		} else if (lastPlayer < 0) {
			lastPlayer = 0;				
		}
	}
	return lastPlayer;
}

//implement the core getOppositePlayerTurn function
int Core::getOppositePlayerTurn()
{
	int oppositePlayer = playerXTurn - turnDirection * 2;
	if (turnDirection == 1) {
		if (oppositePlayer >= players.size()) {			//reset turn to 0
			oppositePlayer = 0;
		} else if (oppositePlayer < 0) {
			oppositePlayer = players.size()-1;				//reset turn to the last player
		}
	} else if (turnDirection == -1) {
		if (oppositePlayer >= players.size()) {			
			oppositePlayer = players.size()-1;
		} else if (oppositePlayer < 0) {
			oppositePlayer = 0;				
		}
	}
	return oppositePlayer;
}



//implement the core resetDeck function
void Core::resetDeck()
{
	cout << discard->getDeck().size() << endl;
	for (int i=0; i<discard->getDeck().size() - 1; i++) {		//left one top card in discard
		discard->pushCard(i, draw);			//push the card to core to reset the deck
	}
}









//implement the core turnCycle function
void Core::turnCycle()
{
	int stackSize = 0;				//at the start of the turn, see how many cards have been stacked to be drawn 
	while (endGame == false) {
		players[playerXTurn]->getPlayerHand()->sortHand();		//for safety reason, just sort it 
		defaultPrinting();
		
		stackSize += players[playerXTurn]->getCardsToDraw();
		if (stackSize > 0) {		
			if (stackingMode == true) {
				stackSize = stackable(stackSize, players[playerXTurn]->getCardsToDraw());			//since only drawtwo and drawfour call the setCardsToDraw function (except for resetting), stackable will be called
			} else if (stackingMode == false) {
				players[playerXTurn]->drawCard(players[playerXTurn]->getCardsToDraw());		//if stack mode is false, go straight to draw cards
				stackSize = 0;
			}
		}

		players[playerXTurn]->setCardsToDraw(0);			//reset the number of cards that player has to draw
		players[playerXTurn]->getPlayerHand()->sortHand();		//sort hand before the turn, just for safe measure
		players[playerXTurn]->playerTurn();
		if (getHandSize(playerXTurn) == 0) {				//player out of card 
			endGame = true;
		}
		

		//end of a cycle, move on to the next one
		playerXTurn += turnDirection;
		if (turnDirection == 1) {
			if (playerXTurn >= players.size()) {			//reset turn to 0
				playerXTurn = 0;
			} else if (playerXTurn < 0) {
				playerXTurn = players.size()-1;				//reset turn to the last player
			}
		} else if (turnDirection == -1) {
			if (playerXTurn >= players.size()) {			
				playerXTurn = players.size()-1;
			} else if (playerXTurn < 0) {
				playerXTurn = 0;				
			}
		}
		
		//::animationDelay(1500);
		cout << endl;
		cout << endl;
		cout << endl;
		//::clearConsole();
	}
	if (endGame == true) {
		cout << "Alright you can go back to what people call 'real life' now, game over" << endl;
	}
}



//implement the core defaultPrinting function
void Core::defaultPrinting()
{
	cout << "Turns: ";
	if (turnDirection == 1) {
		for (int i=0; i<players.size(); i++) {			//print out the turns and number of cards in the cycle
			turnPrinting(i);
		}
	} else if (turnDirection == -1) {
		for (int i=players.size() - 1; i>=0; i--) {			//print out the turns and number of cards in the cycle
			turnPrinting(i);
		}
	}
	cout << endl;
	cout << endl;
	
	cout << "Current card is: ";
	::rgb(discard->getLastCardColor());
	cout << discard->getLastCardName() << "\e[0m" << endl;		//print out current card

	//if (typeid(players[0]).name() == "P6Player") {			//usually, player 0 is the real player. but if i want i can have 4 bots play w/ each other	
	cout << "Your hand: " << endl;				
	for (int i=0; i<players[0]->getPlayerCard().size(); i++) {
		cout << i << ". ";
		::rgb(players[0]->getPlayerCard()[i]->getColor());
		cout << players[0]->getPlayerCard()[i]->getName() << "\e[0m" << endl;
	}
	cout << endl;
	//}

	cout << players[playerXTurn]->getName() << " turn: " << endl;
}


//implement the core turnPrinting function
void Core::turnPrinting(int turn)
{
	if (players[turn]->getPlayerCard().size() == 1) {
		cout << "\e[91mUNO! \e[0m";			//put a red capitalized uno at the front of the player 
	}
	if (turn == playerXTurn) {
		cout << "\e[94m[" << players[turn]->getName() << " (" << getHandSize(turn) << ")]\e[0m -> ";		//put a small bracket at the player who is playing
	} else {
		cout << players[turn]->getName() << " (" << getHandSize(turn) << ") -> ";
	}
}




//implement the core beginGameDraw function
void Core::beginGameDraw()
{
	//each player gets 7 cards at the begin of the game
	for (int m=0; m<players.size(); m++) {
		players[m]->drawCard(7);
		//::animationDelay(400);
		players[m]->getPlayerHand()->sortHand();
	}
}




//implement the void playable function
vector<Card*> Core::playable()
{
	int currentColor = discard->getLastCardColor();
	int currentNumber = discard->getLastCardNumber();
	vector<Card*> playerHand =  players[playerXTurn]->getPlayerCard();
	vector<Card*> playableDeck;

	bool noWildcard = false;
	for (int i=0; i<playerHand.size(); i++) {
		if (playerHand[i]->getColor() == currentColor) {		//same color. wildcard color is checked below
			playableDeck.push_back(playerHand[i]);
			noWildcard = true;			//if a card matches color, noWildcard = true (tho it's useless if noBluffingMode is false)
		} else if (playerHand[i]->getNumber() == currentNumber) {			//no need to check for same wildcard number, it's checked above
			playableDeck.push_back(playerHand[i]);
			noWildcard = true;
		} else if ((playerHand[i]->getNumber() == 13 || (playerHand[i]->getNumber() == 14)) && ((noWildcard = false && noBluffingMode == true) || (noBluffingMode == false)) ) {
			playableDeck.push_back(playerHand[i]);			//since wildcards are the last cards to be checked, i don't have to worry about wildcards
		}													//being pushed into the deck before other playable cards have been pushed 
	}									//wildcard if condition analysis: number = wildcard and [(noBuffling = true & noWildcard = false) or (noBluffing = false)] 
	return playableDeck;
}




//implement the core canPlay function
bool Core::canPlay()
{
	if (playable().size() > 0) {		//call playable, if there are cards playable, return true. else, false
		return true;
	} else if (playable().size() <= 0) {
		return false;
	}	
}




//implement the core forceDraw function
void Core::forceDraw(bool choicePlayFalse)
{
	if (canPlay() == false || choicePlayFalse == false) {
		int extraCards = 0;
		bool compatibleCard = false;
		while (compatibleCard == false) {			//while the card is incompatible, continue to draw 
			players[playerXTurn]->drawCard(1);
			extraCards++;

			Card* newCard = players[playerXTurn]->getPlayerCard()[getHandSize(playerXTurn) - 1];			//check and see if the newly drawn card is compatible or not
			if (newCard->getColor() == discard->getLastCardColor() || newCard->getColor() == 5 || newCard->getNumber() == discard->getLastCardNumber()) {
				compatibleCard = true;
			}
			//::animationDelay(400);

			//if player draws a compatible card
			if (compatibleCard == true) {			//search the deck again, if there is compatible card, that means you've drawn the right card
				players[playerXTurn]->playerForceDraw(newCard);
			}
			
		}
	}
}



//implement the core choicePlay function
void Core::choicePlay()
{
	if (canPlay() == true) {
		vector<Card*> playableCards = playable();						//list the playable cards
		players[playerXTurn]->playerChoicePlay(playableCards);
	} else if (canPlay() == false) {
		forceDraw();
	}
}



//implement the core stackable function
int Core::stackable(int stackSize, int stackType)
{
	int requiredCard;			//number of the card required to stack
	if (stackType == 2) {
		requiredCard = 12;			//drawtwo	
	} else if (stackType == 4) {
		requiredCard = 14;			//drawfour
	}

	bool haveStackCard = false;
	for (int i=0; i<getHandSize(playerXTurn); i++) {							//check if there is a stackable card or not
		if (players[playerXTurn]->getPlayerCard()[i]->getNumber() == requiredCard) {
			haveStackCard = true;
			break;
		}
	}


	if (haveStackCard == true) {			//player has stackable card
		return players[playerXTurn]->playerStackable(stackSize, stackType, requiredCard);
	} else if (haveStackCard == false) {				//draw the full stack if don't have stack card
		cout << "No stackable card" << endl;
		players[playerXTurn]->drawCard(stackSize);
		return 0;				//reset the stackSize, if player don't stack card and draw the sum
	}				
}



//implement the core runGame function
void Core::runGame()
{
}

//implement the core destructor
Core::~Core()
{
}