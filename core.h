#ifndef CORE_H
#define CORE_H

#include "player.h"
#include "interface.h"

#include <vector>
#include <string>
#include <iostream>

//class Threadfunction;

class Core
{
private: 
	//players
	std::vector<Player*> players;
	int turnDirection; 	//1 for clockwise, -1 for counter clockwise turn
	int playerXTurn; 

	//cards
	Draw *draw;
	Discard *discard;
	std::vector<Card*> cardList;

	//game mode
	bool stackingMode;
	bool noBluffingMode;
	bool ohSevenMode;

	//mics
	bool endGame;		//F in the chat for iron man, i've never watched the movie bc i didn't watch ifinity war




	//private action sets
	void defaultPrinting();			//cout some basic information at the start of the turn 
	void turnPrinting(int turn);		//print the turn things (Turn: p1->p2->...)
		
	int stackable(int stackSize, int stackType);		//ask if player can and want to stack draw cards or not

	bool canPlay();			//see if player can play any card in their hand or not
	std::vector<Card*> playable();			//get the list of cards that player can play 



public: 
	Core();

	//basic functions (i.e. set and get)
	void setDirection();		//just take turnDirection * -1
	int getDirection();
	
	void setPlayers(std::vector<Player*> playerList);
	std::vector<Player*> getPlayers();

	void setPlayerXTurn(int turn);			//for now, it's here for testing purposes, but i may ended up never need this thing at all
	int getPlayerXTurn();

	void setDraw(Draw* drawDeck);
	Draw* getDraw();

	void setDiscard(Discard* discardDeck);
	Discard* getDiscard();

	int getHandSize(int playerNo);			//this one only serve the purpose of the code looks better when i'm trying to get the card size of each player
	//which is used way more often than you might think
	
	void setStackingMode();
	void setNoBluffingMode();
	void setOhSeven();
	bool getOhSeven();			//i only need to get oh seven since it directly affact the functionaily of the bots

	int getNextPlayerTurn();
	int getLastPlayerTurn();
	int getOppositePlayerTurn();

	void resetDeck();		//reset the draw deck when it's low on card



	//public action sets 
	void beginGameDraw();			//drawing 7 cards at the beginning of the game

	void turnCycle();		//loop between players as turns

	void choicePlay();		//if player can play, they can either play a card, or draw until they get a match one
	void forceDraw(bool choicePlayFalse = true);		//if player cannot play any card, then they're forced to draw until they got a compatible card 

	void runGame();				//incorporate turnCycle and countdown timer
	
	~Core();
};

#endif

