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
    vector<Card*> botCard = core->getPlayers()[playerXTurn]->getPlayerHand()->getDeck();
    vector<int> colorAmount(4);             //get the deck and see which color appears the most
    for (int i=0; i<botCard.size(); i++) {
        if (botCard[i]->getColor() != 5) {
            colorAmount[botCard[i]->getColor() - 1]++;            //wildcard doesn't count here
        }
    }
    int mostColor = *max_element(colorAmount.begin(), colorAmount.end());      //amount of card of the color with the most card
    
    vector<int> colorStrength(4);
    for (int i=0; i<botCard.size(); i++) {
        if (botCard[i]->getNumber() <= 9) {             //if it's a number card, add 1 point
            colorAmount[botCard[i]->getColor() - 1]++;           
        } else if (botCard[i]->getNumber == 10 && botCard[i]->getNumber == 11) {    //if it's skip or reverse
            colorAmount[botCard[i]->getColor() - 1] += 2;
        } else if (botCard[i]->getNumber == 12) {               //if it's a drawtwo card
            colorAmount[botCard[i]->getColor() - 1] += 3;
        }
    }
    
    //the nature of uno is you want to be able to play for as long as possible
    //therefore, color that appears the most and have the most powerful card will be considered as the prefered color
    vector<int> totalPoint(4);                  //take the multiplication for the strongest color
    for (int i=0; i<colorAmount.size(); i++) {
        if (colorAmount[i] == mostColor) {              //if it has the max color amount, multiply with colorStrength to get the prefered color
            totalPoint[i] = colorAmount[i] * colorStrength[i];
        } else {
            totalPoint[i] = 0;              //if it's not, set to 0
        }
    }
    color = max_element(totalPoint.begin(), totalPoint.end()) - totalPoint.begin();
}


//implement the card destructor
Wildcard::~Wildcard()
{
}

