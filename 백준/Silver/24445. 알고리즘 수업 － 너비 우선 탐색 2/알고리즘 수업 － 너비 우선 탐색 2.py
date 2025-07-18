from collections import deque
import sys
input = sys.stdin.readline

N, M, R = map(int, input().split())

adj = [[] for _ in range(N + 1)]
for _ in range(M):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

for i in range(1, N + 1):
    adj[i].sort(reverse=True)

visited = [0] * (N + 1)
cnt = 1

def bfs(R):
    global cnt
    deq = deque([R])
    visited[R] = cnt

    while deq:
        num = deq.popleft()
        for i in adj[num]:
            if not visited[i]:
                cnt += 1
                visited[i] = cnt
                deq.append(i)

bfs(R)

for i in range(1, N + 1):
    print(visited[i])