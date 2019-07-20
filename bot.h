#ifndef BOT_H
#define BOT_H

#include <vector>
#include <string>
#include "core.h"

class Bot
{
private:
    //for those who wondering, 'pp' comes from osu!
    int handPP, nextPP, oppositePP, previousPP;     //performance points of each player
    int handSize, nextSize, oppositeSize, previousSize;     //hand card size
    int botNumber, nextNumber, oppositeNumber, previousNumber;          //which player bots control

    Player* botPlayer;          //get player status
    Deck* botHand;      
    std::vector<Card*> botCard;

    Core* core;



    /*consider gameplay layout:

    (Deck)       ----------> (Opposite player) -------------
                |                                           \
                |                                           v
            (Next player)         (Discard)           (Previous player)
                 ^                                          |
                 \                                          |
                  ------------- (Bot player)  <-------------
    
    Youtube comment text emoji and art pays off

    If someone reads my code in the future, please don't edit this. leave it like that
    */



public: 
    Bot();
    Bot(Player* bot, Core* gameCore);

    //set and get stuff
    void setBotNumber(int number);
    void update();      //update different variables 


    //pp calculators 
    double handColorPPCalculator();        //calculate hand pp 
    void actionCardCalculator();


    ~Bot();
};

#endif