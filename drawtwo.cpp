#include "drawtwo.h"
using namespace std;

//implement the default drawtwo constructor
Drawtwo::Drawtwo()
{
	name += "Draw Two";
	cardNumber = 12;
}

//implement the drawtwo (cColor) constructor
Drawtwo::Drawtwo(int cColor) : Action(cColor)
{
	name += "Draw Two";
	cardNumber = 12;
}

//implement the drawtwo setName function
void Drawtwo::setName()
{
	name += "Draw Two";
}

//implement the drawtwo effect function
void Drawtwo::effect(Core* core)
{
	//effect
}

//implement the drawtwo destructor 
Drawtwo::~Drawtwo()
{
}