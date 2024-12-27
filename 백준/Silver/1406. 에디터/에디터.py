import sys
input = sys.stdin.readline

string = input().strip()
num = int(input().strip())
left_stack = list(string)  # 커서 왼쪽 부분
right_stack = []           # 커서 오른쪽 부분

for _ in range(num):
    edit = input().strip()
    
    if edit[0] == 'P':  # P $: 커서 위치에 문자 추가
        left_stack.append(edit[-1])
    elif edit[0] == 'L':  # L: 커서를 왼쪽으로 이동
        if left_stack:
            right_stack.append(left_stack.pop())
    elif edit[0] == 'D':  # D: 커서를 오른쪽으로 이동
        if right_stack:
            left_stack.append(right_stack.pop())
    elif edit[0] == 'B':  # B: 커서 왼쪽 문자 삭제
        if left_stack:
            left_stack.pop()

# 결과 출력
ans = ''.join(left_stack + right_stack[::-1])  # 오른쪽 스택을 뒤집어서 붙임
print(ans)
