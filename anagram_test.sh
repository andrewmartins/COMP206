#!/bin/bash

clear

a="listen"
b="silent"
$HOME/anagram $a $b
x=$?
if [ $x -eq 0  ]; then
	echo "Test succeeded!"
else
	echo "Test failed :("
fi
c="listen"
d="silence"
$HOME/anagram $c $d
y=$?
if [ $y -eq 1 ];then
	echo "Test succeeded!"

else
	echo "Test failed :("
fi
echo "Execution of anagram program has ended successfully!"
