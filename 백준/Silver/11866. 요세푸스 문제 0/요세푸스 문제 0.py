from collections import deque

N, K = map(int, input().split(' '))
que = deque(range(1, N+1))
result = []

while que:
    que.rotate(-K+1)  # 왼쪽으로 K-1칸 회전
    result.append(que.popleft())  # 맨 앞 제거


print("<" + ", ".join(map(str, result)) + ">")
