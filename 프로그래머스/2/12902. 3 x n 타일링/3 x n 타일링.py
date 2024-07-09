def solution(n):
    if n % 2 != 0:
        return 0
    
    dp = [0] * 5001
    
    dp[2] = 3
    dp[4] = 11
    dp[6] = 41
    dp[8] = 153
    
    for i in range(10, n + 1, 2):
        dp[i] = dp[i-2] * 4 - dp[i-4]


    return dp[n] % 1000000007