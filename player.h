#ifndef PLAYER_H
#define PLAYER_H

/* 
//card library 
#include "drawfour.h"
#include "colorcard.h"
#include "drawtwo.h"
#include "reverse.h"
#include "skip.h"
#include "number.h"
*/

#include "hand.h"
#include "draw.h"
#include "discard.h"


#include "interface.h"

class Core;

class Player
{
private: 
	std::string playerName;
	int nextTurn;		//see if player can play the next turn or not, 1 = yes
	Hand* playerHand;
	Core* core;

public: 
	Player();
	Player(Hand* deck);

	//basic functions
	void setPlayerHand(Hand* deck);
	Deck* getPlayerHand();

	void setName(std::string pName);
	void nameEasterEgg(std::string pName);	
	std::string getName();

	void setNextTurn();
	int getNextTurn();

	void setCore(Core* gameCore);

	//action set
	void drawCard(int noOfCard);
	void playCard(int cardIndex);

	~Player();
};

#endif