#include "core.h"
using namespace std;

//implement the default core constructor
Core::Core()
{
	turnDirection = 1;
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

//implement the core getPlayerXTurn function
int Core::getPlayerXTurn()
{
	return playerXTurn;
}

//implement the core turnCycle function
void Core::turnCycle()
{
	while (endGame == false) {
		//call functions

		//end of a cycle 
		playerXTurn++;
	}
}

//implement the core destructor
Core::~Core()
{
}