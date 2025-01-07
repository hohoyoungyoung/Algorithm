import sys
input = sys.stdin.readline

# 최대 입력값 설정 
MAX_LIMIT = 10**6

# 에라토스테네스의 체로 소수를 미리 계산
def sieve_of_eratosthenes(limit):
    sieve = [True] * (limit + 1)
    sieve[0] = sieve[1] = False  # 0과 1은 소수가 아님
    
    for i in range(2, int(limit**0.5) + 1):
        if sieve[i]:
            for j in range(i * i, limit + 1, i):
                sieve[j] = False
    
    primes = [x for x in range(2, limit + 1) if sieve[x]]
    return primes, sieve  # 소수 리스트와 소수 여부를 확인할 수 있는 배열 반환

# 미리 계산된 소수와 소수 여부 배열
primes, is_prime = sieve_of_eratosthenes(MAX_LIMIT)

# 골드바흐 파티션 찾기
def sum_lst(n):
    for prime in primes:
        if prime > n:  # 소수가 n보다 크면 중단
            break
        if is_prime[n - prime]:  # n - prime이 소수라면 성공
            print(f'{n} = {prime} + {n - prime}')
            return
    print("Goldbach's conjecture is wrong")

# 입력 처리 및 실행
while True:
    n = int(input().strip())
    if n == 0:
        break
    sum_lst(n)
