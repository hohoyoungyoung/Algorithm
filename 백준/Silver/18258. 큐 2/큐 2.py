import sys
from collections import deque

input = sys.stdin.readline

N = int(input())
que = deque()

for _ in range(N):
    order = input().strip()  
    
    if order.startswith('push'):
        _, b = order.split()
        que.append(int(b))
    
    elif order == 'pop':
        print(que.popleft() if que else -1)
    
    elif order == 'size':
        print(len(que))
    
    elif order == 'empty':
        print(1 if len(que) == 0 else 0)

    elif order == 'front':
        print(que[0] if que else -1)

    elif order == 'back':
        print(que[-1] if que else -1)
