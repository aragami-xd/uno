#include "colorcard.h"
using namespace std;

//implement the default colorcard constructor
Colorcard::Colorcard()
{
	name = "Wildcard";
	cardNumber = 13;
}

//implement the colorcard (cColor) constructor
Colorcard::Colorcard(int cColor) : Wildcard(cColor)
{
	name = "Wildcard";
	cardNumber = 13;
}

//implement the colorcard setName function
void Colorcard::setName()
{
	name = "Wildcard";
}

//implement the colorcard effect function
void Colorcard::effect()
{
	//this card doesn't really have any effect 
}

//implement the colorcard destructor
Colorcard::~Colorcard()
{
}