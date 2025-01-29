N = int(input())

dp = [1, 1, 1]  # 초기 값 설정

if N == 1:
    print(sum(dp) % 9901)
    exit()

for i in range(2, N + 1):
    a, b, c = dp[0], dp[1], dp[2]
    dp[0] = (a + b + c) % 9901
    dp[1] = (a + c) % 9901
    dp[2] = (a + b) % 9901

print(sum(dp) % 9901)