#ifndef SEVEN_H
#define SEVEN_H

#include <vector>
#include "action.h"

class Player;

class Seven : public Action
{
private:
    virtual void setName();
public: 
    Seven();
    Seven(int cColor);

    
    virtual void effect(Core* core);

    ~Seven();
};

#endif