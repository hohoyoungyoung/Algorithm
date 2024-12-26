n = int(input())
now = 1
ans = []
stack = []
find = True

for i in range(n):
    stack_num = int(input())
    
    
    while now <= stack_num:
        ans.append('+')
        stack.append(now)
        now += 1
    
    if stack[-1] == stack_num:
        ans.append('-')
        stack.pop()
        
    
    else:
        find = False

        

if not find:
    print('NO')
    
else:
    for i in ans:
        print(i)