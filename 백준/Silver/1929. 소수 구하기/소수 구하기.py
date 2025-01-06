def sieve_of_eratosthenes(a, b):
    sieve = [True] * (b + 1)
    sieve[0] = sieve[1] = False  
    
    for i in range(2, int(b**0.5) + 1):
        if sieve[i]:
            for j in range(i * i, b + 1, i):
                sieve[j] = False
    
    return [x for x in range(a, b + 1) if sieve[x]]

a, b = map(int, input().split())
primes = sieve_of_eratosthenes(a, b)
print('\n'.join(map(str, primes)))  