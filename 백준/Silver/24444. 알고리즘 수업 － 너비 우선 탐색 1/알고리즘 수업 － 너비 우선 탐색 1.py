from collections import deque
import sys
input = sys.stdin.readline

N, M, R = map(int, input().split(' '))

adj = [[] for i in range(N+1)]

for i in range(M):
    u, v = map(int, input().split(' '))
    adj[u].append(v)
    adj[v].append(u)


visited = [0] * (N+1)
deq = deque([])
cnt = 1

def bfs(R):
    deq.append(R)
    global cnt
    visited[R] = cnt
    while deq:
        num = deq.popleft()
        adj[num].sort()
        for i in adj[num]:
            if not visited[i]:
                cnt += 1
                visited[i] = cnt
                deq.append(i)

bfs(R)

for i in range(1, len(visited)):
    print(visited[i])