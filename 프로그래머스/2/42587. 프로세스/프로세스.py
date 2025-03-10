from collections import deque

def solution(priorities, location):
    
    ans = 0
    priority = max(priorities)
    
    processes = deque([(idx, priority) for idx, priority in enumerate(priorities)])
    
    while processes: 
        a = processes.popleft()
        # 우선순위가 밀리지 않는경우
        if a[1] >= priority:
            ans += 1
            
            #processes에서 max
            max_num = 0
            for i in processes:
                if i[1] > max_num:
                    max_num = i[1]
            priority = max_num
            
            if a[0] == location:
                return ans
        # 우선순위가 밀리는 경우 
        else:
            processes.append(a)
        
    return ans