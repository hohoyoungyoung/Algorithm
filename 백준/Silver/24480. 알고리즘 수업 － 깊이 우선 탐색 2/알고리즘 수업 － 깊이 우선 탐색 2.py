import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline  # ✅ 빠른 입력 처리

N, M, R = map(int, input().split())

adj = [[] for _ in range(N+1)]

for _ in range(M):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)

for i in range(1, N+1):
    adj[i].sort(reverse=True)  # 내림차순으로 정점 방문

visited = [0] * (N+1)
cnt = 1

def dfs(start):
    global cnt
    visited[start] = cnt
    for num in adj[start]:
        if not visited[num]:
            cnt += 1
            dfs(num)

dfs(R)

for i in range(1, N+1):
    print(visited[i])
