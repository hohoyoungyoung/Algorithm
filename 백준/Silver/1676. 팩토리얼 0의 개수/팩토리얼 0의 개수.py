def factorial_0(n):
    count = 0
    i = 5
    while n >= i:
        count += n // i  # 5의 배수 개수 더하기
        i *= 5  # 5의 제곱, 세제곱 등도 고려
    return count

print(factorial_0(int(input())))