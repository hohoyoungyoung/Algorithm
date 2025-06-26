def convert_to_base(n, base):
    if n == 0:
        return '0'

    digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"  # 최대 36진수까지 가능
    result = ''

    while n > 0:
        result = digits[n % base] + result
        n //= base

    return result


def solution(n, t, m, p):
    num_str = ''
    i = 0
    while True:
        num_str += convert_to_base(i,n)
        if len(num_str) > (m*(t-1) + p):
            break
        
        i += 1
    
    ans = ''
    count = 0 
    
    for i in range(p-1, len(num_str), m):
        count += 1
        ans += num_str[i]
        
        if count == t:
            break
    
    return ans