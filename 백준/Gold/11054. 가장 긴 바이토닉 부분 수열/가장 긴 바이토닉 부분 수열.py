N = int(input())
A = list(map(int, input().split()))

# LIS 구하기
inc = [1] * N
for i in range(N):
    for j in range(i):
        if A[j] < A[i]:
            inc[i] = max(inc[i], inc[j] + 1)

# LDS 구하기
dec = [1] * N
for i in range(N-1, -1, -1):
    for j in range(N-1, i, -1):
        if A[j] < A[i]:
            dec[i] = max(dec[i], dec[j] + 1)

# 바이토닉 최대 길이
max_len = 0
for i in range(N):
    max_len = max(max_len, inc[i] + dec[i] - 1)

print(max_len)
