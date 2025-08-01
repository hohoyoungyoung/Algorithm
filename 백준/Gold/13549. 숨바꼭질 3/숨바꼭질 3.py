from collections import deque

N, K = map(int, input().split())
INF = int(1e9)
distance = [-1] * 100001
distance[N] = 0

dq = deque()
dq.append(N)

while dq:
    pos = dq.popleft()

    for next_pos, cost in [(pos * 2, 0), (pos - 1, 1), (pos + 1, 1)]:
        if 0 <= next_pos <= 100000:
            if distance[next_pos] == -1 or distance[next_pos] > distance[pos] + cost:
                distance[next_pos] = distance[pos] + cost
                if cost == 0:
                    dq.appendleft(next_pos)
                else:
                    dq.append(next_pos)

print(distance[K])
