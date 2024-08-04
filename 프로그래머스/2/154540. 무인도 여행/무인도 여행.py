# 무인도 dp table 만들어서 방문지점 메모하고 dfs 하면 될듯? 

def solution(maps):
    
    answer = []
    
    row = len(maps)
    col = len(maps[0])
    
    dp = [[False]*col for i in range(row)]
    
    direction = [(1,0),(-1,0),(0,1),(0,-1)]
    
    # m, n이 좌표로 들어간다고 하면~

    def search(m,n):
         
        stack = [(m,n)]
        cache = 0
        
        while stack:
            m,n = stack.pop()
            
            if (m < 0) or (n < 0) or (m > row-1) or (n > col-1) or (dp[m][n] == True) or (maps[m][n] == 'X'):
                continue


            cache += int(maps[m][n])
            dp[m][n] = True

            for i in range(4):
                x,y = direction[i]
                stack.append((m+x, n+y))

        return cache
        
        
    for i in range(row):
        for j in range(col):
            if dp[i][j] == False:
                cache1 = 0
                cache1 += search(i,j)
                if cache1 != 0:
                    answer.append(cache1)
    
    if len(answer) == 0:
        return [-1]
    
    return sorted(answer)
