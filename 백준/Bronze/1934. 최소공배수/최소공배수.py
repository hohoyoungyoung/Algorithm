import math

n = int(input())

for i in range(n):
    a, b = map(int, input().split())
    print(math.lcm(a,b))