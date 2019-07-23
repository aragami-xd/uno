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
	playerXTurn = core->getPlayerXTurn() + 1*core->getDirection();		//since you skip next player as cycle
	if (playerXTurn >= core->getPlayers().size()) {			//reset turn to 0
		playerXTurn = 0;
	} else if (playerXTurn < 0) {
		playerXTurn = core->getPlayers().size()-1;				//reset turn to the last player
	}
	
	Player* drawPlayer = core->getPlayers()[playerXTurn];	//set player to that playerX
	drawPlayer->setCardsToDraw(4);
	drawPlayer->setNextTurn();			//turns out drawfour and draw two gives you a free skip. that changes the bot design entirely 
}

//implement the drawfour destructor
Drawfour::~Drawfour()
{
}