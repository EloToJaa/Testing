from os import system as cmd

def read_file(file_name):
    with open(file_name, "r") as f:
        #return [[int(x) for x in line.split()] for line in f]
        #return [int(x) for x in f]
        return f.read()

cmd("g++ -std=c++17 -Wshadow -Wall -o wzor wzor.cpp -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG")
cmd("g++ -std=c++17 -Wshadow -Wall -o brut brut.cpp -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG")

n = int(input("Podaj liczbe testow: "))
for i in range(n):
    print(i)

    cmd("python3 gen.py > wzor.in")
    cmd("./brut < wzor.in > brut.out")
    cmd("./wzor < wzor.in > wzor.out")
    
    brut = read_file("brut.out")
    wzor = read_file("wzor.out")

    if wzor != brut:
        print("Error")
        break
    #print(i, ": ", *read_file("wzor.out"))