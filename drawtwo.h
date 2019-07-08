#ifndef DRAWTWO_H
#define DRAWTWO_H

#include "action.h"

class Drawtwo : public Action 
{
public: 
	Drawtwo();
	Drawtwo(int cColor);

	virtual void effect();

	~Drawtwo();
};

#endif