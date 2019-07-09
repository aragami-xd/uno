#include "skip.h"
using namespace std;

//implement the default skip constructor
Skip::Skip()
{
}

//implement the skip (cColor) constructor
Skip::Skip(int cColor) : Action(cColor)
{
	name += "Skip";
	cardNumber = 12;
}

//implement the skip effect function
void Skip::effect()
{
	//effect
}

//implement the skip destructor
Skip::~Skip()
{
}