#include "player.h"
#include <iostream>
using namespace std;

//implement the default player constructor
Player::Player()
{
	nextTurn = 1;		//player can play next turn as default
	Hand* deck;
	playerHand = deck;
}

//implement the player (deck) cosntructor
Player::Player(Hand *deck)
{
	playerHand = deck;
	nextTurn = 1;
}

//implement the player setPlayerDeck function
void Player::setPlayerHand(Hand* deck)
{
	playerHand = deck;
}

//implement the player getPlayerDeck function
Deck* Player::getPlayerHand()
{
	return playerHand;
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
	nameEasterEgg(pName);
	playerName = pName;
}

//implement the player getName function
string Player::getName()
{
	return playerName;
}

//implement the player setNextTurn function
void Player::setNextTurn()
{
	nextTurn = nextTurn * (-1);
}

//implement the player getNextTurn function
int Player::getNextTurn()
{
	return nextTurn;
}

//implement the player drawCard function
void Player::drawCard(int noOfCard, Draw* draw) 
{
	for (int i=0; i<noOfCard; i++) {					//drawing x cards
		vector<Card*> hand = draw->getDeck();			//put deck here since the program has to update the deck constantly 
		draw->pushCard(0, playerHand);		//draw to last card to playerHand, which then delete that card in the Draw deck 
		//this_thread::sleep_for(chrono::milliseconds(150));			//delay the process by 500 milliseconds, mostly for animation 
	}
	playerHand->sortHand();				//sort it after have finished drawing cards 
}

//implement the player destructor
Player::~Player()
{
}