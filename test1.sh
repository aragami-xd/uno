#!/bin/bash
echo test1
for i in $(seq 1 20)
do
    ./a.out < test/input1.txt | tee test/outputOhSevenStack$i.txt
    clear
done