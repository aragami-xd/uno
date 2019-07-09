//this class is used for test the program 
#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <vector>
#include <string>

#include "drawfour.h"
#include "colorcard.h"
#include "drawtwo.h"
#include "reverse.h"
#include "skip.h"
#include "number.h"

class Test
{
private: 
	std::vector<Card*> card;
public: 
	Test();
	Test(std::vector<Card*> cardList);

	void testCardName(std::string cardName, int index);
	void testCardColor(int cardColor, int index);
	void printCardList();

	~Test();
};

#endif