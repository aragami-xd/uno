#include "zero.h"
#include "core.h"
using namespace std;

//implement the default zero constructor
Zero::Zero()
{
}

//implement the zero (cColor) constructor
Zero::Zero(int cColor) : Action(cColor) 
{
    name += "0";
}

//implement the zero setName function
void Zero::setName()
{
    name += "0";
}

//implement the zero effect function
void Zero::effect(Core* core)
{
    vector<Hand*> playersHand;
    for (int i=0; i<core->getPlayers().size(); i++) {
        playersHand.push_back(core->getPlayers()[i]->getPlayerHand());
    }
    cout << "All players have to swap hand with the previous player" << endl;       //gameplay wise, it's previous, but programming wise, it can be the next
    for (int i=0; i<core->getPlayers().size(); i++) {
        if (core->getDirection() == 1) {    
            if (i > 0) {
                core->getPlayers()[i]->setPlayerHand(playersHand[i-1]);       //take the hand of the previous player
            } else if (i == 0) {
                core->getPlayers()[i]->setPlayerHand(playersHand[core->getPlayers().size() - 1]);         //first player will get the hand of the last player
            }
        } else if (core->getDirection() == -1) {
            if (i < core->getPlayers().size() - 1) {
                core->getPlayers()[i]->setPlayerHand(playersHand[i+1]);       //take the hand of the next player
            } else {
                core->getPlayers()[i]->setPlayerHand(playersHand[0]);         //last player will take the hand of the first player
            }
        }
    }
    ::animationDelay(500);
    cout << "All hands have been swapped" << endl;
}

//implement the zero destructor
Zero::~Zero()
{
}

