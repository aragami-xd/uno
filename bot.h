#ifndef BOT_H
#define BOT_H

#include "core.h"
#include "player.h"

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

class Bot
{
private:
    Player* player;
    Core* core;
    Hand* botHand;
    std::vector<Card*> botCard;

    int botTurn;
    int strongestColor;

public:
    Bot();
    
    //basic function
    void setCore(Core* gameCore);
    void setPlayer(Player* botPlayer, int playerXTurn);


    //action sets
    void setStrongestColor();           //color that you have the most amount will be the strongest; if same amount, color with most action is the strongest
    int getStrongestColor();

    int botPlayCard(std::vector<Card*> playableCards);

    //void nextPlayerWeakestColor();


    ~Bot();
};

#endif