# dp[a][b][c]의 값을 저장할 3차원 리스트
dp = [[[0]*21 for _ in range(21)] for _ in range(21)]

def w(a, b, c):
    # 기저 조건
    if a <= 0 or b <= 0 or c <= 0:
        return 1
    
    # 20 초과는 20으로 고정
    if a > 20 or b > 20 or c > 20:
        return w(20, 20, 20)

    # 이미 계산된 값이 있다면 그 값을 반환
    if dp[a][b][c] != 0:
        return dp[a][b][c]

    # 점화식 계산 및 저장
    if a < b and b < c:
        dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
    else:
        dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)

    return dp[a][b][c]


# 입력 처리
while True:
    a, b, c = map(int, input().split())
    if a == -1 and b == -1 and c == -1:
        break
    print(f"w({a}, {b}, {c}) = {w(a, b, c)}")
