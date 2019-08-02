#ifndef BOT_H
#define BOT_H

#include "player.h"

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

class Bot : public Player
{
private:
    int strongestColor;
    int weakestColor;

public:
    Bot();
    Bot(Hand* botHand);

    //action sets
    void setStrongestWeakestColor();           //color that you have the most amount will be the strongest; if same amount, color with most action is the strongest
    int getStrongestColor();                   //color that you have the least will be the weakest, the one with least action card will be the weakest if equal amount
    int getWeakestColor();

    virtual void drawCard(int noOfCard);

    //void nextPlayerWeakestColor();


    //pure virtual implementations
    virtual void playerTurn();
	virtual void playerChoicePlay(std::vector<Card*> playableCards);	
	virtual void playerForceDraw(Card* newCard);
    virtual int playerStackable(int stackSize, int stackType, int requiredCard);
    virtual int playerSetColor();
    virtual int playerChooseSwap(std::vector<Player*> otherPlayers);

    ~Bot();
};

#endif