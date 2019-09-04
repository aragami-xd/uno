#include "bot.h"
#include "core.h"
#include <time.h>
#include <iostream>
using namespace std;


//implement the bot - passive passivePlay function
int Bot::passivePlay(vector<Card*> playableCard, bool ohSeven)
{
	//cout << "call playable " << playableCard.size() << endl;
	for (int i=0; i<playableCard.size(); i++) {
		for (int m=0; m<playerCard.size(); m++) {
			if (playableCard[i]->getName() == playerCard[m]->getName()) {
				return i;
			}
		}
	}
	//to be honest, i don't really know what i should do with this thing either. just play normally like this i guess?
}