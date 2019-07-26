#!/bin/bash
echo test3
for i in $(seq 1 20)
do
    ./a.out < test/input3.txt | tee test/outputStandard$i.txt
    clear
done