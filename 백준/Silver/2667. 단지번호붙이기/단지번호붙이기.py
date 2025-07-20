N = int(input())

maps = []
result = []

# 지도 입력
for _ in range(N):
    maps.append(input())

# 방문 여부 기록
visited = [[0] * N for _ in range(N)]

# 상하좌우 방향 설정
direction = [(-1, 0), (1, 0), (0, -1), (0, 1)]

# DFS 정의
def dfs(x, y):
    global count
    for dx, dy in direction:
        nx, ny = x + dx, y + dy
        if 0 <= nx < N and 0 <= ny < N:
            if maps[nx][ny] == '1' and visited[nx][ny] == 0:
                visited[nx][ny] = 1
                count += 1
                dfs(nx, ny)

# 전체 지도 순회
for i in range(N):
    for j in range(N):
        if maps[i][j] == '1' and visited[i][j] == 0:
            count = 1
            visited[i][j] = 1  # 시작점 방문 체크!
            dfs(i, j)
            result.append(count)

# 출력
print(len(result))         # 총 단지 수
for val in sorted(result): # 단지 내 집 수 오름차순 출력
    print(val)
