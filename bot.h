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

    std::vector<int> otherHandSize;       //hold the hand size of all other player. for visual representation, 0 will hold the next player, 1 is opposite, 2 is last  
    int strongestOpponent;

    //private action sets
    void setStrongestWeakestColor();           //color that you have the most amount will be the strongest; if same amount, color with most action is the strongest
    void setOtherHandSize();
    void update();              //this thing will basically update the variables regarding to the stats of the game on that turn

    bool avoidSwitch();         //this function will test and see if it's suitable for the bot to switch card with other player or not

    //aggressive tactics
    int aggressivePlay(std::vector<Card*> playableCard, bool ohSeven);
    std::vector<int> setBotBlacklist(std::vector<int> blacklist, bool ohSeven);
    int checkBlacklist(std::vector<int> blacklist, std::vector<Card*> playableCard);


    //passive bot
    int passivePlay(std::vector<Card*> playableCard, bool ohSeven);
    


public:
    Bot();
    Bot(Hand* botHand);
    

    //action sets
    int getStrongestColor();                   //color that you have the least will be the weakest, the one with least action card will be the weakest if equal amount
    int getWeakestColor();

    virtual void drawCard(int noOfCard);

    

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