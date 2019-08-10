#include "human.h"
#include "core.h"
#include <sstream>
using namespace std;

//implement the default human constructor
Human::Human()
{
}

//implement the human (humanHand constructor)
Human::Human(Hand* humanHand) : Player(humanHand)
{
}


//implement the human drawCard function
void Human::drawCard(int noOfCard)
{
    for (int i=0; i<noOfCard; i++) {					//drawing x cards 
        core->getDraw()->pushCard(0, playerHand);       //get the first card
		cout << "You have drawn a ";        //print out which card has been drawn
        ::rgb(playerHand->getDeck()[playerHand->getDeck().size() - 1]->getColor());     
		cout << playerHand->getDeck()[playerHand->getDeck().size() - 1]->getName() << "\e[0m" << endl;
        Player::drawCard(noOfCard);
	}
}



//implement the human callUno function 
void Human::callUno()
{
	srand(time(0));
	char a_to_z[] = "abcdefghijklmnopqerstuwxyz";			//choose a random key to call uno
	int randomChar = rand()%26;
	char unoChar = a_to_z[randomChar];

	cout << "Press " << unoChar << " to call Uno! now!" << endl;		//prompting the user to call uno
	char charInput;
	cin >> charInput;
	if (charInput == unoChar) {
		cout << "Uno!" << endl;
		uno = 1;
	} else {
		cout << "Wrong button! Draw 2 cards" << endl;
		drawCard(2);
	}
}



//implement the human playerChoicePlay function
void Human::playerChoicePlay(vector<Card*> playableCards)
{
    cout << "Choose a card to play. If you don't want to play, press 'd' to draw extra cards: ";
	string choice;
	int choiceInt;
	bool rightChoice = false;

	while (rightChoice == false) {
	cin >> choice;
		if (choice == "d") {				//check the input. if "d", draw new cards. else, play a card
			core->forceDraw(false);
			rightChoice = true;
		} else {
			istringstream iss (choice);			//convert string to int
			iss >> choiceInt;

			if (choiceInt < 0 || choiceInt > playerCard.size()) {					//pick card out of the list
				cout << "You can't play this card. Pick again" << endl;
			} else {
				for (int i=0; i<playableCards.size(); i++) {				//pick a playable card
					if (playerCard[choiceInt]->getName() == playableCards[i]->getName()) {		//test it through for loop
						playCard(choiceInt);
						rightChoice = true;
						break;
					}
				}
				if (rightChoice == false) {			//by the end of the loop, if the condition is false, player hasn't picked the right card yet
					cout << "You can't play this card. Pick again" << endl;
				}
			}

		}
	}
}



//implement the human playerTurn function
void Human::playerTurn()
{
    if (nextTurn == 1) {			//if they can play, then play	
		::animationDelay(400);

		core->choicePlay();		//player's action in the turn 
		if (playerCard.size() == 1) {		//at the end of the turn, if there is only 1 card left, call the function 
			callUno();	
		}

	} else if (nextTurn == -1) {				//if they cannot play, then not play, and reverse that value
		nextTurn = 1;
		cout << "You cannot play this turn" << endl;
	}
}


//implement the playerForceDraw function
void Human::playerForceDraw(Card* newCard)
{
    cout << endl;
	cout << "Compatible card: ";
	::rgb(newCard->getColor());
	cout << newCard->getName() << "\e[0m - Play or keep?" << endl;		//ask if player wants to keep or play the card
	cout << "1. Play" << endl;			
	cout << "2. Keep" << endl;

	string choice;
	bool rightChoice = false;
	while (rightChoice == false) {
		cin >> choice;
		if (choice == "1") {
			playCard(playerCard.size() - 1);		//play the last card
			rightChoice = true;
		} else if (choice != "2" && choice != "1") {
			cout << "Invalid choice, choose again" << endl;		//wrong choice
		} else if (choice == "2") {		//if choose to keep, then do nothing
			rightChoice = true;
		}
	}	
}



//implement the human playerStackable function
int Human::playerStackable(int stackSize, int stackType, int requiredCard)
{
	cout << "You can stack card. Want to stack? (y/n) ";
    bool rightInput = false;
	while (rightInput == false) {
		string stackInput;
		cin >> stackInput;
		if (stackInput == "y") {			//player choose to stack
				
			cout << "Play the stackable card: ";
			while (rightInput == false) {
				int choice;
				cin >> choice;
				if (playerCard[choice]->getNumber() == requiredCard) {			//if it's the right card
					playCard(choice);
					rightInput = true;
					return stackSize;				//return the stackType
				} else {
					cout << "You can't stack that card" << endl;
				}
			}
			rightInput = true;

		} else if (stackInput == "n") {			//player choose not to stack...for some reason
			rightInput = true;
			drawCard(stackSize);					//they'll have to draw the stackSize
		} else {
			cout << "Choose again" << endl;			//turn vanoss mode and become an asshole 
		}
	}
	return 0;
}


//implement the wildcard playerSetColor function
int Human::playerSetColor()
{
    cout << "Choose a wildcard color: " << endl;
    cout << "1. \e[91mRed\e[0m" << endl;
    cout << "2. \e[92mGreen\e[0m" << endl;
    cout << "3. \e[94mBlue\e[0m" << endl;
    cout << "4. \e[93mYellow\e[0m" << endl;

    int color;
    string colorChoiceString;           //get the input color. convert string to int for foolproof

    bool rightColor = false;
    while (rightColor == false) {
        cin >> colorChoiceString;
        istringstream iss(colorChoiceString);
        iss >> color;
        if (color > 4 || color < 0) {
            cout << "Choose again" << endl;
        } else {
            rightColor = true;
            return color;
        }
    }
}


//implement the player playerChooseSwap function
int Human::playerChooseSwap(vector<Player*> otherPlayers)
{
	cout << "Which player you want to swap with?" << endl;
    for (int i=0; i<otherPlayers.size(); i++) {
        cout << i << ". " << otherPlayers[i] ->getName() << " [" << otherPlayers[i]->getPlayerCard().size() << "]" << endl;
    }
    int choice;                     //choosing the hand to swap with 
    bool rightChoice = false;
    while (rightChoice == false) {
        cin >> choice;
        if (choice >= 0 && choice < 4) {     
            cout << "Swapping card with ";
            ::rgb(4);
            cout << otherPlayers[choice]->getName() << "\e[0m" << endl;
            rightChoice = true;
        } else {
            cout << "This is a 4 player game" << endl;
        }
    }
    return choice;
}



//implement the human destructor
Human::~Human()
{
}

