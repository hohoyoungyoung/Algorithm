import heapq

N, K = map(int, input().split(' '))
INF = float('inf')
distance = [INF] * 100001

if N >= K:
    print(N-K)
else:
    heap = [(0, N)]
    distance[N] = 0

    while heap:
        time, pos = heapq.heappop(heap)

        for next_pos, cost in [(pos*2, 0), (pos-1, 1), (pos+1, 1)]:
            if (0<=next_pos<=100000):
                if (distance[next_pos] > time + cost):
                    distance[next_pos] = time + cost
                    heapq.heappush(heap, (distance[next_pos], next_pos))

    print(distance[K])