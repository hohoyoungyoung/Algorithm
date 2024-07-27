# (깊이, 값 )

def solution(numbers, target):
    
    ans = 0
    
    stack = [(0, numbers[0]), (0, -numbers[0])]
    
    
    while stack:
        
        depth, number = stack.pop()
        
        if depth==(len(numbers)-1) and number == target:
            ans += 1
            
        
        if depth < len(numbers)-1:
            stack.append((depth+1, number+numbers[depth+1]))
            stack.append((depth+1, number-numbers[depth+1]))
        
        
    return ans