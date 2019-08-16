#!/bin/bash
echo test5: 0-7 mode, no bluffing mode
for i in $(seq 1 20)
do
    echo "$i"
    ./a.out < test/input5.txt > test/outputOhSevenNoBluffing$i.txt
    clear
done