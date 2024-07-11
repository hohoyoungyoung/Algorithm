# 최저 택시요금 return

def solution(n, s, a, b, fares):
    
    dp = [[float('inf') for _ in range(n+1)] for _ in range(n+1)]
    
    for i in range(1, n+1):
        dp[i][i] = 0
        
    for fare in fares:
        u, v, w = fare
        dp[u][v] = w
        dp[v][u] = w

    # k, i, j 위치 때문에 애먹었다... 순서가 왜 이렇게 되는지 기억.
    
    for k in range(1, n+1):
        for i in range(1, n+1):
            for j in range(1, n+1):
                if dp[i][j] > dp[i][k] + dp[k][j]:
                    dp[i][j] = dp[i][k] + dp[k][j]
    
    answer = float('inf')
    
    for t in range(1, n+1):
        answer = min(answer, dp[s][t] + dp[t][a] + dp[t][b])
    
    
    return answer
