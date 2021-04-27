#!/bin/bash
# $1 - MAXN
# $2 - testowany program

cp "$2" sol.cpp
make sol

for (( i=0; i < 1000000; i++)) ; do
    echo test $i
    echo $i $1 | ./gen > t.in
    ./slow < t.in > t.out
    ./sol < t.in | cmp t.out
    if [ $? -ne 0 ] ; then
        break
    fi
done
