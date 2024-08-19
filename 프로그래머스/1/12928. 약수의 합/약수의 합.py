def solution(n):
    
    ans_l = []
    
    for i in range(1, n+1):
        if n % i == 0:
            ans_l.append(i)
    
    
    return sum(ans_l)