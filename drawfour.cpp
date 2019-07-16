#include "drawfour.h"
#include "core.h"
#include "player.h"
using namespace std;

//implement the default drawfour constructor
Drawfour::Drawfour()
{
	name = "Draw 4 Wildcard";
	cardNumber = 14;
}

//implement the drawfour (cColor) constructor
Drawfour::Drawfour(int cColor) : Wildcard(cColor)
{
	name = "Draw 4 Wildcard";
	cardNumber = 14;
}

//implement the drawfour setName function
void Drawfour::setName()
{
	name = "Draw 4 Wildcard";
}
//implement the drawfour effect function
void Drawfour::effect(Core* core)
{
    int playerXTurn;
	playerXTurn = core->getPlayerXTurn() + 1*core->getDirection();		//since you skip next player as cycle

	Player* drawPlayer = core->getPlayers()[playerXTurn];	//set player to that playerX
	drawPlayer->drawCard(4, core->getDraw());
}

//implement the drawfour destructor
Drawfour::~Drawfour()
{
}