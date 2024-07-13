import sys
sys.setrecursionlimit(10**6)

def solution(nodeinfo):
    answer = []
    memo={}
    preorder_list = []
    postorder_list = []

    for i in range(len(nodeinfo)):
        memo[nodeinfo[i][0]] = i+1
        
    nodeinfo.sort()
    
    def preorder(n):
        max_y = 0
        max_i = 0
        
        if len(n) < 1:
            return
        
        for i in range(len(n)):
            if n[i][1] > max_y:
                max_y = n[i][1]
                max_i = i
    
        preorder_list.append(memo[n[max_i][0]])
    
        preorder(n[:max_i])
        preorder(n[max_i+1:])
    
    def postorder(n):
        max_y = 0
        max_i = 0
        
        if len(n) < 1:
            return
        
        for i in range(len(n)):
            if n[i][1] > max_y:
                max_y = n[i][1]
                max_i = i
    
        postorder(n[:max_i])
        postorder(n[max_i+1:])    
        postorder_list.append(memo[n[max_i][0]])

        
    preorder(nodeinfo)
    postorder(nodeinfo)
    answer.append(preorder_list)
    answer.append(postorder_list)
    
    
    return answer
