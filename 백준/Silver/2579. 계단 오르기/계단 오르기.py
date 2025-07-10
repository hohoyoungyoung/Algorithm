N = int(input())

stairs = [int(input()) for i in range(N)]

dp = [0] * N

if N == 1:
    print(stairs[0])
elif N == 2:
    print(stairs[0] + stairs[1])
elif N == 3:
    print(max(stairs[1]+stairs[2], stairs[0]+stairs[2]))

else:
    dp[0] = stairs[0]
    dp[1] = stairs[0] + stairs[1]
    dp[2] = max(stairs[1]+stairs[2], stairs[0]+stairs[2])

    for i in range(3, N):
        dp[i] = max(dp[i-3]+stairs[i-1]+stairs[i], dp[i-2]+stairs[i])

    print(dp[-1])