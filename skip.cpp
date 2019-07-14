#include "skip.h"
#include "core.h"
#include "player.h"
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

//implement the skip setName function
void Skip::setName()
{
	name += "Skip";
}

//implement the skip effect function
void Skip::effect()
{
	/* 
	int playerXTurn;
	playerXTurn = core->getPlayerXTurn() + 1*core->getDirection();		//since you skip next player as cycle

	Player* skippedPlayer = core->getPlayers()[playerXTurn];	//set player to that playerX
	skippedPlayer->setNextTurn();
	*/
	
}


//implement the skip destructor
Skip::~Skip()
{
}