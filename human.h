#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"

class Human : public Player
{
private:

public:
    Human();
    Human(Hand* humanHand);
}


#endif