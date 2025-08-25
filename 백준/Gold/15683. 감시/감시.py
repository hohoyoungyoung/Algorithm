import sys
from copy import deepcopy
input = sys.stdin.readline

# 방향: 우, 좌, 상, 하
dirs = [(0,1),(0,-1),(-1,0),(1,0)]

# CCTV 타입별 가능한 방향 묶음
cctv_dirs = {
    1: [[0],[1],[2],[3]],
    2: [[0,1],[2,3]],
    3: [[0,2],[0,3],[1,2],[1,3]],
    4: [[0,1,2],[0,1,3],[0,2,3],[1,2,3]],
    5: [[0,1,2,3]]
}

def watch(board, x, y, dirset):
    n, m = len(board), len(board[0])
    for d in dirset:
        nx, ny = x, y
        while True:
            nx += dirs[d][0]
            ny += dirs[d][1]
            if not (0 <= nx < n and 0 <= ny < m): break
            if board[nx][ny] == 6: break  # 벽
            if board[nx][ny] == 0:
                board[nx][ny] = '#'

def dfs(idx, board):
    global ans
    if idx == len(cctvs):
        blind = sum(row.count(0) for row in board)
        ans = min(ans, blind)
        return

    t, x, y = cctvs[idx]
    for dirset in cctv_dirs[t]:
        new_board = deepcopy(board)
        watch(new_board, x, y, dirset)
        dfs(idx+1, new_board)

# 입력 처리
N, M = map(int, input().split())
board = []
cctvs = []
for i in range(N):
    row = list(map(int, input().split()))
    for j in range(M):
        if 1 <= row[j] <= 5:
            cctvs.append((row[j], i, j))
    board.append(row)

ans = 64  # 최대 사각지대는 8*8=64
dfs(0, board)
print(ans)
