N = int(input())

def ans(num):

    if num in [1,2,3]:
        return 1
    
    dp = [0] * num

    dp[0], dp[1], dp[2] = 1, 1, 1

    for i in range(3, num):
        dp[i] = dp[i-2] + dp[i-3]
    
    return dp[num-1]

for i in range(N):
    print(ans(int(input())))