# 균형잡힌 문자열 - (와 )의 개수가 같다는게 보장
def check_balance(string):
    left_count = 0
    right_count = 0
    for i in range(len(string)):
        if string[i] == '(':
            left_count += 1
        else:
            right_count += 1
    return left_count == right_count


def check_collect(string):
    stack = []
    for char in string:
        if char == '(':
            stack.append(char)
        else:
            if not stack:
                return False
            stack.pop()
    return not stack  # 스택이 비었으면 True


def solution(p):
    u = ''
    v = ''
    if not p:
        return ''
    
    for i in range(2, len(p)+1, 2):
        if check_balance(p[:i]):
            u = p[:i]
            v = p[i:]
            break
    
    if check_collect(u):
        return u + solution(v)
    else:
        restart = '('
        restart += solution(v)
        restart += ')'
        restart += ''.join(')' if ch == '(' else '(' for ch in u[1:-1])
        return restart
    return answer