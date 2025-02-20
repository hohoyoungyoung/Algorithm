n = int(input())
lst = list(map(int, input().split()))

# 1. 피벗 찾기: 오른쪽에서 왼쪽으로 탐색하며, lst[i] < lst[i+1]를 만족하는 i를 찾음.
pivot = -1
for i in range(n - 2, -1, -1):
    if lst[i] < lst[i + 1]:
        pivot = i
        break

# 피벗이 없는 경우(내림차순 배열)는 다음 순열이 없으므로 -1 출력.
if pivot == -1:
    print(-1)
else:
    # 2. 피벗보다 큰 수 중에서, 오른쪽에서 가장 먼저 만나는 원소의 인덱스를 찾음.
    swap_index = -1
    for j in range(n - 1, pivot, -1):
        if lst[j] > lst[pivot]:
            swap_index = j
            break

    # 3. 피벗과 swap_index의 값을 교환.
    lst[pivot], lst[swap_index] = lst[swap_index], lst[pivot]
    # 피벗 오른쪽 부분을 뒤집어서 오름차순으로 만듦.
    lst[pivot + 1:] = lst[pivot + 1:][::-1]
    
    # 결과 출력 (원하는 포맷에 맞게 공백으로 구분하여 출력)
    print(" ".join(map(str, lst)))
