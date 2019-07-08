#ifndef SKIP_H
#define SKIP_H

#include "action.h"

class Skip : public Action 
{
public:
	Skip();
	Skip(int cColor);

	virtual void effect();

	~Skip();
};

#endif