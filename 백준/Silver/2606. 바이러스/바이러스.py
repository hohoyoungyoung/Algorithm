max_num = int(input())
N = int(input())

adj = [[] for i in range(max_num+1)]
visited = [0] * (max_num+1)

for i in range(N):
    a, b = map(int, input().split(' '))
    adj[a].append(b)
    adj[b].append(a)

def dfs(s):
    if not visited[s]:
        visited[s] = 1
        for line in adj[s]:
            dfs(line)

dfs(1)

print(sum(visited)-1)