import sys
input = sys.stdin.readline

stack = []
output = []

N = int(input())

for _ in range(N):
    order = input().split()

    if order[0] == '1':
        stack.append(int(order[1]))
    elif order[0] == '2':
        if stack:
            output.append(str(stack.pop()))
        else:
            output.append('-1')
    elif order[0] == '3':
        output.append(str(len(stack)))
    elif order[0] == '4':
        output.append('1' if not stack else '0')
    elif order[0] == '5':
        if stack:
            output.append(str(stack[-1]))
        else:
            output.append('-1')

# 출력은 한 번에
print('\n'.join(output))
