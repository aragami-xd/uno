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

//implement the core reverse function
void Core::reverse()
{
	turnDirection = turnDirection * (-1);
}

//implement the core skip function
void Core::skip()
{

}

//implement the core destructor
Core::~Core()
{
}