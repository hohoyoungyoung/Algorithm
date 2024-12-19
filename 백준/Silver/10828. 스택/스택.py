import sys
input = sys.stdin.read

num, *commands = input().splitlines()

stack = []

for string in commands:
    if ' ' in string:  # push 명령어
        _, b = string.split()
        stack.append(int(b))
    else:
        if string == 'pop':
            print(stack.pop() if stack else -1)
        elif string == 'size':
            print(len(stack))
        elif string == 'empty':
            print(0 if stack else 1)
        elif string == 'top':
            print(stack[-1] if stack else -1)
            
            
