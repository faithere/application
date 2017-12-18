#!/bin/bash
echo "Input word1:"
read word1
echo "Input word2:"
read word2

if test "$word1" == "$word2"
    then
        echo "Match case"
fi
           
echo "End of Program"

if test $# -eq 0
then 
    echo "You must input at leaset one paramter"
fi
