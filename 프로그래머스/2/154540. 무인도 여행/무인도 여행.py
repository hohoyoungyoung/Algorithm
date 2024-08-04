def solution(maps):
    answer = []
    
    row = len(maps)
    col = len(maps[0])
    
    dp = [[False]*col for _ in range(row)]
    
    direction = [(1,0), (-1,0), (0,1), (0,-1)]
    
    def search(m, n):
        stack = [(m, n)]
        total = 0
        
        while stack:
            x, y = stack.pop()
            if x < 0 or y < 0 or x >= row or y >= col or dp[x][y] or maps[x][y] == 'X':
                continue
            
            dp[x][y] = True
            total += int(maps[x][y])
            
            for dx, dy in direction:
                stack.append((x + dx, y + dy))
        
        return total
    
    for i in range(row):
        for j in range(col):
            if not dp[i][j] and maps[i][j] != 'X':
                island_value = search(i, j)
                if island_value > 0:
                    answer.append(island_value)
    
    if len(answer) == 0:
        return [-1]
    
    return sorted(answer)