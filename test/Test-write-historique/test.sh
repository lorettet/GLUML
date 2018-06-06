#!/bin/bash

make
date=$(date +'%d/%m/%Y')
echo -e "$date;7;1;A2:29.0;A3:94.0;A4:158.0;A1:TF\nM1:25.2;M2:27.4\n$date;8;2;A2:19.5;A3:120.0;A4:155.4;A1:AA\nM1:88.0;M2:34.8\n$date;9;3;A2:47.3;A3:-110.6;A4:159.3;A1:ZZ\nM2:38.0" > file/historiqueReel.txt


./a.out &> /dev/null
echo "--- Expected ---"
cat file/historiqueReel.txt
echo "--- output ---"
cat file/historique.txt
differences=$(diff file/historiqueReel.txt file/historique.txt)
if [ "$differences" = "" ]	
then
	echo "Test validé"
	exit 0
else
	echo "Erreur : les outputs ne sont pas identiques"
	exit 1
fi

