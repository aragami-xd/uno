#include "core.h"
using namespace std;

//implement the default core constructor
Core::Core()
{
	turnDirection = 1;
}

//implement the core setDirection function
void Core::setDirection()
{
	turnDirection = turnDirection * (-1);
}

//implement the core getDireciton function
void Core::getDireciton()
{
	return turnDirection;
}

//implement the core turnCycle function
void Core::turnCycle()
{
	while (endGame == false) {
		
	}
}

//implement the core destructor
Core::~Core()
{
}