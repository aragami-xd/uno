#ifndef CORE_H
#define CORE_H

/* 
//card library 
#include "drawfour.h"
#include "colorcard.h"
#include "drawtwo.h"
#include "reverse.h"
#include "skip.h"
#include "number.h"
*/

#include "deck.h"

#include "player.h"

#include <vector>
#include <string>
#include <iostream>

class Core
{
private: 
	std::vector<Player*> players;
	int turnDirection; 	//1 for clockwise, -1 for counter clockwise turn
	int playerXTurn; 
	bool endGame;		//F in the chat for iron man

public: 
	Core();

	void setDirection();		//just take turnDirection * -1
	int getDirection();

	void setPlayers(std::vector<Player*> playerList);
	std::vector<Player*> getPlayers();

	int getPlayerXTurn();
	
	void turnCycle();		//loop between players as turns
	~Core();
};

#endif

