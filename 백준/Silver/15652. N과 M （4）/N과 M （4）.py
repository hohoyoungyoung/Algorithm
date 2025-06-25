N, M = map(int, input().split(' '))

visited = [False] * (N+1)

def backtrack(seq, visited):
    if len(seq) == M:
        print(' '.join(map(str, seq)))
        return

    start = seq[-1] if seq else 1

    for i in range(start, N+1):
        
        seq.append(i)
        visited[i] = True

        backtrack(seq, visited)
            
        seq.pop()
        visited[i] = False


backtrack([], visited)

# 이거 백준에 제출하기