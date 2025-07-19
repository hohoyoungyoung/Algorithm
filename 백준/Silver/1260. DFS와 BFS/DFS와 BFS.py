from collections import deque


N, M, V = map(int, input().split(' '))

adj = [[] for i in range(N+1)]

for i in range(M):
    a, b = map(int, input().split(' '))
    adj[a].append(b)
    adj[b].append(a)

for i in range(len(adj)):
    adj[i].sort()


ans1 = ''
visited = [0] * (N+1)

def dfs(m):
    global ans1
    if not visited[m]:
        visited[m] = 1
        ans1 += f'{m} '
        for i in adj[m]:
            dfs(i)

dfs(V)
print(ans1)

ans2 = ''  
visited2 = [0] * (N+1)



def bfs(m):

    global ans2 
    que = deque([m])
    visited2[m] = 1
    ans2 += f'{m} '
    
    while que:
        pop_num = que.popleft()
        for num in adj[pop_num]:
            if not visited2[num]:
                visited2[num] = 1
                ans2 += f'{num} '
                que.append(num)
    
bfs(V)
print(ans2)
