#include "player.h"
using namespace std;

//implement the default player constructor
Player::Player()
{
	nextTurn = 1;
}

//implement the player easterEgg function
void Player::nameEasterEgg(string pName)
{
	if (pName == "vanoss") {		//vanoss crew name easter egg
		playerName = "VanossFC4";
	} else if (pName == " ") {
		playerName = "Al Dusty - National treasure";
	} else if (pName == "al dusty") {
		playerName = "Al Duty - National disaster";
	} else if (pName == "terroriser") {
		playerName = "TehTerroriser";
	} else if (pName == "panda") {
		playerName = "BigJiggly";
	} else if (pName == "moo") {
		playerName = "Moo.Snuckel";
	} else if (pName == "nogla") {
		playerName = "DAITHIDENOGLA";
	} else if (pName == "ohm") {
		playerName = "Ohmwrecker"; 
	} else if (pName == "407") {
		playerName = "MLG_fourzer0";
	}
}

//implement the player setName function
void Player::setName(string pName)
{
	easterEgg(pName);
	playerName = pName;
}

//implement the player getName function
string Player::getName()
{
	return playerName;
}

//

//implement the player destructor
Player::~Player()
{
}