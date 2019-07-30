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

public:
    Bot();
    Bot(Hand* botHand);

    //action sets
    void setStrongestColor();           //color that you have the most amount will be the strongest; if same amount, color with most action is the strongest
    int getStrongestColor();

    int botPlayCard(std::vector<Card*> playableCards);

    //void nextPlayerWeakestColor();


    ~Bot();
};

#endif