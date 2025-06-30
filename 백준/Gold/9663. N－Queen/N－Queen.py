def n_queen_backtracking(n):
    def dfs(row):
        nonlocal count
        if row == n:
            count += 1
            return

        for col in range(n):
            if col in cols or (row + col) in diag1 or (row-col) in diag2:
                continue
            cols.add(col)
            diag1.add(row + col)
            diag2.add(row - col)
            dfs(row+1)
            cols.remove(col)
            diag1.remove(row + col)
            diag2.remove(row - col)

    count = 0
    cols = set()
    diag1 = set()
    diag2 = set()
    dfs(0)
    return count

N = int(input())
print(n_queen_backtracking(N))

