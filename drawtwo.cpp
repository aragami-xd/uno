#include "drawtwo.h"
#include "core.h"
#include "player.h"
using namespace std;

//implement the default drawtwo constructor
Drawtwo::Drawtwo()
{
	name += "Draw Two";
	cardNumber = 12;
}

//implement the drawtwo (cColor) constructor
Drawtwo::Drawtwo(int cColor) : Action(cColor)
{
	name += "Draw Two";
	cardNumber = 12;
}

//implement the drawtwo setName function
void Drawtwo::setName()
{
	name += "Draw Two";
}

//implement the drawtwo effect function
void Drawtwo::effect(Core* core)
{
	int playerXTurn;
	playerXTurn = core->getPlayerXTurn() + 1*core->getDirection();		//since you skip next player as cycle
	if (playerXTurn >= core->getPlayers().size()) {			//reset turn to 0
		playerXTurn = 0;
	} else if (playerXTurn < 0) {
		playerXTurn = core->getPlayers().size()-1;				//reset turn to the last player
	}

	Player* drawPlayer = core->getPlayers()[playerXTurn];	//set player to that playerX
	drawPlayer->setCardsToDraw(2);
	drawPlayer->setNextTurn();
}

//implement the drawtwo destructor 
Drawtwo::~Drawtwo()
{
}