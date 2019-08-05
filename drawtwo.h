#ifndef DRAWTWO_H
#define DRAWTWO_H

#include "action.h"

class Drawtwo : public Action 
{
private:
	virtual void setName();
public: 
	Drawtwo();
	Drawtwo(int cColor);

	
	virtual void effect(Core* core);

	~Drawtwo();
};

#endif