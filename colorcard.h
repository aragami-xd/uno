#ifndef COLORCARD_H
#define COLORCARD_H

#include "wildcard.h"

class Colorcard : public Wildcard
{
private:
	virtual void setName();
public: 
	Colorcard();
	Colorcard(int cColor);

	
	void effect(Core* core);

	~Colorcard();
};

#endif
