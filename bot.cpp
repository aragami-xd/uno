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
double Bot::handColorPPCalculator()
{
    int maxColorPP = 200;
    double handPP;
    int currentColor = core->getDiscard()->getLastCardColor();

    int sameColorPP = 2;        //color score multipliers 
    int wildcardPP = 3;
    int normalColor = 1;
    int ppMultiplier = sameColorPP + wildcardPP + normalColor;

    double ppPerCard = maxColorPP/(botCard.size()/ppMultiplier);
    /* ppPerCard explanation:
    - The more cards you have with either 5th color (wildcard) or same color as the current color, the better. they worth double/triple the pp
    - 8 = 2 + 3 + 3 (current color x2 + wildcard x3 + 3 other colors)       (may be adjusted in the future)
    - Hypothetically, if you have your hand full of wildcard and cards with same color as the current card, you're having the absolute powerful hand, ready to 
    fuck everyone up. Until the current color changes and they fuck you up
    - pp will be constanly recalculated in the background, so if you have 5/5 yellow cards and current color is yellow, you have 200pp. Next turn it's red and you'll get 0pp
    */

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

//implement the bot actionCardCalculator


//implement the bot destructor
Bot::~Bot()
{
}


