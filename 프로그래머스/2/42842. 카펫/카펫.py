def solution(brown, yellow):
    carpet_size = brown + yellow
    g = 3  # 최소 가로 크기 (yellow 최소값이 1일 때, 전체는 3x3)
    
    while True:
        # s(세로)는 g를 기준으로 계산하여 설정
        if carpet_size % g == 0:  # 전체 크기가 나누어 떨어져야 함
            s = carpet_size // g  # 세로 크기 결정

            # 조건 확인 (노란색 영역과 가로-세로 조건 검증)
            if (g - 2) * (s - 2) == yellow and g >= s:
                return [g, s]

        g += 1  # 가로를 1씩 증가시키면서 탐색