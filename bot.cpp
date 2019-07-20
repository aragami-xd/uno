#include "bot.h"
using namespace std;

//implmenet the default bot constructor
Bot::Bot()
{
}

//implement the bot (bot) constructor
Bot::Bot(Player* bot, Core* gameCore)
{
    botPlayer = bot;
    botHand = botPlayer->getPlayerHand();
    botCard = botHand->getDeck();
    core = gameCore;
}




//implement the bot setBotNumber function
void Bot::setBotNumber(int number)
{
    botNumber = number;
    nextNumber = number++;
    if (nextNumber >= 4) {
        nextNumber -= 4;
    }
    previousNumber = number--;
    if (previousNumber < 0) {
        nextNumber += 4;
    }
    oppositeNumber = number + 2;
    if (nextNumber >= 4) {
        nextNumber -= 4;
    }
}


//implement the bot update function
void Bot::update()
{
    handSize = core->getHandSize(botNumber);
    nextSize = core->getHandSize(nextNumber);
    previousSize = core->getHandSize(previousNumber);
    oppositeSize = core->getHandSize(oppositeNumber);
}


//implement the bot handColorPPCalculator function
/*
double Bot::handColorPPCalculator()
{   
    int maxColorPP = 200;
    double sameColorPP = 2, wildcardPP = 3, normalColor = 1;                        //color score multipliers 
    double ppColorMultiplier = sameColorPP + wildcardPP + normalColor*3;

    double handPP;
    int currentColor = core->getDiscard()->getLastCardColor();
    double ppPerCard = maxColorPP/(botCard.size()/ppColorMultiplier);
    /* ppPerCard explanation:
    - The more cards you have with either 5th color (wildcard) or same color as the current color, the better. they worth double/triple the pp
    - 8 = 2 + 3 + 3 (current color x2 + wildcard x3 + 3 other colors)       (may be adjusted in the future)
    - Hypothetically, if you have your hand full of wildcard and cards with same color as the current card, you're having the absolute powerful hand, ready to 
    fuck everyone up. Until the current color changes and they fuck you up
    - pp will be constanly recalculated in the background, so if you have 5/5 yellow cards and current color is yellow, you have 200pp. Next turn it's red and you'll get 0pp

    for (int i=0; i<botCard.size(); i++) {
        if (botCard[i]->getColor() == 5) {
            handPP += ppPerCard * wildcardPP;          //worth double the pp (should have been 1.26 HDDTHR)
        } else if (botCard[i]->getColor() == currentColor) {
            handPP += ppPerCard * sameColorPP;
        } else {
            handPP == ppPerCard * normalColor;
        }
    }
    return handPP;
}
*/

//implement the bot handColorPPCalculator
double Bot::handColorPPCalculator()
{
    //int maxColorPP = 200;
    double sameColorPP = 2, normalColor = 1;                        //color score multipliers, no wildcards since they are calculated using number

    double handColorPP;
    int currentColor = core->getDiscard()->getLastCardColor();

    /*
    compare to the draft version above 
    - This one doesn't use maxPP and ppPerCard system, but using adjusted pp system instead
    - Kinda like osu!mania vs osu!standard scoring system: one based on combo, one based on percentage to maximum score 
    - calculate total pp like normal, then compare it with other players' pp if they got the same hand size (just multiply it)
    */

    for (int i=0; i<botCard.size(); i++) {        //worth double the pp (should have been 1.26 HDDTHR)
        if (botCard[i]->getColor() == currentColor) {
            handColorPP += sameColorPP;
        } else {
            handColorPP == normalColor;
        }
    }
    return handColorPP;
}



//implement the bot handColorPPCalculator (temporary version only)
double Bot::handColorPPCalculator()
{
    //int maxNumberPP = 200;        //higher or lower than color?
    double numberPP = 1, drawTwoPP = 2.5, reversePP = 2.25, skipPP = 2, colorCardPP = 3, drawFourPP = 3.5;
    
    //double ppNumberMultiplier = (colorCardPP + drawFourPP)/2 + (drawTwoPP + reversePP + skipPP)*2/3 + numberPP * 4;     
    //ppMultiplier considers a deck has 7 cards, with 1 wildcard, 2 action cards and 4 normal number cards  

    double handNumberPP;
    int currentNumber = core->getDiscard()->getLastCardNumber();



    for (int i=0; i<botCard.size(); i++) {              //same number -> double the value 
        int sameNumberMultiplier = 1;
        if (botCard[i]->getNumber() == currentNumber) {
            sameNumberMultiplier = 2;
        }
        if (botCard[i]->getNumber >= 0 && botCard[i]->getNumber <= 9) {     //different numbers 
            handNumberPP += numberPP * sameNumberMultiplier;
        } else if (botCard[i]->getNumber == 10) {
            handNumberPP += reversePP * sameNumberMultiplier;
        } else if (botCard[i]->getNumber == 11) {
            handNumberPP += skipPP * sameNumberMultiplier;
        } else if (botCard[i]->getNumber == 12) {
            handNumberPP += drawTwoPP * sameNumberMultiplier;
        } else if (botCard[i]->getNumber == 13) {
            handNumberPP += colorCardPP * sameNumberMultiplier;
        } else if (botCard[i]->getNumber == 14) {
            handNumberPP += drawFourPP * sameNumberMultiplier;
        } 
    }
    return handNumberPP;
}



//implement the bot ppCalculator
void Bot::ppCalculator()
{
    totalPP = handColorPPCalculator() + handNumberPPCalculator();
    //just keep it like that for now, it may change later
}

//implement the bot adjustPP function
double Bot::adjustPP(int playerNo)
{
    return totalPP * (handSize/core->getHandSize(playerNo));
}


//implement the bot destructor
Bot::~Bot()
{
}


