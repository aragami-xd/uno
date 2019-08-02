#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"

class Human : public Player
{
private:
public:
    Human();
    Human(Hand* humanHand);

    //action set
    virtual void drawCard(int noOfCard);
    char unoSignal();               //let the player knows that they can call uno next this round
    void callUno(char unoChar);     //pressing uno


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