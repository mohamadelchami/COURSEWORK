#!/bin/sh

PATTERN="$1"

shift 

for arg in "$@"; 
do
	if echo $arg | grep $PATTERN >/dev/null 2>&1; then
        	echo "yes"
	else
        	echo "no"
	fi
done

