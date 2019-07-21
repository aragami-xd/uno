#include "wildcard.h"
#include "core.h"
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

//implement the wildcard effect function
void Wildcard::effect(Core* core)
{
    setColor(core);
}

//implement the wildcard setColor function
void Wildcard::setColor(Core* core)
{
    int playerXTurn = core->getPlayerXTurn();

    if (playerXTurn == 0) {
	    cout << "Choose a wildcard color: " << endl;
        cout << "1. \e[91mRed\e[0m" << endl;
        cout << "2. \e[92mGreen\e[0m" << endl;
        cout << "3. \e[94mBlue\e[0m" << endl;
        cout << "4. \e[93mYellow\e[0m" << endl;

        string colorChoiceString;           //get the input color. convert string to int for foolproof
        bool rightColor = false;
        while (rightColor == false) {
            cin >> colorChoiceString;
            istringstream iss(colorChoiceString);
            iss >> color;
            if (color > 4 || color < 0) {
                cout << "Don't mess around" << endl;
            } else {
                rightColor = true;
            }
        }
    } else {
        color = 1;          //temporarily set like this for the bot
    }

    cout << "Color has been set to ";       //confirm color change
    ::rgb(color);
    if (color == 1) {
        cout << "red\e[0m" << endl;
    } else if (color == 2) {
        cout << "green\e[0m" << endl;
    } else if (color == 3) {
        cout << "blue\e[0m" << endl;
    } else if (color == 4) {
        cout << "yellow\e[0m" << endl;
    }
}

//implement the card destructor
Wildcard::~Wildcard()
{
}

