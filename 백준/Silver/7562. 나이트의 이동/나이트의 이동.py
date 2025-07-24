from collections import deque

N = int(input())

for i in range(N):
    I = int(input())

    q = deque([])

    start_row, start_col = map(int, input().split(' '))
    end_row, end_col = map(int, input().split(' '))

    if (start_row==end_row and start_col==end_col):
        print(0)
        continue

    q.append((start_row, start_col))

    maps = [[0]*I for _ in range(I)]
    cnt = 1

    while q:
        row, col = q.popleft()


        for nrow, ncol in [(row-1,col-2),(row-2,col-1),(row-2,col+1),(row-1,col+2),(row+1,col+2),(row+2,col+1),(row+2,col-1),(row+1,col-2)]:
        
            if (0<=nrow<I and 0<=ncol<I and maps[nrow][ncol] == 0): 
                maps[nrow][ncol] = maps[row][col] + 1
                q.append((nrow,ncol))
                if (nrow==end_row and ncol==end_col):
                    print(maps[end_row][end_col])
                    break
                