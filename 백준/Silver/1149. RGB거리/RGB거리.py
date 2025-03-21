# 양 옆 걍 다다르게 앞에서 index 0 쓰면 뒤에는 1,2 중골라야 하는듯

n = int(input())

cost = []
minCost = -int(1e9)
dp = [[0]*3 for _ in range(n)]
for i in range(n):
    cost.append(list(map(int, input().split())))
    
dp[0][0], dp[0][1], dp[0][2] = cost[0][0], cost[0][1], cost[0][2]

for i in range(n):
    dp[i][0] = (
        min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0]
    )
    dp[i][1] = (
        min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1]
    )
    dp[i][2] = (
        min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2]
    )

print(min(dp[-1]))