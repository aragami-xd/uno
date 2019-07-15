#include "core.h"
using namespace std;

//implement the default core constructor
Core::Core()
{
	turnDirection = 1;
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
}

//implement the core getPlayerXTurn function
int Core::getPlayerXTurn()
{
	return playerXTurn;
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
void Core::beginGameDraw(Draw* draw)
{
	for (int i=0; i<7; i++) {			//each player gets 7 cards at the begin of the game
		for (int m=0; m<4; m++) {
			players[m]->drawCard(1, draw);
			//this_thread::sleep_for(chrono::milliseconds(150));
		}
	}

	vector<Card*> pCard = (players[0]->getPlayerHand())->getDeck();
	for (int m=0; m<pCard.size(); m++) {
		cout << pCard[m]->getName() << endl;
	}
}

//implement the core destructor
Core::~Core()
{
}