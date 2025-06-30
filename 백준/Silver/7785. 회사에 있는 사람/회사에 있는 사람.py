n = int(input())

log = set()

for i in range(n):
    name, state = input().split(' ')
    if state == 'enter':
        log.add(name)
    else:
        log.remove(name)

for i in sorted(log, reverse=True):
    print(i)