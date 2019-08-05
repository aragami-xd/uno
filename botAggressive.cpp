#include "bot.h"
#include "core.h"
#include <time.h>
#include <iostream>
using namespace std;


//implement the bot aggressivePlay fucntion
//implement the bot aggressivePlay function
int Bot::aggressivePlay(vector<Card*> playableCard, bool ohSeven)
{
    /*
    vector<int> blacklist;          
    //here's the thing: number goes from 0-13, with action cards are 0,7,10-13
    //however, color only goes from 1-5 (heck, we count to 4 here, since 5 is wildcard color, it can be changed into anything)
    //therefore, with 1 vector, i can hold all the colors and numbers that shouldn't be played

    int nextPlayerSize = core->getHandSize(getNextTurn());
    int lastPlayerSize = core->getHandSize(core->getLastPlayerTurn());
    int oppositePlayerSize = core->getHandSize(core->getOppositePlayerTurn());

    //apply blacklist filter with opposite and previous player only
    //we'll run the loop after that, if no cards can be played, we'll apply the blacklist for the next player as well, and reset it later
    if (lastPlayerSize > oppositePlayerSize) {          
        blacklist.push_back(11);                  //else, avoid playing skip card
        //numberBlacklist.push_back(12);                //draw two and draw four cards act the same in a way (free skip), but since they allow stacking, things
        //numberBlacklist.push_back(14);                //might be different      

    } else if (lastPlayerSize < oppositePlayerSize) {           //if last player got less card than the opposite one, it's best not to play reverse and give them the turn
        blacklist.push_back(10);
    }   
    //blacklist is to avoid the two wildcards only, not a true representation of what you should play

    int cardToBePlayed = -1;        //set to -1 for condition checking
    for (int i=playableCard.size()-1 && cardToBePlayed != -1; i>=0; i--) {          //play aggressive will loop from strongest card to the weakest
        for (int m=0; m<blacklist.size(); m++) {
            if (playableCard[i]->getNumber() != blacklist[m]) {         //if the card is not in blackList, play it
                cardToBePlayed = i;
                break;
            }
        }
    }

    //if end of this loop and nothing is played, we move on to the next one
    //same drill i guess?
    if (nextPlayerSize < lastPlayerSize) {
        
    }
    */






    vector<int> blackList;
    //blacklist will hold the list of card that shouldn't be played. action cards will have the number of 0,7,10-12, wildcard is 13-14
    //number will also hold here under the number of 1-4. no need to worry about them being number since number cards can be played at anytime
    //we'd just assumed that you cannot predict which card number other players are holding, otherwise would become an np-hard problem real quick

    //blacklist will skip the right element in the loop so that bot won't play that card
    //but if there is no other choice (i.e. all playableCards are blacklisted), the bot will either have to draw or play that card

    int cardToPlayIndex = -1;           //set to -1 default for if loop condition

    if (playerCard.size() == playableCard.size() == 1) {
        //if you have only 1 card left and you can play it, just play it already, what are you waiting for honestly?
        cardToPlayIndex = 0;
    } else {
        cout << strongestOpponent << endl;
        if (strongestOpponent == 1) {        //with the strongest opponent is the 
            blackList.push_back(getWeakestColor());          //use the weakest color as the place holder for now, change later
        } else if (strongestOpponent == 2) {
            blackList.push_back(11);         //if the opposite player is the strongest player, don't even think about touching the skip card
            //i won't be putting the drawtwo and drawfour card here "yet" since they might be able to be stacked, and i want to see how well skip behaves first
        } else if (strongestOpponent == 3) {
            blackList.push_back(12);         //blacklist the reverse
        }

    
        for (int i = playableCard.size() - 1; i >= 0 && cardToPlayIndex == -1; i++) {
            for (int m=0; m<blackList.size(); m++) {           
                if (playableCard[i]->getColor() == 5) {
                    cardToPlayIndex = i;        //if it's a wildcard
                    break;
                } else if (blackList[m] >= 1 && blackList[m] <= 4 && playableCard[i]->getColor() != blackList[m]) {    //check color blacklisting
                    if ((blackList[m] == 0 || blackList[m] > 4) && playableCard[i]->getNumber() != blackList[m]) {        //check number blacklisting
                        cardToPlayIndex = i;        //if the card is not in the blacklist
                        break;          //i choose to check the number first since despite play aggressively, it's best to save the color
                    }
                }
            }
        }

        //if cardToPlayIndex is = -1, that means you haven't been able to play any cards yet
        if (cardToPlayIndex != -1) {
            //if you can't play any card with the blacklist filter, then you'll either have to just play the strongest card you can play, or draw extra card
            //though, the second one doesn't guarantee that you'll be better off either
            //for now, i'll have some fun and go for random. toss the coin, head for play, tail for draw
            srand(0);
            int randomValue = rand() % 2;
            if (randomValue == 0) {
                return -1;                  //for now, we'll set the output to -1 for draw
            } else {
                return playableCard.size() - 1;         //return the last card
            }



            /* or maybe we can do it like this?
            if (ohSeven == true) {          //it's ohSeven, someone will swap with you anyways, what's the point of keeping low number of cards?
                return -1
            } else {
                return playableCard.size() - 1;
            }
            */
        }     
    }
    return cardToPlayIndex;   
}