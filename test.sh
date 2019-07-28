./test1.sh && ./test2.sh && ./test3.sh && ./test4.sh && ./test5.sh
#these shell files will carry out the system testing, by setting every players to bot and let the game plays automatically
#the output will be saved in files (see individual testX.sh for more details)
#since the game ends with a message "Alright, you can come back to what people call 'real life' now", i can search for the 'real life' 
#keyword in the file list (ctrl shift f) in vscode, and see the result. if the amount of results is less than the amount of test (of course, 
#subtract 1 to the result since the message is also in the core.cpp file), then system testing is a fail
#unit testing has been tested in the test class. though, there are so much that you can test using unit testing
#many errors and bugs have been found during system testing (esp 7 and 0 cards), so don't tell me it's wasteful