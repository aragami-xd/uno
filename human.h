#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"

class Human : public Player
{
private:
    virtual void drawCard(int noOfCard);
    void callUno();     //pressing uno

public:
    Human();
    Human(Hand* humanHand);

    //action set

    //pure virtual implmentations 
    virtual void playerChoicePlay(std::vector<Card*> playableCards);
	virtual void playerTurn();
	virtual void playerForceDraw(Card* newCard);
	virtual int playerStackable(int stackSize, int stackType, int requiredCard);
    virtual int playerSetColor();
    virtual int playerChooseSwap(std::vector<Player*> otherPlayers);

    ~Human();
};


#endif