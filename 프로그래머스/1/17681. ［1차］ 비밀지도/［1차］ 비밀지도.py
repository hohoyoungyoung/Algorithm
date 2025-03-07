# 둘 다 공백 -> 공백
# 하나라도 벽 -> 벽 
# 벽:1, 공백:0
# 이진화 -> 각 값 더해서 0인것만 공백으로 그 외는 다 벽

def binary(n, length):
    return format(n, 'b').zfill(length)  # n 비트 길이로 변환

def solution(n, arr1, arr2):
    map1 = [binary(arr1[i], n) for i in range(n)]
    map2 = [binary(arr2[i], n) for i in range(n)]
    
    ans = []
    for j in range(n):
        cache = ''
        for k in range(n):
            if int(map1[j][k]) + int(map2[j][k]) > 0:
                cache += '#'
            else:
                cache += ' '
        ans.append(cache)
        
    return ans
