#ifndef ZERO_H
#define ZERO_H

#include "action.h"

class Zero : public Action
{
public:
    Zero();
    Zero(int cColor);
    
    virtual void setName();
    virtual void effect(Core* core);
    ~Zero();
}

#endif