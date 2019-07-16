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

class Player
{
private: 
	std::string playerName;
	int nextTurn;		//see if player can play the next turn or not, 1 = yes
	Hand* playerHand;

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

	//action set
	void drawCard(int noOfCard, Draw* draw);
	void playCard(int cardIndex, Discard* discard, Core* core);

	~Player();
};

#endif