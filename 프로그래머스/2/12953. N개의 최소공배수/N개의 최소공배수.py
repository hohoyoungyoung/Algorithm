import math

def lcm(a, b):
    return a * b // math.gcd(a, b)


def solution(arr):
    
    a = 1 
    for i in range(len(arr)):
        a = lcm(a, arr[i])
    
    return a