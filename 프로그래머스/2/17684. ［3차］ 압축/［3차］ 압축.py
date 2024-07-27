def solution(msg):
    ans = []
    dictionary = {}
    
    for i in range(1, 27):
        dictionary[chr(i + 64)] = i
    
    last = 26  
    
    i = 0  
    
    while i < len(msg):
        
        j = i + 1
        while j <= len(msg) and msg[i:j] in dictionary:
            j += 1
        
        current_prefix = msg[i:j-1]
        

        ans.append(dictionary[current_prefix])
        
    
        if j <= len(msg):
            new_entry = msg[i:j]
            last += 1
            dictionary[new_entry] = last
        
        i += len(current_prefix)
    
    return ans
