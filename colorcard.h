#ifndef COLORCARD_H
#define COLORCARD_H

#include "wildcard.h"

class Colorcard : public Wildcard
{
public: 
	Colorcard();
	Colorcard(int cColor);

	virtual void setName();
	void effect();

	~Colorcard();
};

#endif
