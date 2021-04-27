# jezeli pliki wejscia/wyjscia sa w jednym folderze
from os import system as cmd, listdir, mkdir, rmdir
from shutil import move

dir_name = input("Podaj nazwe folderu z testami: ")
in_dir = "in/"
out_dir = "out/"
f_dir = dir_name + "/"
out_ext = ".out"
in_ext = ".in"

files = listdir(f_dir)
outs = [f for f in files if out_ext in f]
ins = [f for f in files if in_ext in f]

mkdir(in_dir)
mkdir(out_dir)

for f in outs:
    move(f_dir + f, out_dir + f)

for f in ins:
    move(f_dir + f, in_dir + f)

rmdir(f_dir)