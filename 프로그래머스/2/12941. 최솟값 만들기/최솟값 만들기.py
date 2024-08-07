def solution(A,B):
    
    A_s = sorted(A)
    B_s = sorted(B)
    A_r = sorted(A, reverse=True)
    B_r = sorted(B, reverse=True)

    answer_1 = 0
    answer_2 = 0
    
    for i in range(len(B)):
        answer_1 += A_s[i] * B_r[i]
    
    for i in range(len(B)):
        answer_2 += A_r[i] * B_s[i]
        
    return min(answer_1,answer_2)