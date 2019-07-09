#include "number.h"
#include "sstream"
using namespace std;

//implement the default number constructor
Number::Number()
{
}

//implement the number (cColor, cNumber) constructor
Number::Number(int cColor, int cNumber) : Card(cColor)
{
	cardNumber = cNumber;
	if (color == 1) {			//name depends on color
		name = "Red ";
	} else if (color == 2) {
		name = "Green ";
	} else if (color == 3) {
		name = "Blue ";
	} else if (color == 4) {
		name = "Yellow ";
	}
	stringstream ss;		//convert int to string
	ss << cardNumber;
	name += ss.str();
}

//implement the number effect function
void Number::effect()
{
}

//implement the number destructor
Number::~Number()
{
}