chessPlate = [[0 for i in range(8)] for i in range(8)]
dx=[2,1,-1,-2,-2,-1,1,2]
dy=[1,2,2,1,-1,-2,-2,-1]

def knigtWalk (x, y, step):
    chessPlate[x][y] = step
    for i in range(8):   
        x1 = x + dx[i]
        y1 = y + dy[i]

        if ((x1 >= 0) and (y1 >= 0) and (x1 < 8) and (y1 < 8) and (chessPlate[x1][y1] == 0)):
            knigtWalk(x1, y1, step + 1)
knigtWalk(0,0,1)
print(*chessPlate, sep='\n')