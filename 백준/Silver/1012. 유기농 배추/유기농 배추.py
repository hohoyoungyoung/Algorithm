import sys
sys.setrecursionlimit(10**6)

T = int(input())

def dfs(row, col):
    for a, b in direction:
        ncol, nrow = col + a, row + b
        if (0 <= ncol < M) and (0 <= nrow < N) and (maps[nrow][ncol] == 1) and (visited[nrow][ncol] == 0):
            visited[nrow][ncol] = 1
            dfs(nrow, ncol)

for _ in range(T):
    M, N, K = map(int, input().split())
    maps = [[0]*M for _ in range(N)]
    visited = [[0]*M for _ in range(N)]
    direction = [(-1,0), (0,-1), (1,0), (0,1)]

    for _ in range(K):
        X, Y = map(int, input().split())
        maps[Y][X] = 1

    cnt = 0
    for i in range(N):
        for j in range(M):
            if visited[i][j] == 0 and maps[i][j] == 1:
                visited[i][j] = 1
                dfs(i, j)
                cnt += 1

    print(cnt)
