#!/bin/bash
echo test4: 0-7 default, stacking default, no bluffing mode
for i in $(seq 1 20)
do
    echo "$i"
    ./a.out < test/input4.txt | tee test/outputNoBluffing$i.txt
    clear
done