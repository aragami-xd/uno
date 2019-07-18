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
#include "interface.h"

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
	Draw *draw;
	Discard *discard;

public: 
	Core();

	//basic functions (i.e. set and get)
	void setDirection();		//just take turnDirection * -1
	int getDirection();
	
	void setPlayers(std::vector<Player*> playerList);
	std::vector<Player*> getPlayers();

	void setPlayerXTurn(int turn);
	int getPlayerXTurn();

	void setDraw(Draw* drawDeck);
	Draw* getDraw();

	void setDiscard(Discard* discardDeck);
	Discard* getDiscard();

	std::vector<Card*> getPlayersCard();
	
	////action sets 
	void turnCycle();		//loop between players as turns
	void defaultPrinting();			//cout some basic information at the start of the turn 
	void beginGameDraw();			//drawing 7 cards at the beginning of the game
	
	std::vector<Card*> playable();
	bool canPlay();			//see if player can play any card in their hand or not
	void forceDraw(bool choicePlayFalse = true);		//if player cannot play any card, then they're forced to draw until they got a compatible card 
	void choicePlay();		//if player can play, they can either play a card, or draw until they get a match one
	
	void turnTimer();

	void runGame();
	
	~Core();
};

#endif

