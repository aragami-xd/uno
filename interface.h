#ifndef INTERFACE_H
#define INTERFACE_H

#include <chrono>
#include <thread>
#include <iostream>


//user interface functions
void animationDelay(int length);        
void clearConsole();
void rgb(int color);			//linustechtips and the PCMR community will be proud
void countdownTimer(int length);
void stackTrace();

#endif