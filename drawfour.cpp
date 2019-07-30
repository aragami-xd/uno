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
	Wildcard::effect(core);
	
    int playerXTurn;
	playerXTurn = core->getNextPlayerTurn();
	
	Player* drawPlayer = core->getPlayers()[playerXTurn];	//set player to that playerX
	drawPlayer->setCardsToDraw(4);
	drawPlayer->setNextTurn();			//turns out drawfour and draw two gives you a free skip. that changes the bot design entirely 
}

//implement the drawfour destructor
Drawfour::~Drawfour()
{
}