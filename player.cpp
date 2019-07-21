#include "player.h"
#include "core.h"
#include <math.h>
#include <iostream>
using namespace std;

//implement the default player constructor
Player::Player()
{
	nextTurn = 1;		//player can play next turn as default
	uno = -1;
	botPlayer = true;
	cardsToDraw = 0;
}

//implement the player (deck) cosntructor
Player::Player(Hand *deck)
{
	playerHand = deck;
	nextTurn = 1;
	uno = -1;
	botPlayer = true;
	cardsToDraw = 0;
}

//implement the player setPlayerDeck function
void Player::setPlayerHand(Hand* deck)
{
	playerHand = deck;
}

//implement the player getPlayerDeck function
Hand* Player::getPlayerHand()
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

//implement the player setCore function
void Player::setCore(Core* gameCore)
{
	core = gameCore;
}

//implement the player setUno function
void Player::setUno()
{
	uno = uno*(-1);
}

//implement the player getUno function
int Player::getUno()
{
	return uno;
}

//implement the player setBotPlayer function
void Player::setBotPlayer()
{
	botPlayer = false;
}

//implement the player getBotPlayer function
bool Player::getBotPlayer()
{
	return botPlayer;
}

//implement the player setCardsToDraw function
void Player::setCardsToDraw(int noOfCards)
{
	cardsToDraw = noOfCards;
}

//implement the player getCardsToDraw function
int Player::getCardsToDraw()
{
	return cardsToDraw;
}



//implement the player drawCard function
void Player::drawCard(int noOfCard) 
{
	for (int i=0; i<noOfCard; i++) {					//drawing x cards 
		core->getDraw()->pushCard(0, playerHand);		//draw to last card to playerHand, which then delete that card in the Draw deck 
		if (botPlayer == false) {		//only print what card is drawn if it's a player, not bot
			cout << "Card ";
			::rgb(playerHand->getDeck()[playerHand->getDeck().size() - 1]->getColor());
			cout << playerHand->getDeck()[playerHand->getDeck().size() - 1]->getName() << "\e[0m is drawn" << endl;
		}
		::animationDelay(floor(1000/noOfCard));
	}
}

//implement the player playCard fuction
void Player::playCard(int cardIndex)
{
	Card* playedCard = (playerHand->getDeck()[cardIndex]);
	cout << "Card ";
	::rgb(playedCard->getColor());
	cout << playerHand->getDeck()[cardIndex]->getName() << "\e[0m" << " is played" << endl;
	cout << endl;
	playedCard->effect(core);
	playerHand->pushCard(cardIndex, core->getDiscard());
}

//implement the player destructor
Player::~Player()
{
}