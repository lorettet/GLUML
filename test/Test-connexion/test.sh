#!/bin/bash

make
retvalue=0
./a.out < input1 &> output.txt
echo "--- Expected ---"
cat expected.txt
echo "--- output ---"
cat output.txt
differences=$(diff output.txt expected1.txt)
if [ "$differences" = "" ]	
then
	echo "Test validé"
else
	echo "Erreur : les outputs ne sont pas identiques"
	retvalue=1
fi

./a.out < input2 &> output.txt
echo "--- Expected ---"
cat expected.txt
echo "--- output ---"
cat output.txt
differences=$(diff output.txt expected2.txt)
if [ "$differences" = "" ]	
then
	echo "Test validé"
else
	echo "Erreur : les outputs ne sont pas identiques"
	retvalue=1
fi

exit "$retvalue"
