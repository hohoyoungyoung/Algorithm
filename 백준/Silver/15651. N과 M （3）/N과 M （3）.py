N, M = map(int, input().split(' '))

def backtrack(seq):
    if len(seq) == M:
        print(' '.join(map(str, seq)))
        return

    for i in range(1, N+1):

        seq.append(i)
        backtrack(seq)
        seq.pop()



backtrack([])