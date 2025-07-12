N = int(input())

wire = []

for i in range(N):
    a, b = map(int, input().split(' '))

    wire.append([a,b])


wire.sort()


for i in range(N):
    wire[i] = wire[i][1]


def LIS(seq):

    dp = [1] * len(seq)
    dp[0] = 1

    for i in range(1, len(seq)):

        for j in range(0, i):

            if seq[j] < seq[i]:
                dp[i] = max(dp[i], dp[j]+1)

    return max(dp)

print(N - LIS(wire))