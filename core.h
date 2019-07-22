#ifndef CORE_H
#define CORE_H

#include "player.h"
#include "interface.h"
#include "thread.h"

#include <vector>
#include <string>
#include <iostream>

//class Threadfunction;

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
	int getHandSize(int playerNo);
	


	////action sets 
	void turnCycle();		//loop between players as turns
	void playerTurn();
	void botTurn();
	
	void defaultPrinting();			//cout some basic information at the start of the turn 
	void turnPrinting(int turn);		//print the turn things (Turn: p1->p2->...)
	
	void beginGameDraw();			//drawing 7 cards at the beginning of the game
	
	std::vector<Card*> playable();			//get the list of cards that player can play 
	bool canPlay();			//see if player can play any card in their hand or not

	void forceDraw(bool choicePlayFalse = true);		//if player cannot play any card, then they're forced to draw until they got a compatible card 
	void playerForceDraw(Card* newCard);
	void botForceDraw(Card* newCard, int extraCards);

	void choicePlay();		//if player can play, they can either play a card, or draw until they get a match one
	void playerChoicePlay(std::vector<Card*> playableCards);
	void botChoicePlay(std::vector<Card*> playableCards);
	
	char unoSignal();			//remind user that they can call uno this round
	void callUno(char unoChar);			//call uno

	int stackable(int stackSize, int stackType);		//ask if player wants to stack draw cards or not
	int playerStackable(int stackSize, int stackType, int requiredCard);
	int botStackable(int stackSize, int stackType, int requiredCard);

	void runGame();				//incorporate turnCycle and countdown timer
	
	~Core();
};

#endif

