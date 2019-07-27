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
	bool botPlayer = true;			//false if it's real player
	int cardsToDraw;		//number of cards needed to draw at the start of the turn 

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

	void setBotPlayer();			//if this function is called, then it's not bot player
	bool getBotPlayer();

	void setCardsToDraw(int noOfCards);		//this function determines which type of card player have to stack or draw (+2 / +4)
	int getCardsToDraw();

	

	//action set
	void drawCard(int noOfCard);
	void playCard(int cardIndex);
	void outOfCards();

	~Player();
};

#endif