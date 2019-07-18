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
    Player* botPlayer;
    Deck* botHand;
    std::vector<Card*> botCard;
    Core* core;

public: 
    Bot();
    Bot(Player* bot, Core* gameCore);

    double handColorPPCalculator();        //calculate hand pp 


    ~Bot();
};

#endif