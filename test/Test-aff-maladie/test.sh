#!/bin/bash

make
./a.out < input > output.txt
echo "--- Expected ---"
cat expected.txt
echo "--- output ---"
cat output.txt
differences=$(diff output.txt expected.txt)
if [ "$differences" = "" ]	
then
	echo "Test validé"
	exit 0
else
	echo "Erreur : les outputs ne sont pas identiques"
	exit 1
fi

