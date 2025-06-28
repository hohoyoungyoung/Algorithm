N = int(input())
sang = set(map(int, input().split()))
M = int(input())
test = list(map(int, input().split()))

ans = ['1' if i in sang else '0' for i in test]
print(' '.join(ans))
