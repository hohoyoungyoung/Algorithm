def solution(msg):
    ans = []
    dict = {}
    
    for i in range(1, 27):
        dict[chr(i+64)] = i
    
    last = 26
    
    i = 0
    
    while i < len(msg):
        
        j = i+1
        
        while j <= len(msg) and msg[i:j] in dict:
            j += 1
        
        current_prefix = msg[i:j-1]
        ans.append(dict[current_prefix])
        
        
        dict[msg[i:j]] = last+1
        last+=1
        
        
        i += len(current_prefix)
        
    
    return ans
        