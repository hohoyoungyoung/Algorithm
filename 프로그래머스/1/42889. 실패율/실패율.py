from collections import Counter

def solution(N, stages):
    answer = []
    stage_counts = Counter(stages)  # 각 스테이지에 있는 사용자 수 카운트
    denominator = len(stages)  # 전체 사용자 수
    
    for i in range(1, N + 1):  # 1부터 N까지 반복
        numerator = stage_counts[i] if i in stage_counts else 0  # 스테이지 i에 있는 사용자 수
        
        if denominator == 0:  # 스테이지에 도달한 사람이 없다면 실패율 0
            failure_rate = 0
        else:
            failure_rate = numerator / denominator  # 실패율 계산
        
        answer.append((failure_rate, i))  # (실패율, 스테이지 번호) 저장
        denominator -= numerator  # 현재 스테이지의 인원을 제외
    
    # 실패율 내림차순, 스테이지 번호 오름차순 정렬
    return [stage for _, stage in sorted(answer, key=lambda x: (-x[0], x[1]))]
