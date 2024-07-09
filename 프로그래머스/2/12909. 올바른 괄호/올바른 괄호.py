def solution(s):
    answer = True
    
    stack = []
    
    for i in range(len(s)):
        if s[i] == "(":
            stack.append(s[i])
        else:
            if len(stack) < 1:
                return False
            stack.pop()
    
    if len(stack) >= 1:
        return False
    

    return answer