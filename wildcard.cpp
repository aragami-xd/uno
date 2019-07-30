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

    if (core->getPlayers()[playerXTurn]->getBotPlayer() == false) {
        playerSetColor();
    } else {
        botSetColor(core, playerXTurn);
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

//implement the wildcard playerSetColor function
void Wildcard::playerSetColor()
{
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
            cout << "Choose again" << endl;
        } else {
            rightColor = true;
        }
    }
}

//implement the wildcard botSetPlayer function
void Wildcard::botSetColor(Core* core, int playerXTurn)
{
    vector<Card*> botCard = core->getPlayers()[playerXTurn]->getPlayerCard();
    vector<int> colorAmount(4);             //get the deck and see which color appears the most
    for (int i=0; i<botCard.size(); i++) {
        if (botCard[i]->getColor() != 5) {
            colorAmount[botCard[i]->getColor() - 1]++;            //wildcard doesn't count here
        }
    }
    color = max_element(colorAmount.begin(), colorAmount.end()) - colorAmount.begin();      //amount of card of the color with the most card
}


//implement the card destructor
Wildcard::~Wildcard()
{
}

