def solution(x, n):
    
    answer = []
    cache = 0
    
    for i in range(n):
        cache += x
        answer.append(cache)
    
    return answer