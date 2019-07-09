#include "drawfour.h"
using namespace std;

//implement the default drawfour constructor
Drawfour::Drawfour()
{
}

//implement the drawfour (cColor) constructor
Drawfour::Drawfour(int cColor) : Wildcard(cColor)
{
	name = "Draw 4 Wildcard";
	cardNumber = 15;
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