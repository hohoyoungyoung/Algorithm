from collections import deque

N, M = map(int, input().split(' '))

adj = [[] for i in range(N+1)]
indegree = [0] * (N+1)

for i in range(M):

    a, b = map(int, input().split(' '))
    
    adj[a].append(b)
    indegree[b] += 1


q = deque()
result = []

for i in range(1, N+1):
    if indegree[i] == 0:
        q.append(i)

while q:
    now = q.popleft()
    result.append(now)

    for nxt in adj[now]:
        indegree[nxt] -= 1
        if indegree[nxt] == 0:
            q.append(nxt)


print(*result)