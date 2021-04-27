#!/bin/bash
# $1 - MAXN
# $2 - testowany program

for (( i=0; i < 1000000; i++)) ; do
    echo test $i
    echo $i $1 | ./gen > t.in
    ./slow < t.in > t.out
    ./$2 < t.in > t.sol
    echo t.in t.out t.sol | ./checker 
    if [ $? -ne 0 ] ; then
        break
    fi
done
