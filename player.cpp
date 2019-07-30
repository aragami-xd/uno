#include "player.h"
#include "core.h"
#include <math.h>
#include <iostream>
using namespace std;

//implement the default player constructor
Player::Player()
{
	nextTurn = 1;		//player can play next turn as default
	uno = -1;
	botPlayer = true;
}

//implement the player (deck) cosntructor
Player::Player(Hand *deck)
{
	playerHand = deck;
	nextTurn = 1;
	uno = -1;
	botPlayer = true;
}

//implement the player setPlayerDeck function
void Player::setPlayerHand(Hand* deck)
{
	playerHand = deck;
	playerCard = playerHand->getDeck();
}

//implement the player getPlayerDeck function
Hand* Player::getPlayerHand()
{
	return playerHand;
}

//implement the player getPlayerCard function
vector<Card*> Player::getPlayerCard()
{
	return playerCard;
}

//implement the player easterEgg function
void Player::nameEasterEgg(string pName)			//vanoss crew name in uno
{
	if (pName == "vanoss" || pName == "evan") {				//vanoss - evan 
		playerName = "VanossFC4";
	} else if (pName == " ") {
		playerName = "Al Dusty - National treasure";			//blank name for al dusty
	} else if (pName == "al dusty") {
		playerName = "Al Duty - National disaster";				//al dusty for al duty (aka vanoss)
	} else if (pName == "terroriser" || pName == "brian") {
		playerName = "TehTerroriser";			//terroriser - brian
	} else if (pName == "panda" || pName == "anthony") {
		playerName = "BigJiggly";			//big jiggly panda	- anthony 
	} else if (pName == "moo" || pName == "brock") {
		playerName = "Moo.Snuckel";			//moo snuckel - brock
	} else if (pName == "nogla") {
		playerName = "DAITHIDEN0GLA";			//daithi de nogla - david (though no one ever calls him by his real name, so i left it out) 
	} else if (pName == "ohm" || pName == "ryan") {
		playerName = "Ohmwrecker"; 			//ohmwrecker - ryan
	} else if (pName == "407" || pName == "scotty") {
		playerName = "MLG_fourzer0";			//fourzeroseven - scotty 
	} else if (pName == "basically" || pName == "marcel") {
		playerName = "MarcelWrk";			//basicallyidowrk - marcel
	} else if (pName == "delirious") {
		playerName = "H2O_Delirious";		//h2o delirious - jonathan? never shown his face despite 10+ mil subs
	} else if (pName == "pig" || pName == "tyler") {
		playerName = "W1LDC4T43";			//i am wildcat - tyler
	}
}

//implement the player setName function
void Player::setName(string pName)
{
	playerName = pName;
	nameEasterEgg(pName);
}

//implement the player getName function
string Player::getName()
{
	return playerName;
}

//implement the player setNextTurn function
void Player::setNextTurn()
{
	nextTurn = nextTurn * (-1);
}

//implement the player getNextTurn function
int Player::getNextTurn()
{
	return nextTurn;
}

//implement the player setCore function
void Player::setCore(Core* gameCore)
{
	core = gameCore;
}

//implement the player setUno function
void Player::setUno()
{
	uno = uno*(-1);
}

//implement the player getUno function
int Player::getUno()
{
	return uno;
}

/*
//implement the player setBotPlayer function
void Player::setBotPlayer()
{
	botPlayer = false;
}

//implement the player getBotPlayer function
bool Player::getBotPlayer()
{
	return botPlayer;
}
*/

//implement the player setCardsToDraw function
void Player::setCardsToDraw(int noOfCards)
{
	cardsToDraw = noOfCards;
}

//implement the player getCardsToDraw function
int Player::getCardsToDraw()
{
	return cardsToDraw;
}



//implement the player drawCard function
void Player::drawCard(int noOfCard) 
{
	for (int i=0; i<noOfCard; i++) {					//drawing x cards 
		core->getDraw()->pushCard(0, playerHand);		//draw to last card to playerHand, which then delete that card in the Draw deck 
		if (botPlayer == false) {		//only print what card is drawn if it's a player, not bot
			cout << "Card ";
			::rgb(playerCard[playerCard.size() - 1]->getColor());
			cout << playerCard[playerCard.size() - 1]->getName() << "\e[0m is drawn" << endl;
		} else {
			cout << "Bot has drawn a card" << endl;
		}
		if (noOfCard == 1) {
			::animationDelay(300);
		} else {
			::animationDelay(floor(1000/noOfCard));
		}
		outOfCards();		//check if there are any cards left. if none, shuffle the discard deck back into the main deck
	}
}

//implement the player playCard fuction
void Player::playCard(int cardIndex)
{
	Card* playedCard = (playerCard[cardIndex]);
	cout << "Card ";
	::rgb(playedCard->getColor());
	cout << playerCard[cardIndex]->getName() << "\e[0m" << " is played" << endl;
	cout << endl;
	if (playerCard[cardIndex]->getNumber() == 7 || playerCard[cardIndex]->getNumber() == 0) {	
		playerHand->pushCard(cardIndex, core->getDiscard());			//zero and seven cards require push card first, since after effect is called
		playedCard->effect(core);										//the card is no longer there to be pushed -> break the card 
	} else {
		playedCard->effect(core);										//this apply mostly to wildcards: they search the hand of player
		playerHand->pushCard(cardIndex, core->getDiscard());			//so if it's pushed first, it cannot find players' hand anymore -> break the bot setColor
	}
}

//implement the player outOfCard function
void Player::outOfCards()
{	
	if (core->getDraw()->getDeck().size() < 1) {			//if the deck is almost out of card, shuffle all the cards in the discarded deck back into the draw deck
		cout << "Deck is almost out of card. All card from discard is pushed back into the deck" << endl;
		::animationDelay(1000);
		vector<Card*> cardList = core->getDiscard()->getDeck();
		core->getDraw()->setDeck(cardList);				//get the cards and shuffle
		core->getDraw()->shuffle();
	}
}

//implement the player destructor
Player::~Player()
{
}