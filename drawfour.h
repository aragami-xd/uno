#ifndef DRAWFOUR_H
#define DRAWFOUR_H

#include "wildcard.h"

class Drawfour : public Wildcard
{
public: 
    Drawfour();
    Drawfour(int cColor);

    void effect();
    void setName();

    ~Drawfour();
};

#endif