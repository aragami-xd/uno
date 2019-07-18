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

//implement the bot handColorPPCalculator function
double Bot::handColorPPCalculator()
{
    int maxColorPP = 200;
    double handPP;
    int currentColor = core->getDiscard()->getLastCardColor();
    double ppPerCard = maxColorPP/(botCard.size()/7);
    /* ppPerCard explanation:
    - The more cards you have with either 5th color (wildcard) or same color as the current color, the better. they worth double the pp
    - 7 = 2 + 2 + 3 (current color x2 + wildcard x2 + 3 other colors)
    - Hypothetically, if you have your hand full of wildcard and cards with same color as the current card, you're having the absolute powerful hand, ready to 
    fuck everyone up. Until the current color changes and they fuck you up
    - pp will be constanly recalculated in the background, so if you have 5/5 yellow cards and current color is yellow, you have 200pp. Next turn it's red and you'll get 0pp
    */

    for (int i=0; i<botCard.size(); i++) {
        if (botCard[i]->getColor() == 5 || botCard[i]->getColor == currentColor) {
            handPP += ppPerCard*2;          //worth double the pp (should have been 1.26 HDDTHR)
        } else {
            handPP += ppPerCard;
        }
    }
    return handPP;
}


