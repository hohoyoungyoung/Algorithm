# 모든 간선의 경우, 그 간선이 제거 되었을때의 연결되는 노드의 수를 구하고
# 그 노드의 수가 전체노드의 절반 보다 작으면 답:(전체 노드-카운트한 노드) - 카운트한 노드
# ,,, 크면 답: 카운트한 노드 - (전체 노드-카운트한 노드)
# 전체노드 - 2카운트한 노드 ---- 절댓값 인듯.
# dictionary = {1: [2,3,4]} 이런식으로 1이 누구랑 연결되어있는지 확인한다면!??

def solution(n, wires):

    answer = float('inf')
    
    for i in range(0, len(wires)):
        e_w = wires[:i] + [] + wires[i+1:] 
    
        w_l = [[] for i in range(n+1)]

        for wire in e_w:
            w_l[wire[0]].append(wire[1])
            w_l[wire[1]].append(wire[0])

        # 탐색
        def dfs(start, visited = [0]*(n+1)):
            visited[start] = 1
            for v in w_l[start]:
                if not visited[v]:
                    dfs(v, visited) 
            return visited   
    
        v_c = sum(dfs(1))
        cache = abs(n - 2*v_c)
        
        answer = min(cache, answer)
        
        
    return answer