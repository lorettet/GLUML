#!/bin/bash

make

i=1
retvalue=0
while [ $i -le 4 ]
do
	echo "### test $i ###"
	./a.out < input$i > output.txt
	echo "--- Expected ---"
	cat expected$i.txt
	echo "--- output ---"
	cat output.txt
	differences=$(diff output.txt expected$i.txt)
	if [ "$differences" = "" ]	
	then
		echo "Test validé"
	else
		echo "Erreur : les outputs ne sont pas identiques"
		retvalue=1
	fi
	let "i=i+1"
done
exit "$retvalue"
