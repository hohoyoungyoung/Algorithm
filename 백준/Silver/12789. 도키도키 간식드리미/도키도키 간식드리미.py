N = int(input())
wait = list(map(int, input().split(' ')))
stack = []
first = 1

for i in range(len(wait)):
    if (wait[i] == first):
        first += 1
        continue

    elif len(stack) == 0:
        stack.append(wait[i])

    else:
        
        while (stack) and (stack[-1] == first):
            stack.pop()
            first += 1
        
        stack.append(wait[i])
    
while (stack) and (stack[-1] == first):
    stack.pop()
    first += 1

if len(stack) == 0:
    print('Nice')
else:
    print('Sad')

