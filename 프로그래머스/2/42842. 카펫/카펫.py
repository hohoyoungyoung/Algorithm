# 전체 카펫 크기 = yellow + brown
# (가로 - 2) × (세로 - 2) = yellow (노랑 영역 크기)
# 가로 * 세로 = brown + yellow (전체 영역)
# 가로 >= 세로 조건 만족
    
def solution(brown, yellow):
    total = brown + yellow  
    
    for h in range(1, int(yellow**0.5) + 1):  # yellow의 약수 찾기
        if yellow % h == 0:
            w = yellow // h  # 가로, 세로 설정
            
            # 실제 카펫 크기 계산 (갈색 타일 포함)
            if (w + 2) * (h + 2) == total:
                return [w + 2, h + 2]  # [가로, 세로]

    return []


        