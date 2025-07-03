import sys
plate = []

for i in range(9):
    plate.append(list(map(int, input().split(' '))))


def row_check(row, col):
    row_can = {} 
    row_can = set([1,2,3,4,5,6,7,8,9]) - set(plate[row])
    return row_can

def col_check(row, col):
    col_lst = []

    for i in range(len(plate)):
        col_lst.append(plate[i][col])

    col_can = {}
    col_can = set([1,2,3,4,5,6,7,8,9]) - set(col_lst)
    return col_can

def square_check(row, col):
    square_lst = []
    start_row = (row//3) * 3
    start_col = (col//3) * 3

    for i in range(start_row, start_row + 3):
        for j in range(start_col, start_col + 3):
            if plate[i][j] != 0:
                square_lst.append(plate[i][j])
    
    return set([1,2,3,4,5,6,7,8,9]) - set(square_lst)

def get_candidates(row, col):
    return row_check(row, col) & col_check(row, col) & square_check(row, col)

def is_filled():
    for row in plate:
        if 0 in row:
            return False
    return True

def solve():
    if is_filled():

        for i in range(len(plate)):
            print(' '.join(map(str, plate[i]))) 

        sys.exit()

    for i in range(len(plate)):
        for j in range(len(plate)):
            if plate[i][j] == 0:
                candidates = get_candidates(i, j)
                # 여기서 구한 get_candidates로 인해 분기가 발생. 

                for num in candidates:
                    plate[i][j] = num
                    solve()
                    plate[i][j] = 0
                return
                

solve()