def solution(dots):
    # 두 선분의 기울기가 같은지 확인하는 함수
    def is_parallel(p1, p2, p3, p4):
        x1, y1 = p1
        x2, y2 = p2
        x3, y3 = p3
        x4, y4 = p4
        # 기울기를 곱셈 형태로 비교하여 정확히 판별
        return (y2 - y1) * (x4 - x3) == (y4 - y3) * (x2 - x1)
    
    # 주어진 4개의 점
    a, b, c, d = dots
    
    # 3가지 경우의 기울기 비교
    if is_parallel(a, b, c, d):  # 케이스 1
        return 1
    if is_parallel(a, c, b, d):  # 케이스 2
        return 1
    if is_parallel(a, d, b, c):  # 케이스 3
        return 1
    
    return 0  # 평행하지 않으면 0
