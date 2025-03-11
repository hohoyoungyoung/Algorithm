def solution(n):
    # Step 1: 삼각형 리스트 만들기
    triangle = [[0] * (i + 1) for i in range(n)]

    # Step 2: 숫자 채우기
    x, y = -1, 0  # 초기 위치
    num = 1  # 채울 숫자
    directions = [(1, 0), (0, 1), (-1, -1)]  # 아래 → 오른쪽 → 위 대각선 순서
    d = 0  # 현재 방향 (0부터 시작)

    
    for i in range(n, 0, -1):  # n, n-1, ..., 1 만큼 반복
        for _ in range(i):
            x += directions[d][0]
            y += directions[d][1]
            triangle[x][y] = num
            num += 1
        d = (d + 1) % 3  # 방향 전환

    # Step 3: 1차원 배열로 변환
    return sum(triangle, [])  # 2차원 리스트를 1차원 리스트로 변환