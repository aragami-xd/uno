all : interface.o card.o wildcard.o action.o number.o drawfour.o colorcard.o drawtwo.o reverse.o skip.o zero.o seven.o deck.o hand.o draw.o discard.o core.o player.o bot.o human.o function.cpp main.cpp
	g++ interface.o card.o wildcard.o action.o number.o drawfour.o colorcard.o drawtwo.o reverse.o skip.o zero.o seven.o deck.o hand.o draw.o discard.o core.o player.o bot.o human.o function.cpp main.cpp

test: interface.o card.o wildcard.o action.o number.o drawfour.o colorcard.o drawtwo.o reverse.o skip.o zero.o seven.o deck.o hand.o draw.o discard.o core.o player.o bot.o human.o test.o function.cpp unitTest.cpp
	g++ interface.o card.o wildcard.o action.o number.o drawfour.o colorcard.o drawtwo.o reverse.o skip.o zero.o seven.o deck.o hand.o draw.o discard.o core.o player.o bot.o human.o test.o function.cpp unitTest.cpp && ./a.out | tee output.txt

debug: interface.o card.o wildcard.o action.o number.o drawfour.o colorcard.o drawtwo.o reverse.o skip.o zero.o seven.o deck.o hand.o draw.o discard.o core.o player.o bot.o human.o function.cpp debug.cpp
	g++ interface.o card.o wildcard.o action.o number.o drawfour.o colorcard.o drawtwo.o reverse.o skip.o zero.o seven.o deck.o hand.o draw.o discard.o core.o player.o bot.o human.o function.cpp debug.cpp && ./a.out | tee output.txt

clean :
	rm *.o a.out *.h.gch

stresstest :
	./test.sh




interface.o : interface.h interface.cpp
	g++ -c interface.h interface.cpp

card.o : card.h card.cpp
	g++ -c card.h card.cpp

wildcard.o : wildcard.h wildcard.cpp
	g++ -c wildcard.h wildcard.cpp

action.o : action.h action.cpp
	g++ -c action.h action.cpp

number.o : number.h number.cpp
	g++ -c number.h number.cpp

drawfour.o : drawfour.h drawfour.cpp
	g++ -c drawfour.h drawfour.cpp

colorcard.o : colorcard.h colorcard.cpp
	g++ -c colorcard.h colorcard.cpp

drawtwo.o : drawtwo.h drawtwo.cpp
	g++ -c drawtwo.h drawtwo.cpp

reverse.o : reverse.h reverse.cpp
	g++ -c reverse.h reverse.cpp

skip.o : skip.h skip.cpp
	g++ -c skip.h skip.cpp
	
zero.o : zero.h zero.cpp
	g++ -c zero.h zero.cpp

seven.o : seven.h seven.cpp
	g++ -c seven.h seven.cpp

deck.o : deck.h deck.cpp
	g++ -c deck.h deck.cpp

hand.o : hand.h hand.cpp
	g++ -c hand.h hand.cpp

draw.o : draw.h draw.cpp
	g++ -c draw.h draw.cpp

discard.o : discard.h discard.cpp
	g++ -c discard.h discard.cpp

core.o : core.h core.cpp
	g++ -c core.h core.cpp
	
player.o : player.h player.cpp
	g++ -c player.h player.cpp
	
bot.o : bot.h bot.cpp botPassive.cpp botAggressive.cpp
	g++ -c bot.h botPassive.cpp botAggressive.cpp bot.cpp 
	
human.o : human.h human.cpp
	g++ -c human.h human.cpp
	
test.o : test.h test.cpp
	g++ -c test.h test.cpp
