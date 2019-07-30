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

//implement the core getPlayersCard function
vector<Card*> Core::getPlayersCard()
{
	return players[playerXTurn]->getPlayerHand()->getDeck();
}

//implement the core getHandSize function
int Core::getHandSize(int playerNo)
{
	return players[playerNo]->getPlayerCard().size();
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


//implement the core getNextHandSize function
int Core::getNextHandSize()
{
	return players[getNextPlayerTurn()]->getPlayerCard().size();
}

//implement the core getLastHandSize function
int Core::getLastHandSize()
{
	return players[getLastPlayerTurn()]->getPlayerCard().size();
}

//implement the core getOppositeHandSize function
int Core::getOppositeHandSize()
{
	return players[getOppositePlayerTurn()]->getPlayerCard().size();
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

		players[playerXTurn]->setCardsToDraw(0);			//reset the number of cards to draw
		players[playerXTurn]->getPlayerHand()->sortHand();		//sort hand before the turn 

		if (players[playerXTurn]->getBotPlayer() == false) {	
			playerTurn();
		} else {
			botTurn();
		}
		if (getPlayersCard().size() == 0) {				//player out of card 
			endGame = true;
		}
		cout << "Player now have " << getPlayersCard().size() << " cards" << endl;

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
		
		::animationDelay(1500);
		cout << endl;
		cout << endl;
		cout << endl;
		::clearConsole();
	}
	if (endGame == true) {
		cout << "Alright you can go back to what people call 'real life' now, game over" << endl;
	}
}



//implement the core playerTurn function
void Core::playerTurn()
{
	if (players[playerXTurn]->getNextTurn() == 1) {			//if they can play, then play	
		::animationDelay(400);

		char inputChar = unoSignal();		//see if player can call uno this round or not
		choicePlay();		//player's action in the turn 
		if (getPlayersCard().size() == 1) {		//at the end of the turn, if there is only 1 card left, call the function 
			callUno(inputChar);	
		}

	} else if (players[playerXTurn]->getNextTurn() == -1) {				//if they cannot play, then not play, and reverse that value
		players[playerXTurn]->setNextTurn();
		cout << "You cannot play this turn" << endl;
	}
}



//implement the core botTurn function
void Core::botTurn()
{
	if (players[playerXTurn]->getNextTurn() == 1) {			//if they can play, then play	
		cout << "Bot's turn" << endl;
		cout << endl;
		::animationDelay(2000);

		choicePlay();		//player's action in the turn 
		if (getPlayersCard().size() == 1) {		//at the end of the turn, if there is only 1 card left, call the function 
			players[playerXTurn]->setUno();
			cout << "Bot called Uno" << endl;
		}


	} else if (players[playerXTurn]->getNextTurn() == -1) {				//if they cannot play, then not play, and reverse that value
		players[playerXTurn]->setNextTurn();
		cout << "Bot cannot play this turn" << endl;
	}
	::animationDelay(1000);			//bot turn will have extra 1000ms of delay so you can have an idea of wtf they are doing
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

	if (players[0]->getBotPlayer() == false) {			//usually, player 0 is the real player. but if i want i can have 4 bots play w/ each other	
		cout << "Your hand: " << endl;
		for (int i=0; i<players[0]->getPlayerCard().size(); i++) {
			cout << i << ". ";
			::rgb(players[0]->getPlayerCard()[i]->getColor());
			cout << players[0]->getPlayerCard()[i]->getName() << "\e[0m" << endl;
			}
		cout << endl;
	}

	cout << players[playerXTurn]->getName() << " turn: " << endl;
}

//implement the core turnPrinting function
void Core::turnPrinting(int turn)
{
	if (players[turn]->getPlayerCard().size() == 1) {
		cout << "\e[91mUNO! \e[0m";			//put a red capitalized uno at the front of the player 
	}
	if (turn == playerXTurn) {
		cout << "\e[94m[" << players[turn]->getName() << " (" << players[turn]->getPlayerCard().size() << ")]\e[0m -> ";		//put a small bracket at the player who is playing
	} else {
		cout << players[turn]->getName() << " (" << players[turn]->getPlayerCard().size() << ") -> ";
	}
}




//implement the core beginGameDraw function
void Core::beginGameDraw()
{
	//each player gets 7 cards at the begin of the game
	for (int m=0; m<players.size(); m++) {
		players[m]->drawCard(7);
		::animationDelay(400);
		players[m]->getPlayerHand()->sortHand();
	}
}




//implement the void playable function
vector<Card*> Core::playable()
{
	int currentColor = discard->getLastCardColor();
	int currentNumber = discard->getLastCardNumber();
	vector<Card*> playerHand =  getPlayersCard();
	vector<Card*> playableDeck;

	bool noWildcard = false;
	for (int i=0; i<playerHand.size(); i++) {
		if (playerHand[i]->getColor() == currentColor) {		//same color. wildcard color is checked below
			playableDeck.push_back(playerHand[i]);
			noWildcard = true;			//if a card matches color, noWildcard = true (tho it's useless if noBluffingMode is false)
		} else if (playerHand[i]->getNumber() == currentNumber) {			//no need to check for same wildcard number, it's checked above
			playableDeck.push_back(playerHand[i]);
			noWildcard = true;
		} else if (playerHand[i]->getColor() == 5 && ((noWildcard = false && noBluffingMode == true) || (noBluffingMode == false))) {
			playableDeck.push_back(playerHand[i]);			//since wildcards are the last cards to be checked, i don't have to worry about wildcards
		}													//being pushed into the deck before other playable cards have been pushed 
	}									//wildcard if condition analysis: color = 5 and [(noBuffling = true & noWildcard = false) or (noBluffing = false)] 
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

			Card* newCard = getPlayersCard()[getPlayersCard().size()-1];			//check and see if the newly drawn card is compatible or not
			if (newCard->getColor() == discard->getLastCardColor() || newCard->getColor() == 5 || newCard->getNumber() == discard->getLastCardNumber()) {
				compatibleCard = true;
			}
			::animationDelay(400);

			//if player draws a compatible card
			if (compatibleCard == true) {			//search the deck again, if there is compatible card, that means you've drawn the right card
				if (players[playerXTurn]->getBotPlayer() == false) {
					playerForceDraw(newCard);
				} else {
					botForceDraw(newCard, extraCards);
				}
			}
			
		}
	}
}

//implement the core playerForceDraw function
void Core::playerForceDraw(Card* newCard)
{
	cout << endl;
	cout << "Compatible card: ";
	::rgb(newCard->getColor());
	cout << newCard->getName() << "\e[0m - Play or keep?" << endl;		//ask if player wants to keep or play the card
	cout << "1. Play" << endl;			
	cout << "2. Keep" << endl;

	string choice;
	bool rightChoice = false;
	while (rightChoice == false) {
		cin >> choice;
		if (choice == "1") {
			players[playerXTurn]->playCard(getPlayersCard().size() - 1);		//play the last card
			rightChoice = true;
		} else if (choice != "2" && choice != "1") {
			cout << "Invalid choice, choose again" << endl;		//wrong choice
		} else if (choice == "2") {		//if choose to keep, then do nothing
			rightChoice = true;
		}
	}	
}

//implement the core botForceDraw function
void Core::botForceDraw(Card* newCard, int extraCards)				//bot will always play the card
{
	cout << "Bot has drawn " << extraCards << " cards" << endl;
	players[playerXTurn]->playCard(getPlayersCard().size() - 1);
}



//implement the core choicePlay function
void Core::choicePlay()
{
	if (canPlay() == true) {
		
		vector<Card*> playableCards = playable();						//list the playable cards
		
		if (players[playerXTurn]->getBotPlayer() == false) {
			playerChoicePlay(playableCards);
		} else {
			botChoicePlay(playableCards);
		}


	} else if (canPlay() == false) {
		forceDraw();
	}
}

//implement the core playerChoicePlay function
void Core::playerChoicePlay(vector<Card*> playableCards)
{
	cout << "Choose a card to play. If you don't want to play, press 'd' to draw extra cards: ";
	string choice;
	int choiceInt;
	bool rightChoice = false;

	while (rightChoice == false) {
	cin >> choice;
		if (choice == "d") {				//check the input. if "d", draw new cards. else, play a card
			forceDraw(false);
			rightChoice = true;
		} else {
			istringstream iss (choice);			//convert string to int
			iss >> choiceInt;

			if (choiceInt < 0 || choiceInt > getPlayersCard().size()) {					//pick card out of the list
				cout << "You can't play this card. Pick again" << endl;
			} else {
				for (int i=0; i<playableCards.size(); i++) {				//pick a playable card
					if (getPlayersCard()[choiceInt]->getName() == playableCards[i]->getName()) {		//test it through for loop
						players[playerXTurn]->playCard(choiceInt);
						rightChoice = true;
						break;
					}
				}
				if (rightChoice == false) {			//by the end of the loop, if the condition is false, player hasn't picked the right card yet
					cout << "You can't play this card. Pick again" << endl;
				}
			}

		}
	}
}

//implement the core botChoicePlay function
void Core::botChoicePlay(vector<Card*> playableCards)				//bot will always play the first card they can play 
{
	bool callBreak = false;
	for (int i=0; i<getPlayersCard().size() && callBreak == false; i++) {				//pick a playable card
		for (int m=0; m<playableCards.size(); m++) {
			if (getPlayersCard()[i]->getName() == playableCards[m]->getName()) {		//test it through for loop
				players[playerXTurn]->playCard(i);
				callBreak = true;
				break;
			}
		}
	}
}





//implement the core unoSignal function 
char Core::unoSignal()
{
	srand(time(0));
	char a_to_z[] = "abcdefghijklmnopqerstuwxyz";
	int randomChar = rand()%26;
	if (getPlayersCard().size() == 2 && canPlay() == true) {
		cout << "Ready for Uno? Press " << a_to_z[randomChar] << " to call Uno after playing the card" << endl;
		cout << endl;
	}
	return a_to_z[randomChar];
}




//implement the core callUno function 
void Core::callUno(char unoChar)
{
	cout << "Press " << unoChar << " now!" << endl;
	char charInput;
	cin >> charInput;
	if (charInput == unoChar) {
		cout << "Uno!" << endl;
		players[playerXTurn]->setUno();
	} else {
		cout << "Wrong button!" << endl;
		players[playerXTurn]->drawCard(2);
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
	for (int i=0; i<getPlayersCard().size(); i++) {							//check if there is a stackable card or not
		if (getPlayersCard()[i]->getNumber() == requiredCard) {
			cout << "You can stack card. Want to stack? (y/n) ";
			haveStackCard = true;
			break;
		}
	}


	if (haveStackCard == true && players[playerXTurn]->getBotPlayer() == false) {			//player has stackable card
		return playerStackable(stackSize, stackType, requiredCard);
	} else if (haveStackCard == true && players[playerXTurn]->getBotPlayer() == true) {		//bot has stackable card
		return botStackable(stackSize, stackType, requiredCard);
	} else if (haveStackCard == false) {				//draw the full stack if don't have stack card
		cout << "No stackable card" << endl;
		players[playerXTurn]->drawCard(stackSize);
		return 0;				//reset the stackSize, if player don't stack card and draw the sum
	}					
}


//implement the core playerStackable function
int Core::playerStackable(int stackSize, int stackType, int requiredCard)
{
	bool rightInput = false;
	while (rightInput == false) {
		string stackInput;
		cin >> stackInput;
		if (stackInput == "y") {			//player choose to stack
				
			cout << "Play the stackable card: ";
			while (rightInput == false) {
				int choice;
				cin >> choice;
				if (getPlayersCard()[choice]->getNumber() == requiredCard) {			//if it's the right card
					players[playerXTurn]->playCard(choice);
					rightInput = true;
					return stackSize;				//return the stackType
				} else {
					cout << "You can't stack that card" << endl;
				}
			}
			rightInput = true;

		} else if (stackInput == "n") {			//player choose not to stack...for some reason
			rightInput = true;
			players[playerXTurn]->drawCard(stackSize);					//they'll have to draw the stackSize
		} else {
			cout << "Choose again" << endl;			//turn vanoss mode and become an asshole 
		}
	}
	return 0;
}

//implement the core botStackable function
int Core::botStackable(int stackSize, int stackType, int requiredCard)
{
	for (int i=0; i<getPlayersCard().size(); i++) {
		if (getPlayersCard()[i]->getNumber() == requiredCard) {
			players[playerXTurn]->playCard(i);				//bot will always stack the first card they can stack 
			return stackSize;
			break;
		}
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