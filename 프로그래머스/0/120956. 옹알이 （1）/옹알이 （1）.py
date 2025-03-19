import re

def solution(babbling):
    pattern = re.compile(r'^(aya|ye|woo|ma)+$')  # 허용된 단어로만 구성된지 체크
    forbidden_pattern = re.compile(r'(ayaaya|yeye|woowoo|mama)')  # 연속된 같은 단어 금지

    count = 0
    for word in babbling:
        if forbidden_pattern.search(word):  # 연속된 같은 단어가 포함된 경우 건너뜀
            continue
        if pattern.match(word):  # 허용된 단어만으로 구성된 경우 카운트 증가
            count += 1
            
    return count