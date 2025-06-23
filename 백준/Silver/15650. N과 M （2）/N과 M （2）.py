N, M = map(int, input().split())

def backtrack(seq):
    if len(seq) == M:
        print(' '.join(map(str, seq)))
        return

    start = seq[-1] + 1 if seq else 1  # seq가 비었으면 1부터 시작

    for i in range(start, N + 1):
        backtrack(seq + [i])  # 새 리스트로 넘겨주기 (불변성 유지)

backtrack([])
