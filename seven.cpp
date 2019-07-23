#include "seven.h"
#include "player.h"
#include "core.h"
#include <iostream>
#include <algorithm>
using namespace std;

//implement the default seven constructor
Seven::Seven()
{
}

//implement the seven cColor constructor
Seven::Seven(int cColor) : Action(cColor)
{
    name += "7";
}

//implement the seven setName function
void Seven::setName() 
{
    name += "7";
}

//implement the seven effect function
void Seven::effect(Core* core)
{
    Player* currentPlayer;
    vector<Player*> otherPlayers;
    for (int i=0; i<core->getPlayers().size(); i++) {
        if (i == core->getPlayerXTurn()) {
            currentPlayer = core->getPlayers()[i];
        } else {
            otherPlayers.push_back(core->getPlayers()[i]);
        }
    }

    int swapPlayer; 
    if (currentPlayer->getBotPlayer() == false) {               //asking which hand the player wants to swap with
        swapPlayer = playerEffect(core, otherPlayers);
    } else if (currentPlayer->getBotPlayer() == true) {
        swapPlayer = botEffect(core, otherPlayers);
    }
    swap(*(currentPlayer->getPlayerHand()), *(otherPlayers[swapPlayer]->getPlayerHand()));        //swapping hand
}

//implement the seven playerEffect function
int Seven::playerEffect(Core* core, vector<Player*> otherPlayers)
{
    cout << "Which player you want to swap with?" << endl;
    for (int i=0; i<otherPlayers.size(); i++) {
        cout << i << ". " << otherPlayers[i] ->getName() << " [" << otherPlayers[i]->getPlayerHand()->getDeck().size() << "]" << endl;
    }
    int choice;                     //choosing the hand to swap with 
    bool rightChoice = false;
    while (rightChoice == false) {
        cin >> choice;
        if (choice >= 1 && choice <= 3) {
            cout << "Swapping card with " << otherPlayers[choice]->getName() << endl;
        }
    }
    return choice;
}

//implement the seven botEffect function
int Seven::botEffect(Core* core, vector<Player*> otherPlayers)
{
    vector<int> deckSize;
    for (int i=0; i<otherPlayers.size(); i++) {
        deckSize.push_back(otherPlayers[i]->getPlayerHand()->getDeck().size());
    }
    if (deckSize[0] > deckSize[1] && deckSize[0] > deckSize[2]) {               //bot will always swap hand with the person with least cards
        cout << "Swapping card with " << otherPlayers[0]->getName() << endl;
        return 1;
    } else if (deckSize[1] > deckSize[0] && deckSize[1] > deckSize[2]) {
        cout << "Swapping card with " << otherPlayers[1]->getName() << endl;
        return 2;
    } else if (deckSize[2] > deckSize[1] && deckSize[2] > deckSize[1]) {
        cout << "Swapping card with " << otherPlayers[2]->getName() << endl;
        return 3;
    } 
}

//implement the seven destructor
Seven::~Seven()
{
}