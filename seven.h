#ifndef SEVEN_H
#define SEVEN_H

#include "action.h"

class Seven : public Action
{
public: 
    Seven();
    Seven(int cColor);

    virtual void setName();
    virtual void effect(Core* core);
    int playerEffect(Core* core, vector<Player*> otherPlayers);
	int botEffect(Core* core, vector<Player*> otherPlayers);

    ~Seven();
};

#endif