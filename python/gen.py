from numpy.random import randint as rand, choice
#print(*rand(10, 20, n))

n = rand(1, 101)
d = rand(1, n+1)
p = rand(1, n * 7)

print(n, p, d)
print(*rand(1, 11, n))