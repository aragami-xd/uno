To the person who is opening this file: Please close it now. This is some area 51 private s***. It's not 20th Sep yet



















If you still decide to read it, BRUH ALERT: CRINGE CONTENT AHEAD. PROCEED WITH CAUTION. LONG TERM EXPOSURE TO CRINGE CAN CAUSE BRAIN DAMAGE AND BEING UNFUNNY










Alright, to the logbook

So this file will contain some logs about the project
Since the log has been made after the oh-seven expansion has been made, there isn't much details about things far before thatb ut nevertheless: these are some key moments during the development of the game, and what i've learnt from it
Which is actually quite a lot

1. Why did i start the project?
As i've mentioned in the README.md, i want to make the game of Uno because of VanossGaming skits and funny moments in Uno
Yeah it's hillarious AF to watch, so i've decided to make something like uno
That's pretty much it. Basically i think it's cool
The project started on Jul 7, 2019. that means it has taken me 20 days to get here (or 21, since i sleep pretty late, the day has passed)

2. Designing
To be honest, i didn't do that much on the design of this program. Or at least, not that detail
But, i've designed a simple hierarchy of objects: card class and deck class. Card class will take care of the cards, different types and
Effects of each card... The cards are then created in main.cpp as a vector, passed into the core program in the draw deck (subclass of deck)
Yes, there were some minor changes in the design, but they are mostly considering if a function should be virtual, pure virtual and where should it 
be declared and initialized
I've taken an agile approach to the program, so naturally, a lot of things have been added to accomodate for the new changes

3. Unit testing
Unit testing is carried out by the test class, which mainly covers the basic functionality of the game, mosly, cards and deck. core testing is handled
using shell scripts
Unit testing seems to be broken at first, since the function runs corectly throughout the game, but the tests are still fail. After a while, i've realized 
that: A. the tests were right all along, but the methods which they used to get the input is not really good. So i've changed it. But B. some edge cases haven't been found in the program. That's why testing doesn't work, because it touches the edge cases without me even knowing it
(Those tests are based on 2 players, but the game is partially hard-coded for 4 players. though, that's probably for the best since moving on to many players
will be pretty hard)

4. 4 player release
I've released the game once (still on Github) and did share it on Facebook to see if anyone interested in it. Though, by that time, I've not firgured out how to export the code as a Windows executable program yet, so I have to make do with the fact that no one really care about it
In this release, you're essentially controlling all 4 players at once. You finished one player, then move on to play the next player. But, it did provide
some basic knowledge of how the game is like

5. Bots
My initial plan is to create 3 advanced bots, predicting players' card and strategy, assessing it's own hand's strength to choose the best playstyle
However, the plan was too ambitious to be true, at least for now. Mostly it's about time constraints, if I've had more time (i.e. summer break), I might have 
created a bot like that. Though again, it's way too ambitious, technical side. I'm no Redstone or Google engineer. I'm only me. I'd probably have to take a course in artificial intelligent or algorithm design first (the latter one is what i'm taking this sem. Wish me luck bois)
So that's why i'm ended up settle for a stupid bot: it always play the first card it can play, try to stack whenever it can, and so on. Yeah, not much. I may change the bot in the future and make it play the first card that force the color of the current card to be it's strongest color
In order for the bot to be implemented, i got to change quite a bit in the core of the program. Functionally, they are not much different from player, it just automatically play the card using the algorithm above, and don't print out too much
I'll try to migrate all the bot function into a bot class later on. But for now, if it ain't broke, don't fix it
After the bot implementation, I've released a second version of the game, now available on both Unix and Windows platform (Windows as exe, Unix as a normal compiled file)

6. System testing
There were some problem with the first system testing, but that is mostly involved around turns not behaving correctly. sometimes after the last player, the turn doesn't return to the first player and move on, which causes segmentation fault
Eventually, these errors are fixed, but that led me to have no fucking clue how the turn and direction system works with each other. While i can use them correctly now, i still have not much clue of what's going on. But hey, one man project this complex and in just a this amount of time, give me a break

7. Burning out
At some point, i was really burnt out with the project. I'm tired, i don't know what to do at all. The program has tons of errors, and i have no idea what i should do with them. Yes, that has caused some burning out effect on me. I watch anime while programming, but have no idea what i'm watching, if even watching anything at all. Yeah... not so good. I did suffer from a nother burning out later on, but right now, i'm good
Burning out mostly happen during the system tesing and debugging period
If you have access to my private Uno repository (which you are, since you're reading this), you can read the commit messages. I did describe some burning out problem in some commits
But no, as much as i'm tired and depressed with the project, i didn't want to ditch it. I want to continue working on it, no matter what. But at the same time, I wish that somehow, things just go fine without any problem

8. The 0-7 disaster
Implementing the 0-7 cards into the game turns out to be much harder than i thought. Got to change a lot of things from the existing program, and make a lot of new functons to accomodate those two. those 2 are actually quite a bit more complicated than i thought, but i have them done eventually. But there is a problem: these cards involve around swapping pointers (or objects inside pointers) of different players. This has caused a lot of conflict with wildcards

7. System testing 2 - 0-7 and wilcard conflict
Wildcards have a setColor function inside them that determine what color will it be after being played. For player, there isn't anything to worry about. But for bot, it has to analyse its own hand to see which color it has the most right now (most powerful color) and change to it. However, working alongside with swapping cards (0-7) has caused a lot of contradiction problem of passing cards around and call effects correctly
But i guess the tactic for you to debug an error, is... well... just print everything. Literally. Everything. Circle it down into a smaller size of issues then find the exact cause of error

8. Burning out 2
System testing 2 was hard. Here's the nutshell: Wildcards and 0-7 rely on different mechanic to function. To be honest, i didn't put much effort into the design of 0-7, since i'm running out of time, and i thought what could have gone wrong? Anyways, that different mechanic has left the 2 cards with only one works and the other one doesn't. But to find that thing out, it was extremely difficult. Runs after runs, hundreds out output files, and so on. That took me days to solve, and by day, i mean i've spent close to 24 hours on it. Average of 12 hours spent on the program everyday, needless to say, that number racks up quick
And yes, it was tired and frustrating

9. 0-7 tested and passed - aftermatch
Eventually I've found the root cause of the problem and fix it. All of these errors are really hard to found, but fixing them is actually really easy. There is just not much to it but swapping the order of some funcitons around, adding some if condiions, and done. 60/60 tests passed. There has never been any feeling better than this

10. No bluffing
To be honest, there isn't much to this at all. It just a matter of adding one if condition, checking if the game mode is on or not. That's it

11. Advanced bot (aka Al Duty - national disaster)
Yeah... not sure what to say about this one though. Quite a lot of fun but frustrating stuff in this iteration of the game. Thanks to Cheryl (adds lecturer), the process of debugging and upgrading the program has become quite a bit better and faster. Though with that said, i'm still under a lot of problem
Cheryl's recommendation is to using some stuff about 'alpha beta pruning' and 'depth first search' as a method to generate moves. While they seem pretty fascinating, i don't have a deep enough understanding in those things to build that model in the game, let alone implementing it

12. Coupling
The more i look into the design the program, the worse i think it is. Minimal documents (2 pages of notes) and not much design evaluation, of course it's gonna give me a lot of problem. So the problem here is: Cards shouldn't be calling stuff from core. It should be core that is calling stuff from card... Right?So it would have been better for me to just put the card's effect inside the core, right?
Looking back at the program, to be honest, specialize the cards might not have served any purposes at all. I mean the card effect rely nothing on the cards at all, and all it rely on is the core. So it's kinda like... the effect is just there at the cards, but it's not a part of the class at all!
Not sure if i should redesign it though, since at this point, i kinda just want to move on from it and work on the bot, which i still have no idea what to do next

13. More problem incoming
I guess from a perspective of a guy who have just finihed oop, the project is a success. But now that i've got a lot of the game done and i'm starting to mess around it and put more feature in, the initial design is starting to fall apart. It doesn't leave too much room for expand, and i haven't looked at the game and object from the right perspective yet. Example, i look at the cards from a perspective of a card, what can it do, not what it does. e.g. draw four wildcard can make the next player draws 4 cards, but it cannot tell the player to do so. it's the core that should handle all of those work
But still, refering back to the Yugioh example, what if i want more than just 10 different cards but hundreds of them?
Either way, the design sucks, and i'm not sure if i should really move on with it anymore. If i do then nice, but if i don't... well it's been fun. Learned a lot
