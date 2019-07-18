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


//implement the card rgb function
void rgb(int color)
{
	if (color == 1) {       //r
		cout << "\e[91m ";
	} else if (color == 2) {        //g
		cout << "\e[92m ";
	} else if (color == 3) {        //b
		cout << "\e[94m ";
	} else if (color == 4) {        //y
		cout << "\e[93m ";
	} else if (color == 5) {         //light grey for wildcard
        cout << "\e[37m ";
    }
}