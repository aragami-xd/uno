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

    int swapPlayer; 
    if (currentPlayer->getBotPlayer() == false) {               //asking which hand the player wants to swap with
        swapPlayer = playerEffect(core, otherPlayers);
    } else if (currentPlayer->getBotPlayer() == true) {
        swapPlayer = botEffect(core, otherPlayers);
    }
    //::animationDelay(500);

    //these 4 lines down here don't seem to work at all. same goes with the zero card: it doesn't swap shit. i suspect something 
    //is wrong with swapping the pointer (it doesn't swap correctly. values might have either been overlapped, or it doesnt' swap shit at all. can't really tell
    //delete these 3 lines of comment once the issues are fixed, for now keep it there
    //remember to also fix the one in zero class, since it's the same as seven
    vector<Card*> currentHand = currentPlayer->getPlayerHand()->getDeck();          //get the cards from players hand
    vector<Card*> otherHand = otherPlayers[swapPlayer]->getPlayerHand()->getDeck();
    /*
    cout << "Current hand:" << endl;
    for (int i=0; i<currentHand.size(); i++) {
        cout << i << ". " << currentHand[i]->getName() << endl;
    }
    cout << endl;
    cout << "Other hand:" << endl;
    for (int i=0; i<otherHand.size(); i++) {
        cout << i << ". " << otherHand[i]->getName() << endl;
    }
    cout << endl;
    */

    currentPlayer->getPlayerHand()->getDeck().clear();
    otherPlayers[swapPlayer]->getPlayerHand()->getDeck().clear();       //empty the players hand

    /*
    cout << "Current hand:" << endl;
    for (int i=0; i<currentHand.size(); i++) {
        cout << i << ". " << currentHand[i]->getName() << endl;
    }
    cout << endl;
    cout << "Other hand:" << endl;
    for (int i=0; i<otherHand.size(); i++) {
        cout << i << ". " << otherHand[i]->getName() << endl;
    }
    cout << endl;
    */

    currentPlayer->getPlayerHand()->setDeck(otherHand);             //set the hand of the player to the cards above
    otherPlayers[swapPlayer]->getPlayerHand()->setDeck(currentHand);

    /*
    cout << "Current hand:" << endl;
    for (int i=0; i<currentHand.size(); i++) {
        cout << i << ". " << currentHand[i]->getName() << endl;
    }
    cout << endl;
    cout << "Other hand:" << endl;
    for (int i=0; i<otherHand.size(); i++) {
        cout << i << ". " << otherHand[i]->getName() << endl;
    }
    cout << endl;
    */

    //currentPlayer->setPlayerHand(otherHand);            //set current player hand to that player
    //otherPlayers[swapPlayer]->setPlayerHand(currentHand);              //set other player hand to current player hand
    //there were some issues with swap, not being able to swap pointers and segmentation fault, so i have to do it manually
    
    //::animationDelay(500);
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
    //::animationDelay(500);

    vector<int> deckSize;
    for (int i=0; i<otherPlayers.size(); i++) {
        deckSize.push_back(otherPlayers[i]->getPlayerHand()->getDeck().size());
    }
    
    int minElementIndex = min_element(deckSize.begin(), deckSize.end()) - deckSize.begin();
    cout << "Swapping card with ";
    ::rgb(4);
    cout << otherPlayers[minElementIndex]->getName() << "\e[0m" << endl;
    return minElementIndex;
}

//implement the seven destructor
Seven::~Seven()
{
}