import sys
sys.setrecursionlimit(10**6)  # 🔥 중요!

N, M, R = map(int, sys.stdin.readline().split())

adj = [[] for _ in range(N + 1)]

for _ in range(M):
    a, b = map(int, sys.stdin.readline().split())
    adj[a].append(b)
    adj[b].append(a)

for i in range(1, N + 1):
    adj[i].sort()

visited = [0] * (N + 1)
ans = [0] * (N + 1)
cnt = 0

def dfs(node):
    global cnt
    cnt += 1
    visited[node] = True
    ans[node] = cnt

    for neighbor in adj[node]:
        if not visited[neighbor]:
            dfs(neighbor)

dfs(R)

for i in range(1, N + 1):
    print(ans[i])
