#include "skip.h"
using namespace std;

//implement the default skip constructor
Skip::Skip()
{
	name += "Skip";
	cardNumber = 11;
}

//implement the skip (cColor) constructor
Skip::Skip(int cColor) : Action(cColor)
{
	name += "Skip";
	cardNumber = 11;
}

//implement the skip effect function
void Skip::effect()
{
	int playerXTurn;
	Core tempCore;
	playerXTurn = tempCore.getPlayerXTurn() + 1*tempCore.getDirection();		//since you skip next player as cycle

	Player* skippedPlayer = tempCore.getPlayers()[playerXTurn];	//set player to that playerX
	skippedPlayer->setNextTurn();
}


//implement the skip destructor
Skip::~Skip()
{
}