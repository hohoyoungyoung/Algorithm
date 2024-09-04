# 가장 먼 X값, Y값  가장 짧은 x, y 

def solution(wallpaper):
    lux = float('inf')
    luy = float('inf')
    rdx = -float('inf')
    rdy = -float('inf')
    
    row = len(wallpaper)
    col = len(wallpaper[0])
    
    for i in range(row):
        for  j in range(col):
            if wallpaper[i][j] == '#':
                # 제일 작은 y와 젤 작은 x 제일큰 y와 제일큰 x
                lux = min(lux, i)
                luy = min(luy, j)
                
                rdx = max(rdx, i+1)
                rdy = max(rdy, j+1)
                        
    return [lux, luy, rdx, rdy]