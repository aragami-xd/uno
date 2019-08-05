#ifndef ZERO_H
#define ZERO_H

#include "action.h"

class Zero : public Action
{
private:
    virtual void setName();

public:
    Zero();
    Zero(int cColor);
    
    
    virtual void effect(Core* core);
    ~Zero();
};

#endif