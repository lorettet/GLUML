#!/bin/bash

i=0
valid=0
error=0
for test in Test-*
do
	let "i=i+1"
	echo "############## TEST : $test #################"
	cd $test
	./test.sh
	if [ $? != 0 ]
	then
		let "error=error+1"
	else
		let "valid=valid+1"
	fi
	cd ..
done
echo "############### COMPTE RENDU #################"
echo "Tests validés : $valid"
echo "Tests non-validés : $error"
