#!/bin/bash
echo test3: everything default
for i in $(seq 1 20)
do
    echo "$i"
    ./a.out < test/input3.txt > test/outputStandard$i.txt
    clear
done