#!/bin/bash

read -p "Enter Dictionary Filename: " dict
read -p "Enter Grid Filename: " grid

make

time_1=`./a.out ${dict} ${grid} | tail -1`
time_2=`./a.out ${dict} ${grid} | tail -1`
time_3=`./a.out ${dict} ${grid} | tail -1`
time_4=`./a.out ${dict} ${grid} | tail -1`
time_5=`./a.out ${dict} ${grid} | tail -1`
total=$(( ${time_1} + ${time_2} + ${time_3} + ${time_4} + ${time_5} ))
average=$(( ${total} / 5))
echo "Program runs in ${average} miliseconds on average"

