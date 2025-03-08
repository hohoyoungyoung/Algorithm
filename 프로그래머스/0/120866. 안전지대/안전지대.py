def solution(board):
    rows, cols = len(board), len(board[0])
    cache = [[0] * cols for _ in range(rows)]
    
    # 방향 벡터 (상, 하, 좌, 우, 대각선 4방향)
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1), 
                  (-1, -1), (-1, 1), (1, -1), (1, 1)]
    
    # 1이 있는 곳을 기준으로 주변을 모두 1로 설정
    for i in range(rows):
        for j in range(cols):
            if board[i][j] == 1:
                cache[i][j] = 1
                for dx, dy in directions:
                    ni, nj = i + dx, j + dy
                    if 0 <= ni < rows and 0 <= nj < cols:
                        cache[ni][nj] = 1
    
    # 0의 개수 세기
    zero_count = sum(row.count(0) for row in cache)
    
    return zero_count
