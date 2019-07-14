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

//implement the drawfour setName function
void Drawfour::setName()
{
	name = "Draw 4 Wildcard";
}
//implement the drawfour effect function
void Drawfour::effect(Core* core)
{
    //effect
}

//implement the drawfour destructor
Drawfour::~Drawfour()
{
}