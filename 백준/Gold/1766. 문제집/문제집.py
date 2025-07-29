import heapq
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
adj = [[] for _ in range(N + 1)]
indegree = [0] * (N + 1)

# 입력으로 주어진 간선만 추가
for _ in range(M):
    a, b = map(int, input().split())
    adj[a].append(b)
    indegree[b] += 1

# 우선순위 큐 (번호가 낮은 문제 먼저)
heap = []
for i in range(1, N + 1):
    if indegree[i] == 0:
        heapq.heappush(heap, i)

result = []

while heap:
    now = heapq.heappop(heap)
    result.append(str(now))

    for nxt in adj[now]:
        indegree[nxt] -= 1
        if indegree[nxt] == 0:
            heapq.heappush(heap, nxt)

print(' '.join(result))
