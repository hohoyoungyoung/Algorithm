def solution(triangle):
    
    dp = [[0] * (i+1) for i in range(len(triangle))]
    
    for k in range(len(triangle[len(triangle)-1])):
        dp[len(triangle)-1][k] = triangle[len(triangle)-1][k]
        
    for i in range(len(triangle)-1,-1,-1):
        for j in range(len(triangle[i])-1):
                dp[i-1][j] = triangle[i-1][j] + max(dp[i][j], dp[i][j+1]) 

    return dp[0][0]