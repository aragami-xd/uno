#ifndef COLORCARD_H
#define COLORCARD_H

#include "wildcard.h"

class Colorcard : public Wildcard
{
public: 
	Colorcard();
	Colorcard(int cColor);

	void effect();

	~Colorcard();
};

#endif
