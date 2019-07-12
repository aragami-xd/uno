#include "drawfour.h"
using namespace std;

//implement the default drawfour constructor
Drawfour::Drawfour()
{
	name = "Draw 4 Wildcard";
	cardNumber = 14;
}

//implement the drawfour (cColor) constructor
Drawfour::Drawfour(int cColor) : Wildcard(cColor)
{
	name = "Draw 4 Wildcard";
	cardNumber = 14;
}

//implement the drawfour effect function
void Drawfour::effect()
{
    //effect
}

//implement the drawfour destructor
Drawfour::~Drawfour()
{
}