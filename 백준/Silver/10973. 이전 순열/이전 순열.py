n = int(input())
lst = list(map(int, input().split()))

pivot = -1
for i in range(n - 2, -1, -1):
    if lst[i] > lst[i + 1]:
        pivot = i
        break

if pivot == -1:
    print(-1)
else:
    swap_index = -1
    for j in range(n - 1, pivot, -1):
        if lst[j] < lst[pivot]:
            swap_index = j
            break

    lst[pivot], lst[swap_index] = lst[swap_index], lst[pivot]
    lst[pivot + 1:] = lst[pivot + 1:][::-1]
    
    print(" ".join(map(str, lst)))