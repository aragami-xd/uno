#include "core.h"
#include <sstream>
using namespace std;

//implement the default core constructor
Core::Core()
{
	turnDirection = 1;
	endGame = false;
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







//implement the core turnCycle function
void Core::turnCycle()
{
	while (endGame == false) {
		defaultPrinting();

		if (players[playerXTurn]->getNextTurn() == 1) {			//if they can play, then play	
			for (int i=0; i<getPlayersCard().size(); i++) {
				cout << i << ". ";
				::rgb(getPlayersCard()[i]->getColor());
				cout << getPlayersCard()[i]->getName() << "\e[0m" << endl;
			}

			cout << endl;
			::animationDelay(400);

			choicePlay();

		} else if (players[playerXTurn]->getNextTurn() == -1) {				//if they cannot play, then not play, and reverse that value
			players[playerXTurn]->setNextTurn();
			cout << "You cannot play this turn" << endl;
		}

		//end of a cycle, move on to the next one
		playerXTurn += turnDirection;
		if (playerXTurn >= players.size()) {			//reset turn to 0
			playerXTurn = 0;
		} else if (playerXTurn < 0) {
			playerXTurn = players.size()-1;				//reset turn to the last player
		}
		
		::animationDelay(1500);
		::clearConsole();
	}
}

//implement the core defaultPrinting function
void Core::defaultPrinting()
{
	cout << "Turns: ";
	if (turnDirection == 1) {
		for (int i=0; i<players.size(); i++) {			//print out the turns and number of cards in the cycle
			if (i == playerXTurn) {
				cout << "[Player " << i+1 << " (" << getPlayersCard().size() << ")] -> ";		//put a small bracket at the player who is playing
			} else {
				cout << "Player " << i+1 << " (" << players[i]->getPlayerHand()->getDeck().size() << ") -> ";
			}
		}
	} else if (turnDirection == -1) {
		for (int i=players.size() - 1; i>=0; i--) {			//print out the turns and number of cards in the cycle
			if (i == playerXTurn) {
				cout << "[Player " << i+1 << " (" << getPlayersCard().size() << ")] -> ";		//put a small bracket at the player who is playing
			} else {
				cout << "Player " << i+1 << " (" << players[i]->getPlayerHand()->getDeck().size() << ") -> ";
			}
		}
	}
	cout << endl;
	cout << endl;
	
	cout << "Current card is: ";
	::rgb(discard->getLastCardColor());
	cout << discard->getLastCardName() << "\e[0m" << endl;		//print out current card
	cout << "Player " << playerXTurn + 1 << " turn: " << endl;
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
	vector<Card*> playerHand =  getPlayersCard();
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
			cout << "Drawn " << getPlayersCard()[getPlayersCard().size()-1]->getName() << endl;		//print out the last card in the hand, which is the one just drawn
			::animationDelay(400);

			//if player draws a compatible card
			if (canPlay() == true) {			//search the deck again, if there is compatible card, that means you've drawn the right card
				//i code at 2am and don't want to think anymore, we don't talk efficiency here
				cout << "Compatible card: " << getPlayersCard()[getPlayersCard().size()-1]->getName() << " - Play or keep?" << endl;		//ask if player wants to keep or play the card
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
					compatibleCard = true;
				}

			}
		}
	}
	players[playerXTurn]->getPlayerHand()->sortHand();
}

//implement the core choicePlay function
void Core::choicePlay()
{
	if (canPlay() == true) {
		
		vector<Card*> playableCards = playable();						//list the playable cards

		cout << "Choose a card to play. If you don't want to play, press 'd' to draw extra cards" << endl;
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
}

//implement the core turnTimer fucntion
void Core::turnTimer()
{
	int turnLength = 8;				//use 8 seconds since if you use 10, it'll lead to the '0' not being deleted when positioned on the same line
	while (turnLength >= 0) {
		cout << "\rTimer countdown: " << turnLength << flush;			//place \r ath the front and flush at the end. pretty different from using \n at the end or endl
		::animationDelay(1000);
		turnLength--;				//not sure if it's necessary to put this thing after animation delay or not, but the internet do like that, so i'd just go for it
	}
}


//implement the core runGame function
void Core::runGame()
{
	//while (1) {
	//	thread first (&Core::turnTimer, this);
	//	thread second (&Core::turnCycle, this);
	//	first.join();
	//	second.join();
	//}
}

//implement the core destructor
Core::~Core()
{
}