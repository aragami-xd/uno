#include "bot.h"
#include "core.h"
using namespace std;

//implement the default bot constructor
Bot::Bot()
{
    otherHandSize.reserve(3);
}

//implement the bot (botHand) constructor
Bot::Bot(Hand* botHand) : Player(botHand)
{
    otherHandSize.reserve(3);
}



//implement the bot setStrongestColor function
void Bot::setStrongestWeakestColor()
{
    vector<int> colorAmount(4);             //get the deck and see which color appears the most
    for (int i=0; i<playerCard.size(); i++) {
        if (playerCard[i]->getColor() != 5) {
            colorAmount[playerCard[i]->getColor() - 1]++;            //wildcard doesn't count here. -1 since color starts from 1
        }
    }
    int mostColor = *max_element(colorAmount.begin(), colorAmount.end());      //amount of card of the color with the most card
    int leastColor = *min_element(colorAmount.begin(), colorAmount.end());          //with least color


    vector<int> colorStrength(4);
    for (int i=0; i<playerCard.size(); i++) {
        if (playerCard[i]->getNumber() <= 9) {             //if it's a number card, add 1 point
            colorAmount[playerCard[i]->getColor() - 1]++;           
        } else if (playerCard[i]->getNumber() == 10 && playerCard[i]->getNumber() == 11) {    //if it's skip or reverse
            colorAmount[playerCard[i]->getColor() - 1] += 2;
        } else if (playerCard[i]->getNumber() == 12) {               //if it's a drawtwo card
            colorAmount[playerCard[i]->getColor() - 1] += 3;
        }
    }

    
    //the nature of uno is you want to be able to play for as long as possible
    //therefore, color that appears the most and have the most powerful card will be considered as the prefered color
    vector<int> totalPoint(4);                  //take the multiplication for the strongest color

    //find strongest color
    for (int i=0; i<colorAmount.size(); i++) {
        if (colorAmount[i] == mostColor) {              //if it has the max color amount, multiply with colorStrength to get the prefered color
            totalPoint[i] = colorAmount[i] * colorStrength[i];
        } else {
            totalPoint[i] = 0;              //if it's not, set to 0
        }
    }
    strongestColor = max_element(totalPoint.begin(), totalPoint.end()) - totalPoint.begin();

    //find weakest color
    for (int i=0; i<colorAmount.size(); i++) {
        if (colorAmount[i] == leastColor) {              //if it has the max color amount, multiply with colorStrength to get the prefered color
            totalPoint[i] = colorAmount[i] * colorStrength[i];
        } else {
            totalPoint[i] = 0;              //if it's not, set to 0
        }
    }
    weakestColor = min_element(totalPoint.begin(), totalPoint.end()) - totalPoint.begin();
}


//implement the bot getStrongestColor function
int Bot::getStrongestColor()
{
    return strongestColor;
}

//implement the bot getWeakestColor function
int Bot::getWeakestColor()
{
    return weakestColor;
}




//implement the bot drawCard function
void Bot::drawCard(int noOfCard)
{
    for (int i=0; i<noOfCard; i++) {					//drawing x cards 
        core->getDraw()->pushCard(0, playerHand);       //get the first card
		cout << "Bot " << playerName << " has drawn a card" << endl;
        Player::drawCard(noOfCard);
	}
    //cout << "Bot " << playerName << " has drawn " << noOfCard << " cards in total" << endl;
}



//implement the bot setOtherHandSize function
void Bot::setOtherHandSize()
{
    otherHandSize[0] = core->getHandSize(core->getNextPlayerTurn());
    otherHandSize[1] = core->getHandSize(core->getOppositePlayerTurn());
    otherHandSize[2] = core->getHandSize(core->getLastPlayerTurn());
    strongestOpponent = min_element(otherHandSize.begin(), otherHandSize.end()) - otherHandSize.begin();
}


//implement the bot update function
void Bot::update()
{
    setStrongestWeakestColor();
    setOtherHandSize();
}





//implement the bot playerTurn function
void Bot::playerTurn()
{
    update();           //update the hand, no matter what
    if (nextTurn == 1) {			//if they can play, then play	
		cout << "Bot's turn" << endl;
		cout << endl;
		//::animationDelay(2000);

		core->choicePlay();		//player's action in the turn 
		if (playerCard.size() == 1) {		//at the end of the turn, if there is only 1 card left, call the function 
			uno = uno * (-1);
			cout << "Bot called Uno" << endl;
		}


	} else if (nextTurn == -1) {				//if they cannot play, then not play, and reverse that value
		nextTurn == 1;
		cout << "Bot cannot play this turn" << endl;
	}
	::animationDelay(1000);			//bot turn will have extra 1000ms of delay so you can have an idea of wtf they are doing
}



//implement the bot botChoicePlay function
void Bot::playerChoicePlay(vector<Card*> playableCards)
{
    /*
    bool ohSeven = core->getOhSeven();

    bool callBreak = false;
    for (int m=0; m<playableCards.size() && callBreak == false; m++) {            //find the first playable card
        if (core->getHandSize(core->getNextPlayerTurn()) <= 3 ) {        //if the next player is low on card
        //play the strongest cards first. don't let them win
            for (int i=playerCard.size() - 1; i>=0; i--) {             //find the last playable card
                if (playerCard[i]->getName() == playableCards[m]->getName()) {
                    playCard(i);
                    callBreak = true;
                    break;
                }
            }
        } else {
        //if next player has more cards, play defensively -> play the weakest card first
            for (int i=0; i<playerCard.size(); i++) {           //find the first playable card
                if (playerCard[i]->getName() == playableCards[m]->getName()) {
                    cout << "Bot has found the right card and is about to play it" << endl;
                    playCard(i);
                    callBreak = true;
                    break;
                }
            }
        }
    }
    */

    int cardToPlayIndex = aggressivePlay(playableCards, core->getOhSeven());
    if (cardToPlayIndex >= 0) {
        for (int i=0; i<playableCards.size(); i++) {
            if (playableCards[i]->getName() == playerCard[cardToPlayIndex]->getName()) {
                playCard(i);
            }
        }
    } else {            //if it's set to -1
        core->forceDraw(false);
    }

}




//implement the bot playerForceDraw function
void Bot::playerForceDraw(Card* newCard)
{
	if (newCard->getNumber() < 13) {            //keep the wildcard. the rest, play
        cout << "Bot chooses to play the card" << endl;
        playCard(playerCard.size() - 1);          
    } else {
        cout << "Bot chooses to keep the card" << endl;
    }
}





//implement the bot playerStackalble function
int Bot::playerStackable(int stackSize, int stackType, int requiredCard)
{
    for (int i=0; i<playerCard.size(); i++) {
		if (playerCard[i]->getNumber() == requiredCard) {
			playCard(i);				//bot will always stack the first card they can stack 
			return stackSize;
			break;              //returning is not so necessary here, since they will always stack
		}                       //therefore, they never have to draw and reset the stackSize
	}
}


//implement the bot playerSetColor function
int Bot::playerSetColor()
{
    return getStrongestColor();
}


//implement the bot playerChooseSwap function
int Bot::playerChooseSwap(vector<Player*> otherPlayers)
{
    cout << "Bot will swap its hand with another player" << endl;
    cout << endl;
    ::animationDelay(500);

    vector<int> deckSize;
    for (int i=0; i<otherPlayers.size(); i++) {
        deckSize.push_back(otherPlayers[i]->getPlayerCard().size());
    }
    
    int minElementIndex = min_element(deckSize.begin(), deckSize.end()) - deckSize.begin();
    cout << "Swapping card with ";
    ::rgb(4);
    cout << otherPlayers[minElementIndex]->getName() << "\e[0m" << endl;
    return minElementIndex;
}


//implement the bot destructor
Bot::~Bot()
{
}