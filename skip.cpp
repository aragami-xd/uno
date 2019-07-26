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
void Skip::effect(Core* core)
{
	int playerXTurn;
	playerXTurn = core->getPlayerXTurn() + 1*core->getDirection();		//since you skip next player as cycle
	if (core->getDirection() == 1) {
		if (playerXTurn >= core->getPlayers().size()) {			//reset turn to 0
			playerXTurn = 0;
		} else if (playerXTurn < 0) {
			playerXTurn = core->getPlayers().size()-1;				//reset turn to the last player
		}
	} else if (core->getDirection() == -1) {			//for some reason, these thing behaves differently depends on which direction it is
		if (playerXTurn >= core->getPlayers().size()) {			
			playerXTurn = core->getPlayers().size()-1;
		} else if (playerXTurn < 0) {
			playerXTurn = 0;				
		}
	}
	
	Player* skippedPlayer = core->getPlayers()[playerXTurn];	//set player to that playerX
	skippedPlayer->setNextTurn();	
}


//implement the skip destructor
Skip::~Skip()
{
}