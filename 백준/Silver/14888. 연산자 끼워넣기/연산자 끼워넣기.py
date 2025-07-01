N = int(input())

sequence = list(map(int, input().split(' ')))
operator_cnt = list(map(int, input().split(' ')))
# +, -, *, /

max_num = -float('inf')
min_num = float('inf')

def dfs(idx, current_result):
    global max_num, min_num

    if idx == N:
        max_num = max(max_num, current_result)
        min_num = min(min_num, current_result)
        return max_num, min_num

    for i in range(4):
        if operator_cnt[i] > 0:
            operator_cnt[i] -= 1

            if i == 0:
                dfs(idx + 1, current_result + sequence[idx])
            elif i == 1:
                dfs(idx + 1, current_result - sequence[idx])
            elif i == 2:
                dfs(idx + 1, current_result * sequence[idx])
            elif i == 3:
                # 음수 나눗셈 처리 조심!
                if current_result < 0:
                    dfs(idx + 1, -(-current_result // sequence[idx]))
                else:
                    dfs(idx + 1, current_result // sequence[idx])

            operator_cnt[i] += 1  # backtracking
    
    return max_num, min_num


max_num, min_num = dfs(1, sequence[0])

print(max_num)
print(min_num)