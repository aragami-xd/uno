#!/bin/bash
echo test2: 0-7 default, stack mode, no bluffing default
for i in $(seq 1 20)
do
    echo "$i"
    ./a.out < test/input2.txt | tee test/outputNoStack$i.txt
    clear
done