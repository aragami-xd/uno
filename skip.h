#ifndef SKIP_H
#define SKIP_H

#include "action.h"

class Skip : public Action 
{
private:
	virtual void setName();
	
public:
	Skip();
	Skip(int cColor);

	
	virtual void effect(Core* core);

	~Skip();
};

#endif