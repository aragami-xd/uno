#include "action.h" 
using namespace std;

//implement the default action constructor
Action::Action()
{
	if (color == 1) {
		name = "Red ";
	} else if (color == 2) { 
		name = "Green ";
	} else if (color == 3) {
		name = "Blue ";
	} else if (color == 4) {
		name = "Yellow ";
	}
}

//implement the action (cColor) constructor
Action::Action(int cColor) : Card(cColor)
{
	if (color == 1) {
		name = "Red ";
	} else if (color == 2) { 
		name = "Green ";
	} else if (color == 3) {
		name = "Blue ";
	} else if (color == 4) {
		name = "Yellow ";
	}
}

//implement the action destructor
Action::~Action()
{
}