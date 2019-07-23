#ifndef SEVEN_H
#define SEVEN_H

#include <vector>
#include "action.h"

class Player;

class Seven : public Action
{
public: 
    Seven();
    Seven(int cColor);

    virtual void setName();
    virtual void effect(Core* core);
    int playerEffect(Core* core, std::vector<Player*> otherPlayers);
	int botEffect(Core* core, std::vector<Player*> otherPlayers);

    ~Seven();
};

#endif