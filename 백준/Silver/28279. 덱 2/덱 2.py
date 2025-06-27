import sys
input = sys.stdin.readline

from collections import deque

N = int(input())

que = deque()

for i in range(N):
    order = input().strip()

    if order.startswith('1'):
        que.appendleft(int(order[2:]))
    elif order.startswith('2'):
        que.append(int(order[2:]))
    elif order == '3':
        print(que.popleft() if que else -1)
    elif order == '4':
        print(que.pop() if que else -1)
    elif order == '5':
        print(len(que))
    elif order == '6':
        print(0 if que else 1)
    elif order == '7':
        print(que[0] if que else -1)
    else:
        print(que[-1] if que else -1)



    

