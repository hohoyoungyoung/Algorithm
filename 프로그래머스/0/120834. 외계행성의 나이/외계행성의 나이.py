def solution(age):
    answer = ''
    str_age = str(age)
    # chr(97) = a
    
    
    for number in str_age:
        answer += chr(int(number) + 97)
    
    
    return answer