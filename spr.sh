#!/bin/bash

#g++ -std=c++17 -o wzor wzor.cpp -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
#g++ -std=c++17 -o brut brut.cpp -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
g++ -std=c++17 -o wzor wzor.cpp -O2
g++ -std=c++17 -o brut brut.cpp -O2
g++ -std=c++17 -o gen gen.cpp -O2

for((i=1; i>0; i++))
do
    echo $i > ziarno
	./gen < ziarno > test.in
	./wzor < test.in > wzor.out
	./brut < test.in > brut.out
	if diff -b brut.out wzor.out > /dev/null
	then
		echo -ne "$i      \r"
	else
		echo "$i BLAD"
		break
	fi
done

rm ziarno