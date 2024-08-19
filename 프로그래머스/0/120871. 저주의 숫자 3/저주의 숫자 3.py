# 정답은 n보다 커야함

def solution(n):
    
    # 3x -> i
    i = 0
    # j -> 10진법 
    j = 0
    
    while j != n:
        i += 1
        
        if not '3' in str(i) and not i%3 == 0:
            j += 1
        

    
    
    return i
        