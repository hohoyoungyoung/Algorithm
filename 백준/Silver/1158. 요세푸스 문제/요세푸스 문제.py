from collections import deque
import sys

input = sys.stdin.read

a, b = map(int, input().split())

queue = deque(range(1, a + 1)) 
ans = []

while queue:
    queue.rotate(-(b - 1))  
    ans.append(queue.popleft())  

print("<" + ", ".join(map(str, ans)) + ">")
