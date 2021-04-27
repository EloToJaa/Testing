from os import system as cmd, listdir

def read_file(file_name):
    with open(file_name, "r") as f:
        #return [[int(x) for x in line.split()] for line in f]
        #return [int(x) for x in f]
        return f.read()

in_folder = "in/"
out_folder = "out/"
ins = listdir(in_folder)
outs = listdir(out_folder)

cmd("g++ wzor.cpp -o wzor -std=c++17")

zle = 0
dobrze = 0

for i in range(min(len(ins), len(outs))):
    in_f = in_folder + ins[i]
    out_f = out_folder + outs[i]

    noty = ["5","6","7","8", "9", "10", "11"]
    skip = False
    for liczba in noty:
        if liczba in in_f:
            skip = True
    
    if skip:
        continue
    
    print(ins[i], outs[i])

    cmd("./wzor < " + in_f + " > wzor.out")

    wzor = read_file("wzor.out")
    brut = read_file(out_f)

    if wzor != brut:
        zle += 1
    else:
        dobrze += 1

print("Raport:")
print(dobrze, "/", zle + dobrze)
