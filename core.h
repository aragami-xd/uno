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

#include "player.h"

#include <vector>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>

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
	
	//basic functions 
	void setPlayers(std::vector<Player*> playerList);
	std::vector<Player*> getPlayers();

	void setPlayerXTurn(int turn);
	int getPlayerXTurn();
	
	////action sets 
	void turnCycle();		//loop between players as turns
	void beginGameDraw(Draw* draw);

	~Core();
};

#endif

