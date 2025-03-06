def solution(s):
    
    dict1 = {'zero':0,'one':1,'two':2,'three':3,'four':4,'five':5,'six':6,'seven':7,'eight':8,'nine':9}
    dict2 = {'0':0,'1':1,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9}
    
    cache = ''
    ans = ''
    
    for i in s:
        if i in dict2:
            ans += i
        else:
            cache += i
            if cache in dict1:
                ans += str(dict1[cache])
                cache = ''
            
    return int(ans)
        
        
        
    