#include "bot.h"
#include "core.h"

#include "botAggressive.cpp"
#include "botPassive.cpp"
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
    // cout << "most and least color " << mostColor << " " << leastColor << endl;


    vector<int> colorStrength(4);
    for (int i=0; i<playerCard.size(); i++) {
        if (playerCard[i]->getNumber() <= 9) {             //if it's a number card, add 1 point
            colorStrength[playerCard[i]->getColor() - 1]++;          
        } else if (playerCard[i]->getNumber() == 10 || playerCard[i]->getNumber() == 11) {    //if it's skip or reverse
            colorStrength[playerCard[i]->getColor() - 1] += 2;
        } else if (playerCard[i]->getNumber() == 12) {               //if it's a drawtwo card
            colorStrength[playerCard[i]->getColor() - 1] += 3;
        }
    }
    // cout << "total score per color" << endl;
    // for (int i=0; i<colorStrength.size(); i++) {
    //     cout << colorStrength[i] << endl;
    // }
    

    
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
    strongestColor = max_element(totalPoint.begin(), totalPoint.end()) - totalPoint.begin() + 1;
    // cout << strongestColor << endl;

    //find weakest color
    for (int i=0; i<colorAmount.size(); i++) {
        if (colorAmount[i] == leastColor) {              //if it has the max color amount, multiply with colorStrength to get the prefered color
            totalPoint[i] = colorAmount[i] * colorStrength[i];
        } else {
            totalPoint[i] = 0;              //if it's not, set to 0
        }
    }
    weakestColor = min_element(totalPoint.begin(), totalPoint.end()) - totalPoint.begin() + 1;
    // cout << weakestColor << endl;
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
    	cout << "Bot " << playerName << " has drawn a card" << " ";
        ::rgb(core->getDraw()->getDeck()[0]->getColor());
        cout << core->getDraw()->getDeck()[0]->getName() << "\e[0m" << endl;
        core->getDraw()->pushCard(0, playerHand);       //get the first card
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
    // cout << strongestColor << " " << weakestColor << endl;
    if (strongestColor == 5 || weakestColor == 5) {
        cout << "\e[45m BUG ALERT! BRUH ALERT! color has not been set. setStrongestWeakestColor function is not working properly \e[0m" << endl;
    }
    setOtherHandSize();
}





//implement the bot playerTurn function
void Bot::playerTurn()
{
    update();           //update the hand, no matter what
    // cout << strongestColor << endl;
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
		nextTurn = 1;
		cout << "Bot cannot play this turn" << endl;
	}
	::animationDelay(1000);			//bot turn will have extra 1000ms of delay so you can have an idea of wtf they are doing
}



//implement the bot botChoicePlay function
void Bot::playerChoicePlay(vector<Card*> playableCards)
{  
    bool danger = false;            //danger is triggered when a player has less than 4 cards
    for (int i=0; i<otherHandSize.size(); i++) {
        if (otherHandSize[i] < 4) {
            danger = true;
        }
    }
    if (playerCard.size() < 4) {
        danger = true;
    }


    int cardToPlayIndex;
    if (danger == true) {           //if danger, play aggressive
        cardToPlayIndex = aggressivePlay(playableCards, core->getOhSeven());
    } else {
        cardToPlayIndex = passivePlay(playableCards, core->getOhSeven());
    }

    if (cardToPlayIndex >= 0) {
        for (int i=0; i<playerCard.size(); i++) {
            if (playableCards[cardToPlayIndex]->getName() == playerCard[i]->getName()) {
                playCard(i);
                break;
            }
        }
    } else {            //if it's set to -1
        core->forceDraw(false);
    }

}




//implement the bot playerForceDraw function
void Bot::playerForceDraw(Card* newCard)
{
	if (newCard->getNumber() < 13 || newCard->getColor() == getWeakestColor()) {            //keep the wildcard. the rest, play
        cout << "Bot chooses to play the card" << endl;
        playCard(playerCard.size() - 1);          
    } else {
        cout << "Bot chooses to keep the card" << endl;
    }
}





//implement the bot playerStackalble function
int Bot::playerStackable(int stackSize, int stackType, int requiredCard)
{
    cout << "Bot can stack the card" << endl;
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


//implement the bot avoidSwitch function
bool Bot::avoidSwitch()
{
    int strongestPlayerHandSize = otherHandSize[strongestOpponent];
    if (playerCard.size() <= strongestPlayerHandSize) {
        return false;
    } else {
        return true;
    }
}


//implement the bot destructor
Bot::~Bot()
{
}