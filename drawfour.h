#ifndef DRAWFOUR_H
#define DRAWFOUR_H

#include "wildcard.h"

class Drawfour : public Wildcard
{
public: 
    Drawfour();
    Drawfour(int cColor);

    virtual void setName();
    void effect();

    ~Drawfour();
};

#endif