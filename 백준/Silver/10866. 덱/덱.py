from collections import deque
import sys

input = sys.stdin.read  # 한꺼번에 다 읽어 오는거라...

# 입력 받기
data = input().splitlines()
n = int(data[0])  # 첫 번째 줄: 명령의 개수
commands = data[1:]  # 나머지 줄: 명령어들

que = deque()

for command in commands:
    cmd = command.split()
    
    if cmd[0] == 'push_back':
        que.append(int(cmd[1]))
    
    elif cmd[0] == 'push_front':
        que.insert(0, int(cmd[1]))
    
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
