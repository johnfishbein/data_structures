#!/bin/bash
read -p "enter the exponent for counter.cpp: " num
total=0
if [[ ${num} != "quit" ]] ; then
    for i in {1..5} ; do
	echo "Running iteration "${i}"..."
	run_time=`./a.out ${num} | tail -1`
	echo "time taken: "${run_time} "ms"
	total=`expr ${total} + ${run_time}`
    done
echo "5 iterations took "${total}" ms"
result=`expr ${total} / 5`
echo "Average time was "${result}" ms"
fi
