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
}