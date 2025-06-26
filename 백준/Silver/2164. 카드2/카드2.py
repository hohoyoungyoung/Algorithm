from collections import deque 

N = int(input())

wait = [i for i in range(1, N+1)]

wait = deque(wait)

while len(wait) != 1:
    wait.popleft()
    wait.append(wait.popleft())


print(wait[0])