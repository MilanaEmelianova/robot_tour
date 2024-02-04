import queue
import csv
from collections import deque, OrderedDict
from pymaze import maze

# TODO
'''
def get_csv(*args):
the function will take 8 coordinates of the obstacles
format: 2 1 S (or maybe even 2 S - where 2 is 2th cell in the csv file)
the function puts 0 in a cell (2, 1) "S" AND in a cell (3, 1) "N"
'''


with open('createmaze.csv', 'w', newline='') as file:
    writer = csv.writer(file)
    field = ["cell", "E", "W", "N", "S"]
    rows = [["(1, 1)",0,0,0,1],
            ["(2, 1)",1,0,1,0],
            ["(3, 1)",1,0,0,1],
            ["(4, 1)",1,0,0,0],
            ["(1, 2)",0,0,0,1],
            ["(2, 2)",1,1,1,0],
            ["(3, 2)",1,1,0,1],
            ["(4, 2)",1,1,1,0],
            ["(1, 3)",1,0,0,0],
            ["(2, 3)",0,1,0,1],
            ["(3, 3)",1,1,1,1],
            ["(4, 3)",1,1,1,0],
            ["(1, 4)",0,1,0,1],
            ["(2, 4)",0,0,1,1],
            ["(3, 4)",0,1,1,0],
            ["(4, 4)",0,1,0,0]
    ]
    writer.writerow(field)
    writer.writerows(rows)


def BFS(m, x1, y1, x2, y2):
    start=(x1, y1)
    print(f'start: {start}')
    frontier=[start]
    explored=[start]
    bfsPath={}
    while len(frontier)>0:
        currCell=frontier.pop(0)
        if currCell==(1,1):
            break
        for d in 'ESNW':
            if m.maze_map[currCell][d]==True:
                if d=='E':
                    childCell=(currCell[0],currCell[1]+1)
                elif d=='W':
                    childCell=(currCell[0],currCell[1]-1)
                elif d=='N':
                    childCell=(currCell[0]-1,currCell[1])
                elif d=='S':
                    childCell=(currCell[0]+1,currCell[1])
                if childCell in explored:
                    continue
                frontier.append(childCell)
                explored.append(childCell)
                bfsPath[childCell]=currCell
    fwdPath={}
    cell=(x2, y2)
    while cell!=start:
        fwdPath[bfsPath[cell]]=cell
        cell=bfsPath[cell]
    return OrderedDict(reversed(list(fwdPath.items())))
        
    

if __name__=='__main__':
    m=maze(4,4)
    m.CreateMaze(loadMaze="createmaze.csv")
    path=BFS(m, 4, 1, 1, 2)
    print('Length of Shortest Path',len(path))
    print(path)
    m.run()
    
