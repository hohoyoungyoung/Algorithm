num = int(input())

for i in range(num):
    stack = []  
    ps = input()
    ans = 'YES'
    
    for j in range(len(ps)):
        if ps[j] == '(':
            stack.append(ps[j])

        else:

            if ps[j] == ')':
                if len(stack) != 0:
                    stack.pop()
                else:
                    ans = 'NO'
                    break

    if (len(stack) == 0) and (ans == 'YES'):
        ans = 'YES'
    else:
        ans = 'NO'
        
    
    print(ans)