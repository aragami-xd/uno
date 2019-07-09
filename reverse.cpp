#include "reverse.h"
using namespace std;

//implement the default reverse constructor
Reverse::Reverse()
{
}

//implement the reverse (cColor) constructor
Reverse::Reverse(int cColor) : Action(cColor)
{
	name += "Reverse";
	cardNumber = 11;
}

//implement the reverse effect function
void Reverse::effect()
{
	//effect
}

//implement the reverse destructor
Reverse::~Reverse()
{
}

