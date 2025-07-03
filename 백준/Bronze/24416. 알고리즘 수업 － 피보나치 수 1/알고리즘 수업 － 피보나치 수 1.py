# 재귀 계산 횟수 카운팅용
count1 = 0
def fib(n):
    global count1
    if n == 1 or n == 2:
        return 1
    count1 += 1
    fib(n-1)
    fib(n-2)

# DP 계산 횟수 카운팅용
count2 = 0
def fib2(n):
    global count2
    dp = [0] * (n+1)
    dp[1], dp[2] = 1, 1
    for i in range(3, n+1):
        count2 += 1
        dp[i] = dp[i-1] + dp[i-2]

n = int(input())
fib(n)
fib2(n)
print(count1 + 1, count2)  # ← 핵심: count1은 fib(n-1)+fib(n-2) 사용 횟수. 시작점은 1회로 쳐줘야 함
