import heapq

N, E = map(int, input().split(' '))

adj = [[] for i in range(N+1)]
INF = float('inf')

for _ in range(E):
    a, b, c = map(int, input().split(' '))
    adj[a].append((b, c))
    adj[b].append((a, c))

def dijkstra(start):
    distance = [INF] * (N+1)
    distance[start] = 0
    heap = [(0,start)]

    while heap:
        dist, node = heapq.heappop(heap)

        if dist > distance[node]:
            continue
        
        for next_node, cost in adj[node]:
            if distance[next_node] > distance[node] + cost:
                distance[next_node] = distance[node] + cost
                heapq.heappush(heap, (distance[next_node], next_node))

    return distance

v1, v2 = map(int, input().split())  # 꼭 지나야 하는 두 정점

# 1 -> v1 -> v2 -> N
# 1 -> v2 -> v1 -> N
dist1 = dijkstra(1)
dist_v1 = dijkstra(v1)
dist_v2 = dijkstra(v2)

path1 = dist1[v1] + dist_v1[v2] + dist_v2[N]
path2 = dist1[v2] + dist_v2[v1] + dist_v1[N]

result = min(path1, path2)
print(result if result < INF else -1)
