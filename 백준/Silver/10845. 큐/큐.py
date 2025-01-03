import sys
input = sys.stdin.readline

n = int(input())

que = []

for i in range(n):
    command = input().split()
    
    if command[0] == 'push':
        que.append(int(command[1]))
    
    if command[0] == 'pop':
        print(que[0]) if que else print(-1)
        que = que[1:]
        
    if command[0] == 'size':
        print(len(que))
        
    if command[0] == 'empty':
        print(0) if que else print(1)
        
    if command[0] == 'front':
        print(que[0]) if que else print(-1)
        
    if command[0] == 'back':
        print(que[-1]) if que else print(-1)