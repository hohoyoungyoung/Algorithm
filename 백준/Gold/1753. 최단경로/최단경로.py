import heapq
import sys

input = sys.stdin.readline
INF = float('inf')

V, E = map(int, input().split())
K = int(input())

adj = [[] for _ in range(V + 1)]

for _ in range(E):
    u, v, w = map(int, input().split())
    adj[u].append((v, w))


def dijkstra(start):
    distance = [INF] * (V + 1)
    distance[start] = 0  
    heap = [(0, start)]

    while heap:
        dist, now = heapq.heappop(heap)

        if dist > distance[now]:
            continue

        for nxt, cost in adj[now]:
            new_dist = dist + cost
            if new_dist < distance[nxt]:
                distance[nxt] = new_dist
                heapq.heappush(heap, (new_dist, nxt))

    return distance


distance = dijkstra(K)

for i in range(1, V + 1):
    print("INF" if distance[i] == INF else distance[i])
