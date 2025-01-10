def count_factors(n, p):
    count = 0
    while n > 0:
        count += n // p
        n //= p
    return count

n, r = map(int, input().split())

count_2 = count_factors(n, 2) - count_factors(r, 2) - count_factors(n-r, 2)
count_5 = count_factors(n, 5) - count_factors(r, 5) - count_factors(n-r, 5)

print(min(count_2, count_5))
