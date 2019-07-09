#include "card.h"

using namespace std;

//implement the default card constructor
Card::Card()
{
}

//implement the card (cColor) constructor
Card::Card(int cColor) 
{
	color = cColor;
}

//implement the card getColor funciton
int Card::getColor()
{
	return color;
}

//implement the card getName function
string Card::getName()
{
	return name;
}

//implement the card getNumber function
int Card::getNumber()
{
	return cardNumber;
}

//implement the class destructor
Card::~Card()
{
}

