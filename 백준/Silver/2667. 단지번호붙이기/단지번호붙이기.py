N = int(input())

maps = []
result = []

for i in range(N):
    maps.append(input())

visited = [[0]*N for i in range(N)]
direction = [(-1,0),(0,-1),(0,1),(1,0)]

def dfs(x, y):
    for dx,dy in direction:
        if 0 <= x+dx < N and 0 <= y+dy < N and maps[x+dx][y+dy] == '1' and visited[x+dx][y+dy] == 0:
                 
            visited[x+dx][y+dy] = 1
            dfs(x+dx, y+dy)
            global count
            count += 1


for i in range(N):
    for j in range(N):
        if maps[i][j] == '1' and not visited[i][j]:
            visited[i][j] = 1
            count = 1
            dfs(i, j)
            result.append(count)

print(len(result))
result.sort()
for i in range(len(result)):
    print(result[i])