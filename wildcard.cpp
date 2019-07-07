#include "wildcard.h"

//implement the default wildcard constructor
Wildcard::Wildcard() 
{
}

//implment the wildcard color constructor
Wildcard::Wildcard(int cColor) : Card(cColor)
{
    cardType = 3;
}

//implement the card destructor
Wildcard::~Wildcard()
{
}

