N, M = map(int, input().split(' '))

n_list = set(input() for i in range(N))
m_list = [input() for j in range(M)]

count = 0

for m in m_list:
    if m in n_list:
        count += 1

print(count)    

