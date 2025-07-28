# 이번년도 순위 높아졌으면 앞에 들어온다. 
# 잘못된 정보가 있을수도..? 모순 발생할듯
# 올해 순위를 완벽히 못 만들수도 있다.

from collections import deque

test_case = int(input())

for i in range(test_case):
    n = int(input())
    num_list = list(map(int, input().split(' ')))
    adj = [[] for _ in range(n+1)]
    indegree = [0] * (n + 1)

    for i in range(n):
        for j in range(i + 1, n):
            a = num_list[i]
            b = num_list[j]
            adj[a].append(b)
            indegree[b] += 1


    m = int(input())

    for j in range(m):
        num1, num2 = map(int, input().split(' '))
    
        # 방향 바꾸기
        if num2 in adj[num1]:
            adj[num1].remove(num2)
            adj[num2].append(num1)
            indegree[num2] -= 1
            indegree[num1] += 1
        else:
            adj[num2].remove(num1)
            adj[num1].append(num2)
            indegree[num1] -= 1
            indegree[num2] += 1
            
    q = deque()

    for i in range(1, n+1):
        if indegree[i] == 0:
            q.append(i)
    
    result = []
    certain = True #확실한 순위
    cycle = False # 사이클 여부

    for _ in range(n):
        if not q:
            cycle = True
            break
        if len(q) > 1:
            certain = False

        now = q.popleft()
        result.append(now)

        for nxt in adj[now]:
            indegree[nxt] -= 1
            if indegree[nxt] == 0:
                q.append(nxt)

    if cycle:
        print("IMPOSSIBLE")
    elif not certain:
        print("?")
    else:

        print(' '.join(map(str, result)))
