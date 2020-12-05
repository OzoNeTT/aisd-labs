matrix = [
    ['*', '*', '*', '*', '*'],
    ['*', ' ', '*', ' ', '*'],
    ['*', ' ', ' ', ' ', '*'],
    ['*', ' ', '*', ' ', 'E'],
    ['*', 'S', '*', '*', '*']
]

already_visited=[]
def solve1(x,y):
       print((x,y))
       if matrix[x][y] == "E":
           print(*matrix, sep='\n')
           return True
       if matrix[x][y] == "*":
           return False
       if matrix[x][y] == "x":
           return False

       matrix[x][y] = "x"
       if (x,y) in already_visited:
           return False

       already_visited.append((x,y)) 
       if (x < len(matrix)-1 and solve1(x+1,y)):
           return True
       elif (y > 0 and solve1(x,y-1)):
           return True
       elif (x > 0 and solve1(x-1,y)):
           return True
       elif (y < len(matrix)-1 and solve1(x,y+1)):
           return True
       else:
           return False

solve1(4,1)