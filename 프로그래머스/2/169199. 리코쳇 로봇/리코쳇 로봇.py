from collections import deque

def solution(board):
    row = len(board)
    col = len(board[0])
    

    for i in range(row):
        for j in range(col):
            if board[i][j] == 'R':
                s_x, s_y = i, j
            elif board[i][j] == 'G':
                e_x, e_y = i, j
    

    queue = deque([(s_x, s_y, 0)]) 
    visited = set((s_x, s_y))
    
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]  
    
    while queue:
        x, y, move_count = queue.popleft()
        
        if (x, y) == (e_x, e_y):
            return move_count
        
        for dx, dy in directions:
            nx, ny = x, y
            

            while 0 <= nx + dx < row and 0 <= ny + dy < col and board[nx + dx][ny + dy] != 'D':
                nx += dx
                ny += dy
            
            if (nx, ny) not in visited:
                visited.add((nx, ny))
                queue.append((nx, ny, move_count + 1))
    
    return -1  