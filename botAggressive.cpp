#include "bot.h"
#include "core.h"
#include <time.h>
#include <iostream>
using namespace std;


//implement the bot - aggressive aggressivePlay function
int Bot::aggressivePlay(vector<Card*> playableCard, bool ohSeven)
{
	vector<int> blackList;
	//blacklist will hold the list of card that shouldn't be played. action cards will have the number of 0,7,10-12, wildcard is 13-14
	//number will also hold here under the number of 1-4. no need to worry about them being number since number cards can be played at anytime
	//we'd just assumed that you cannot predict which card number other players are holding, otherwise would become an np-hard problem real quick
	//i still keep blacklist as vector since there might be more than 1 card that need to be eliminated in the future. for now, there is only 1

	blackList = setBotBlacklist(blackList, ohSeven);
	//blacklist will skip the right element in the loop so that bot won't play that card
	//but if there is no other choice (i.e. all playableCards are blacklisted), the bot will either have to draw or play that card

	int cardToPlayIndex = -1;           //set to -1 default for if loop condition
	// cout << playerCard.size() << " " << playableCard.size() << " " << blackList.size() << endl;

	if (playerCard.size() == playableCard.size() && playableCard.size() == 1) {
		//if you have only 1 card left and you can play it, just play it already, what are you waiting for honestly?
		cardToPlayIndex = 0;
	} else {
		cardToPlayIndex = checkBlacklist(blackList, playableCard);			//get a cardToPlay index from eliminating the blacklist

		//if cardToPlayIndex is = -1, that means you haven't been able to play any cards yet
		if (cardToPlayIndex != -1) {
			
			//if you can't play any card with the blacklist filter, then you'll either have to just play the strongest card you can play, or draw extra card
			//though, the second one doesn't guarantee that you'll be better off either
			//for now, i'll have some fun and go for random. toss the coin, head for play, tail for draw
			
			// srand(0);
			// int randomValue = rand() % 2;
			// if (randomValue == 0) {
			// 	return -1;                  //for now, we'll set the output to -1 for draw
			// } else {
			// 	return playableCard.size() - 1;         //return the last card
			// }



			// or maybe we can do it like this?
			if (ohSeven == true) {          //it's ohSeven, someone will swap with you anyways, what's the point of keeping low number of cards?
				return -1;
			} else {
				return playableCard.size() - 1;
			}
		}     
	}
	return cardToPlayIndex;   
}



//impleemnt the bot - aggressive setBotBlacklsit function
vector<int> Bot::setBotBlacklist(vector<int> blackList, bool ohSeven)
{
	if (strongestOpponent == 0) {        //with the strongest opponent is the 
		blackList.push_back(getWeakestColor());          //use the weakest color as the place holder for now, change later
	} else if (strongestOpponent == 1) {
		blackList.push_back(11);         //if the opposite player is the strongest player, don't even think about touching the skip card
		//i won't be putting the drawtwo and drawfour card here "yet" since they might be able to be stacked, and i want to see how well skip behaves first
	} else if (strongestOpponent == 2) {
		blackList.push_back(12);         //blacklist the reverse
	}

	if (avoidSwitch() == true && ohSeven == true) {			//if you're the strongest player in the game then don't switch card
		blackList.push_back(0);
		blackList.push_back(7);
	}
	return blackList;
}



//implement the bot - aggressive checkBlacklist function
int Bot::checkBlacklist(vector<int> blackList, vector<Card*> playableCard) {
	int cardToPlayIndex = -1;
	for (int i = playableCard.size() - 1; i >= 0; i--) {
		for (int m=0; m<blackList.size(); m++) {   
			// cout << "blacklist: " << blackList[m] << endl;        
			if (playableCard[i]->getColor() == 5) {
				// cout << playableCard[i]->getName() << endl;
				return i;        //if it's a wildcard
			} else if (blackList[m] >= 1 && blackList[m] <= 4 && playableCard[i]->getColor() != blackList[m]) {    //check color blacklisting
				// cout << playableCard[i]->getName() << endl;
				return i;        //if the card is not in the blacklist
			} else if ((blackList[m] == 0 || blackList[m] > 4) && playableCard[i]->getNumber() != blackList[m]) {        //check number blacklisting
				// cout << playableCard[i]->getName() << endl;
				return i;        //if the card is not in the blacklist
			}
		}
	}
	return -1;

	// cout << cardToPlayIndex << endl;
}