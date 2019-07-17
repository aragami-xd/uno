#include "core.h"
#include <sstream>
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
		if (players[playerXTurn]->getNextTurn() == 1) {			//if they can play, then play		
			choicePlay();
		} else if (players[playerXTurn]->getNextTurn() == -1) {				//if they cannot play, then not play, and reverse that value
			players[playerXTurn]->setNextTurn();
		}
		//end of a cycle 
		playerXTurn++;
		if (playerXTurn >= players.size()) {			//reset turn to 0
			playerXTurn = 0;
		}
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
	vector<Card*> playerHand =  players[playerXTurn]->getPlayerHand()->getDeck();
	vector<Card*> playableDeck;
	for (int i=0; i<playerHand.size(); i++) {
		if (playerHand[i]->getColor() == currentColor || playerHand[i]->getColor() == 5) {		//5 is wildcard color, can be played any time
			playableDeck.push_back(playerHand[i]);
		} else if (playerHand[i]->getNumber() == currentNumber) {			//no need to check for same wildcard number, it's checked above
			playableDeck.push_back(playerHand[i]);
		}
	}
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
		bool compatibleCard = false;
		while (compatibleCard == false) {			//while the card is incompatible, continue to draw 
			players[playerXTurn]->drawCard(1);

			//if player draws a compatible card
			if (canPlay() == true) {		//search the deck again, if there is compatible card, that means you've drawn the right card
				//i code at 2am and don't want to think anymore. so we only talk wooden pickaxe efficiency i here, no diamond pickaxe efficiency v - unbreaking iv - mending i
				//i.e. there are repetitive code
				cout << "Compatible card: " << playable()[0]->getName() << " - Play or keep?" << endl;		//ask if player wants to keep or play the card. there will be only 1 card in playable
				cout << "1. Play" << endl;			
				cout << "2. Keep" << endl;
				string choice;
				cin >> choice;
				if (choice == "1") {
					players[playerXTurn]->playCard(players[playerXTurn]->getPlayerHand()->getDeck().size() - 1);		//play the last card
				} else if (choice != "2" && choice != "1") {
					cout << "Don't mess around. Card will be kept" << endl;		//if player decides to be a dickhead, show them who is a dickhead by keep the card and have 1 more card in the hand (which is not fun)
				}
				compatibleCard = true;
			}
		}
	}
	players[playerXTurn]->getPlayerHand()->sortHand();
}

//implement the core choicePlay function
void Core::choicePlay()
{
	if (canPlay() == true) {
		cout << "You can play these cards in your deck:" << endl;
		vector<Card*> playableCards = playable();						//list the playable cards
		for (int i=0; i<playableCards.size(); i++) {
			cout << i << ". " << playableCards[i]->getName() << endl;
		}

		cout << "Choose a card to play. If you don't want to play, press 'd'" << endl;
		string choice;
		int choiceInt;
		cin >> choice;
		if (choice == "d") {				//check the input. if "d", draw new cards. else, play a card
			forceDraw(false);
		} else {
			istringstream iss (choice);
			iss >> choiceInt;
			if (choiceInt < 0 || choiceInt >= playableCards.size()) {
				cout << "Don't mess around. First card will be played" << endl;			//if they f around, play the first card
				choiceInt = 0;			//change choiceInt to 0
			}
			vector<Card*> playerHand = players[playerXTurn]->getPlayerHand()->getDeck();		//find the index of the choiceInt card in the deck
			for (int i=0; i<playerHand.size(); i++) {
				if (playerHand[i]->getName() == playableCards[choiceInt]->getName()) {
					players[playerXTurn]->playCard(i);
				}
			}
		}
	} 
}


//implement the core destructor
Core::~Core()
{
}