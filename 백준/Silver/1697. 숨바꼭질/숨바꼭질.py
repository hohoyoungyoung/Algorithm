from collections import deque

def bfs(N, K):
    max_size = 100001
    visited = [False] * max_size
    queue = deque()
    queue.append((N, 0))  # (현재 위치, 시간)

    while queue:
        x, t = queue.popleft()
        if x == K:
            return t

        for nx in (x - 1, x + 1, x * 2):
            if 0 <= nx < max_size and not visited[nx]:
                visited[nx] = True
                queue.append((nx, t + 1))

N, K = map(int, input().split())
print(bfs(N, K))
