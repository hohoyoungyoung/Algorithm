
num = int(input())

for i in range(num):
    ans = ''
    stack = input().split(' ')
    for j in range(len(stack)):
        stack[j] = stack[j][::-1]
    

    for k in range(len(stack)):
        ans += (stack[k] + ' ')
    
    print(ans)