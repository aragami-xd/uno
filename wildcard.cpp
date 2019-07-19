#include "wildcard.h"
#include <iostream>
#include <sstream>

using namespace std;

//implement the default wildcard constructor
Wildcard::Wildcard() 
{
    cardType = 3;
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
    cout << "1. \e[91mRed\e[0m" << endl;
    cout << "2. \e[92mGreen\e[0m" << endl;
    cout << "3. \e[94mBlue\e[0m" << endl;
    cout << "4. \e[93mYellow\e[0m" << endl;

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
    ::rgb(color);
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

//implement the wildcard effect function
void Wildcard::effect(Core* core)
{
    setColor();
}

//implement the card destructor
Wildcard::~Wildcard()
{
}

