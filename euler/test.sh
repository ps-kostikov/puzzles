#!/bin/bash

number=$1
mode=$2

if [ $mode = 'py' ]
then
    run="python $number.py"
elif [ $mode = 'cpp' ]
then
    run="./$number"
else
    exit 1
fi

if [ -f in/$number.in ]
then
    answer=$(cat in/$number.in | $run)
else
    answer=$($run)
fi
if [ $answer = $(cat answers/$number) ]
then
    echo $number OK
else
    echo $number FAIL
    exit 1
fi