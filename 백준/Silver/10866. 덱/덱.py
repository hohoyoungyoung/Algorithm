from collections import deque


# 입력 받기
n = int(input())  
commands = [input() for i in range(n)] 

que = deque()

for command in commands:
    cmd = command.split()
    
    if cmd[0] == 'push_back':
        que.append(int(cmd[1]))
    
    elif cmd[0] == 'push_front':
        que.appendleft(int(cmd[1]))  # deque의 appendleft 사용
    
    elif cmd[0] == 'pop_front':
        print(que.popleft() if que else -1)
    
    elif cmd[0] == 'pop_back':
        print(que.pop() if que else -1)
    
    elif cmd[0] == 'size':
        print(len(que))
    
    elif cmd[0] == 'empty':
        print(1 if not que else 0)
    
    elif cmd[0] == 'front':
        print(que[0] if que else -1)
        
    elif cmd[0] == 'back':
        print(que[-1] if que else -1)