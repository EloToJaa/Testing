#!/bin/bash
# $1 - MAXN

for (( i=0; i < 1000000; i++)) ; do
    echo test $i
    echo $i $1 | ./gen > t.in 2>t.out
    ./sol < t.in | cmp t.out
    if [ $? -ne 0 ] ; then
        break
    fi
done
