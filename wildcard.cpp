#include "wildcard.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//implement the default wildcard constructor
Wildcard::Wildcard() 
{
}

//implment the wildcard color constructor
Wildcard::Wildcard(int cColor) : Card(cColor)
{
    cardType = 3;
}

//implement the wildcard setColor function
void Wildcard::setColor()
{
	cout << "Choose a wildcard color: " << endl;
    cout << "1. Red" << endl;
    cout << "2. Green" << endl;
    cout << "3. Blue" << endl;
    cout << "4. Yellow" << endl;

    string colorChoiceString;           //get the input color. convert string to int for foolproof
    while (color > 4 || color < 0) {
        cin >> colorChoiceString;
        istringstream iss(colorChoiceString);
        iss >> color;
        if (color > 4 || color < 0) {
            cout << "Don't mess around" << endl;
        }
    }

    cout << "Color has been set to ";       //confirm color change
    if (color == 1) {
        cout << "red" << endl;
    } else if (color == 2) {
        cout << "green" << endl;
    } else if (color == 3) {
        cout << "blue" << endl;
    } else if (color == 4) {
        cout << "yellow" << endl;
    }
}

//implement the card destructor
Wildcard::~Wildcard()
{
}

