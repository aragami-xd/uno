#include "seven.h"
#include "player.h"
#include "core.h"
#include <iostream>
#include <algorithm>
using namespace std;

//implement the default seven constructor
Seven::Seven()
{
    cardNumber = 7;
}

//implement the seven cColor constructor
Seven::Seven(int cColor) : Action(cColor)
{
    name += "7";
    cardNumber = 7;
}

//implement the seven setName function
void Seven::setName() 
{
    name += "7";
}

//implement the seven effect function
void Seven::effect(Core* core)
{
    Player* currentPlayer;                      //get the current player and other players
    vector<Player*> otherPlayers;
    for (int i=0; i<core->getPlayers().size(); i++) {
        if (i == core->getPlayerXTurn()) {
            currentPlayer = core->getPlayers()[i];
        } else {
            otherPlayers.push_back(core->getPlayers()[i]);
        }
    }

    int swapPlayer = currentPlayer->playerChooseSwap(otherPlayers);
    ::animationDelay(500);
   
    Hand* otherHand = otherPlayers[swapPlayer]->getPlayerHand();
    otherPlayers[swapPlayer]->setPlayerHand(currentPlayer->getPlayerHand());              //set other player hand to current player hand
    currentPlayer->setPlayerHand(otherHand);            //set current player hand to that player

    ::animationDelay(500);
    cout << "Card has been swapped" << endl;
}

//implement the seven destructor
Seven::~Seven()
{
}