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
    Player* currentPlayer;                      //get the current player and other players
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
    ::animationDelay(500);
    cout << "ready to swap" << endl;

    Hand* currentHand = currentPlayer->getPlayerHand();         //store the pointer of player's hand
    Hand* otherHand = otherPlayers[swapPlayer]->getPlayerHand();
    currentPlayer->setPlayerHand(otherHand);            //set current player hand to that player
    otherPlayers[swapPlayer]->setPlayerHand(currentHand);              //set other player hand to current player hand
    //there were some issues with swap, not being able to swap pointers and segmentation fault, so i have to do it manually

    cout << "Card has been swapped" << endl;
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
        if (choice >= 0 && choice < 4) {     
            cout << "Swapping card with ";
            ::rgb(4);
            cout << otherPlayers[choice]->getName() << "\e[0m" << endl;
            rightChoice = true;
        } else {
            cout << "This is a 4 player game" << endl;
        }
    }
    return choice;
}

//implement the seven botEffect function
int Seven::botEffect(Core* core, vector<Player*> otherPlayers)
{
    cout << "Bot will swap its hand with another player" << endl;
    cout << endl;
    ::animationDelay(500);

    vector<int> deckSize;
    for (int i=0; i<otherPlayers.size(); i++) {
        deckSize.push_back(otherPlayers[i]->getPlayerHand()->getDeck().size());
    }
    
    int minElementIndex = min_element(deckSize.begin(), deckSize.end()) - deckSize.begin();
    cout << "Swapping card with " << minElementIndex << endl;
    return minElementIndex;

    //what about having the same size?
}

//implement the seven destructor
Seven::~Seven()
{
}