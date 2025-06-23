N, M = map(int, input().split(' '))

def backtrack(seq, visited):
    if len(seq) == M:
        print(' '.join(map(str, seq)))
        return

    for i in range(1, N+1):
    
        if (not visited[i]) and (not seq or seq[-1] < i):

            seq.append(i)
            visited[i] = True

            backtrack(seq, visited)

            seq.pop()
            visited[i] = False


visited = [False] * (N+1)

backtrack([], visited)