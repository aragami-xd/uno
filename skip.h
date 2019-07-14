#ifndef SKIP_H
#define SKIP_H

#include "action.h"

class Skip : public Action 
{
public:
	Skip();
	Skip(int cColor);

	virtual void setName();
	virtual void effect(Core* core);

	~Skip();
};

#endif