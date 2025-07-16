N, K = map(int, input().split(' '))

dp = [0] * (K+1)
val_list = [0]

for i in range(N):

    weight, value = map(int, input().split(' '))
    
    for j in range(K,weight - 1,-1):  # j>=weight
        # 1. input weight를 넣을 수 있으면        
        dp[j] = max(dp[j], dp[j-weight] + value)


print(dp[-1])
