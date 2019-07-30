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
	playerXTurn = core->getNextPlayerTurn();

	Player* drawPlayer = core->getPlayers()[playerXTurn];	//set player to that playerX
	drawPlayer->setCardsToDraw(2);
	drawPlayer->setNextTurn();
}

//implement the drawtwo destructor 
Drawtwo::~Drawtwo()
{
}