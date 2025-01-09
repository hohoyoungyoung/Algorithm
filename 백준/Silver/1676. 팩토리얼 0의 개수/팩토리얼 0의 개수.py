import math


def factorial_0(n):
    
    i = 1
    
    while math.factorial(n) % 10**i == 0:
        i += 1

    return i-1

print(factorial_0(int(input())))