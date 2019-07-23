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
    for (int i=0; i<core->getPlayers().size(); i++) {
        if (core->getDirection() == 1) {       
            if (i<core->getPlayers().size() - 1) {
                swap(*playersHand[i], *playersHand[i+1]);       //swap hand with next player
            } else {
                swap(*playersHand[i], *playersHand[0]);         //swap hand with the first player
            }
        } else if (core->getDirection() == -1) {
            if (i>1) {
                swap(*playersHand[i], *playersHand[i-1]);       //swap hand with previous player
            } else {
                swap(*playersHand[i], *playersHand[core->getPlayers().size() - 1]);         //swap hand with the last player
            }
        }
    }
    cout << "All hands have been swapped" << endl;
}

//implement the zero destructor
Zero::~Zero()
{
}

