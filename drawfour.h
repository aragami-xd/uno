#ifndef DRAWFOUR_H
#define DRAWFOUR_H

#include "wildcard.h"

class Drawfour : public Wildcard
{
private:
    virtual void setName();
public: 
    Drawfour();
    Drawfour(int cColor);
  
    void effect(Core* core);

    ~Drawfour();
};

#endif