#include "bot.h"
using namespace std;

//implement the default bot constructor
Bot::Bot()
{
}

//implement the bot setCore function
void Bot::setCore(Core* gameCore)
{
    core = gameCore;
}

//implement the bot setPlayer function
void Bot::setPlayer(Player* botPlayer, int playerXTurn)
{
    player = botPlayer;
    botHand = player->getPlayerHand();
    botCard = botHand->getDeck();

    botTurn = playerXTurn;
}







//implement the bot setStrongestColor function
void Bot::setStrongestColor()
{
    vector<int> colorAmount(4);             //get the deck and see which color appears the most
    for (int i=0; i<botCard.size(); i++) {
        if (botCard[i]->getColor() != 5) {
            colorAmount[botCard[i]->getColor() - 1]++;            //wildcard doesn't count here. -1 since color starts from 1
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
    strongestColor = max_element(totalPoint.begin(), totalPoint.end()) - totalPoint.begin();

    //should i set the weakest color here too?
}


//implement the bot getStrongestColor function
int Bot::getStrongestColor()
{
    return strongestColor;
}


//implement the bot botChoicePlay function
int Bot::botPlayCard(vector<Card*> playableCards)
{
    int choice;
    if (core->getNextHandSize() < botCard.size()) {        //compare size with next player
        //if next player has less card, play aggressive -> play the strongest card first
        for (int i=botCard.size() - 1; i>=0; i--) {             //find the last playable card
            for (int m=0; m<playableCards.size(); m++) {
                if (botCard[i]->getName() == playableCards[m]->getName()) {
                    return i;
                }
            }
        }
    } else {             
        //if next player has more card, play defensively and conserve good cards
        for (int i=0; i<botCard.size(); i++) {
            for (int m=0; m<playableCards.size(); m++) {
                if (botCard[i]->getName() == playableCards[m]->getName()) {
                    return i;
                }
            }
        }
    }
}

//implement the bot destructor
Bot::~Bot()
{
}