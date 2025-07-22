from collections import deque

N, M = map(int, input().split())
maps = [list(map(int, list(input().strip()))) for _ in range(N)]

# 이동 방향 (상, 하, 좌, 우)
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

# BFS 함수
def bfs(x, y):
    queue = deque()
    queue.append((x, y))

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            # 범위를 벗어났다면 무시
            if nx < 0 or nx >= N or ny < 0 or ny >= M:
                continue

            # 벽이거나 이미 방문했다면 무시
            if maps[nx][ny] == 0:
                continue

            # 처음 방문하는 곳이면 이전 값 + 1
            if maps[nx][ny] == 1:
                maps[nx][ny] = maps[x][y] + 1
                queue.append((nx, ny))

    return maps[N-1][M-1]  # 도착 지점의 값이 곧 최소 칸 수

print(bfs(0, 0))
