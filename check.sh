#!/bin/bash

#g++ -std=c++17 -o wzor wzor.cpp -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
#g++ -std=c++17 -o brut brut.cpp -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
g++ -std=c++17 -o check check.cpp -O2
g++ -std=c++17 -o gen2 gen2.cpp -O2

for((i=1; i>0; i++))
do
    echo $i > ziarno2
	./gen < ziarno2 > test2.in
	./check < test2.in > check.out
	if diff -b check.out to.out > /dev/null
	then
		echo -ne "$i      \r"
	else
		echo "$i BLAD"
		break
	fi
done

rm ziarno2