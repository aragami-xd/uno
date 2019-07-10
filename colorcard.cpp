#include "colorcard.h"
using namespace std;

//implement the default colorcard constructor
Colorcard::Colorcard()
{
}

//implement the colorcard (cColor) constructor
Colorcard::Colorcard(int cColor) : Wildcard(cColor)
{
	name = "Wildcard";
	cardNumber = 13;
}

//implement the colorcard effect function
void Colorcard::effect()
{
}

//implement the colorcard destructor
Colorcard::~Colorcard()
{
}