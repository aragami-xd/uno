#include "wildcard.h"
#include "core.h"
#include <iostream>
#include <sstream>
#include <algorithm>

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

    color = core->getPlayers()[playerXTurn]->playerSetColor();
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

