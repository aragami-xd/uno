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
	int uno;		//uno = 1 -> uno status (1 card remaining) 

public: 
	Player();
	Player(Hand* deck);

	//basic functions
	void setPlayerHand(Hand* deck);
	Hand* getPlayerHand();

	void setName(std::string pName);
	void nameEasterEgg(std::string pName);	
	std::string getName();

	void setNextTurn();
	int getNextTurn();

	void setCore(Core* gameCore);

	void setUno();
	int getUno();

	

	//action set
	void drawCard(int noOfCard);
	void playCard(int cardIndex);

	~Player();
};

#endif