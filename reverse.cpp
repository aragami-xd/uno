#include "reverse.h"
using namespace std;

//implement the default reverse constructor
Reverse::Reverse()
{
	name += "Reverse";
	cardNumber = 10;
}

//implement the reverse (cColor) constructor
Reverse::Reverse(int cColor) : Action(cColor)
{
	name += "Reverse";
	cardNumber = 10;
}

//implement the reverse effect function
void Reverse::effect()
{
	Core tempCore;
	tempCore.setDirection();
}

//implement the reverse destructor
Reverse::~Reverse()
{
}

