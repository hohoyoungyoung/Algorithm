# 메모리 초과

N = int(input())

dp = [0, 0, 0]
dp[0], dp[1], dp[2] = 1, 1, 1 

for i in range(2, N+1):
    a, b, c = dp[0], dp[1], dp[2]
    dp[0] = a+b+c
    dp[1] = a+c
    dp[2] = a+b
    
print(sum(dp)%9901)