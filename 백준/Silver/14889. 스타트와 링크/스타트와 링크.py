N = int(input())

table = []

for i in range(N):
    table.append(list(map(int, input().split(' '))))

visited = [False] * (N+1)
sequence = []


def get_team_score(team):
    score = 0
    for i in range(len(team)):
        for j in range(i + 1, len(team)):
            a = team[i] - 1  # 인덱스 맞추기 (1-based → 0-based)
            b = team[j] - 1
            score += table[a][b] + table[b][a]
    return score


min_diff = float('inf')

def dfs(start_index):
    global min_diff

    if len(sequence) == N // 2:
        start_team = sequence
        link_team = [i for i in range(1, N+1) if i not in sequence]

        start_score = get_team_score(start_team)
        link_score = get_team_score(link_team)

        diff = abs(start_score - link_score)
        min_diff = min(min_diff, diff)
        
        return

    for i in range(start_index, N + 1):  # 1부터 N까지
        if not visited[i]:
            visited[i] = True
            sequence.append(i)

            dfs(i + 1)  # 조합이므로 다음 탐색은 i+1부터

            sequence.pop()
            visited[i] = False

dfs(1)
print(min_diff)