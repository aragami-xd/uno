#include "drawfour.h"
using namespace std;

//implement the default drawfour constructor
Drawfour::Drawfour()
{
}

//implement the drawfour (cColor) constructor
Drawfour::Drawfour(int cColor) : Wildcard(cColor)
{
}

//implement the drawfour setName function
void Drawfour::setName() 
{
    name = "Draw 4 Wildcard";
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