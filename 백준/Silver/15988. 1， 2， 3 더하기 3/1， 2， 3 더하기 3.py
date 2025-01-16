MOD = 1000000009

# 미리 최대 n까지 dp 계산
max_n = 1000000  # n의 최대값을 적절히 설정
dp = [0] * (max_n + 1)
dp[1], dp[2], dp[3] = 1, 2, 4

for i in range(4, max_n + 1):
    dp[i] = (dp[i-3] + dp[i-2] + dp[i-1]) % MOD

# 테스트 케이스 처리
for _ in range(int(input())):
    n = int(input())
    print(dp[n])
