import math

n = int(input())

i = 2
j = 0

while( i*i <= n and j != 1 ):
    if n % i == 0:
        j =1
    i += 1    
if j == 1:
    print("Составное число")
else:
    print("Простое число")