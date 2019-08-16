#!/bin/bash
echo test1: 0-7 mode, stack default, no bluffing default
for i in $(seq 1 20)
do
    echo "$i"
    ./a.out < test/input1.txt > test/outputOhSevenStack$i.txt
    clear
done