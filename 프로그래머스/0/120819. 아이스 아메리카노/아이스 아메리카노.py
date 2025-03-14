def solution(money):
    answer = 0
    
    if money < 5500:
        return [0, money]
    
    while True:
        money -= 5500
        answer += 1
        if money < 5500:
            return [answer, money]
            
    