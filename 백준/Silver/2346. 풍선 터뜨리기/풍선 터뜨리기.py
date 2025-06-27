from collections import deque

N = int(input())
nums = list(map(int, input().split()))
que = deque((i+1, num) for i, num in enumerate(nums))  # 튜플 구성

ans = []

while que:
    a, b = que.popleft()
    ans.append(a)
    
    if not que:
        break

    if b > 0:
        que.rotate(-(b - 1))
    else:
        que.rotate(-b)

print(' '.join(map(str, ans)))
