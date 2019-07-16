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

	Player* drawPlayer = core->getPlayers()[playerXTurn];	//set player to that playerX
	drawPlayer->drawCard(2);
}

//implement the drawtwo destructor 
Drawtwo::~Drawtwo()
{
}