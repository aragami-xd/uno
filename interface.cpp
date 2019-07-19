#include "interface.h"
using namespace std;

//implement the animationDelay function
void animationDelay(int length)
{
    this_thread::sleep_for(chrono::milliseconds(length));
}

//implement the clearConsole function
void clearConsole()
{
    cout << flush;
    system("clear");
    cout << "Uno!" << endl;
    cout << endl;
}


//implement the rgb function
void rgb(int color)
{
	if (color == 1) {       //r
		cout << "\e[91m";
	} else if (color == 2) {        //g
		cout << "\e[92m";
	} else if (color == 3) {        //b
		cout << "\e[94m";
	} else if (color == 4) {        //y
		cout << "\e[93m";
	} else if (color == 5) {         //light grey for wildcard
        cout << "\e[37m";
    }
}

//implement the countdownTimer function
void countdownTimer(int length)
{
	int initialLength = length;
	while (length >= 0) {
		if (length >= 1000) {
			cout << "\rTime left: " << length << flush;
		} else if (length >= 100) {
			cout << "\rTime left:  " << length << flush;
		} else if (length >= 10) {
			cout << "\rTime left:   " << length << flush;
		} else if (length > 0) {
			cout << "\rTime left:    " << length << flush;
		}
		if (initialLength < 60) {		//length < 60 means countdown by seconds
			this_thread::sleep_for(chrono::seconds(1));
			length--;
		} else {			//length higher than that means countdown by milliseconds
			this_thread::sleep_for(chrono::milliseconds(20));		//until we have 1000hz monitor, we'll countdown by 20ms for 50hz. don't want vsync here
			length -= 20;
		}
	}
	cout << endl;
}