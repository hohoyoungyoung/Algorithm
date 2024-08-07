def solution(s):
    answer=''
    list = sorted(s, reverse=True)
    for i in range(len(list)):
        answer += list[i]
    return answer