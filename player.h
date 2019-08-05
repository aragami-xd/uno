#ifndef PLAYER_H
#define PLAYER_H

#include "hand.h"
#include "draw.h"
#include "discard.h"


#include "interface.h"

class Core;

class Player
{
protected: 
	std::string playerName;
	int nextTurn;		//see if player can play the next turn or not, 1 = yes
	int playerXTurn;

	Hand* playerHand;
	std::vector<Card*> playerCard;
	Core* core;

	int uno;		//uno = 1 -> uno status (1 card remaining) 
	int cardsToDraw;		//number of cards needed to draw at the start of the turn 


	void nameEasterEgg(std::string pName);


public: 
	Player();
	Player(Hand* deck);

	//basic functions
	void setPlayerHand(Hand* deck);
	Hand* getPlayerHand();
	std::vector<Card*> getPlayerCard();

	void setName(std::string pName);
		
	std::string getName();

	void setNextTurn();
	int getNextTurn();

	void setCore(Core* gameCore);

	void setUno();
	int getUno();


	void setCardsToDraw(int noOfCards);		//this function determines which type of card player have to stack or draw (+2 / +4)
	int getCardsToDraw();

	

	//action set
	virtual void drawCard(int noOfCard);		//draw a number of cards
	void playCard(int cardIndex);			//play the card and call its effect
	void outOfCards();			//check if there is any cards left in the deck after each card drawn

	//polymorphic set
	virtual void playerChoicePlay(std::vector<Card*> playableCards) =0;
	virtual void playerTurn() =0;
	virtual void playerForceDraw(Card* newCard) =0;
	virtual int playerStackable(int stackSize, int stackType, int requiredCard) =0;
	virtual int playerSetColor() =0;
	virtual int playerChooseSwap(std::vector<Player*> otherPlayers) =0;

	~Player();
};

#endif