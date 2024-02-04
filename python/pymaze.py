import csv
from collections import deque

class maze:
    def __init__(self,rows=10,cols=10):
        self.rows=rows
        self.cols=cols
        self.maze_map={}
        self.grid=[]
        self.path={} 
        self._cell_width=50  
        self._win=None 
        self._canvas=None

    def CreateMaze(self,x=1,y=1,pattern=None,loopPercent=0,saveMaze=False,loadMaze=None):
        _stack=[]
        _closed=[]
        self._goal=(x,y)
        def blockedNeighbours(cell):
            n=[]
            for d in self.maze_map[cell].keys():
                if self.maze_map[cell][d]==0:
                    if d=='E' and (cell[0],cell[1]+1) in self.grid:
                        n.append((cell[0],cell[1]+1))
                    elif d=='W' and (cell[0],cell[1]-1) in self.grid:
                        n.append((cell[0],cell[1]-1))
                    elif d=='N' and (cell[0]-1,cell[1]) in self.grid:
                        n.append((cell[0]-1,cell[1]))
                    elif d=='S' and (cell[0]+1,cell[1]) in self.grid:
                        n.append((cell[0]+1,cell[1]))
            return n
                    
        def BFS(cell, y=4):
            frontier = deque()
            frontier.append(cell)
            path = {}
            visited = {(self.rows,self.cols)}
            while len(frontier) > 0:
                cell = frontier.popleft()
                if self.maze_map[cell]['W'] and (cell[0],cell[1]-1) not in visited:
                    nextCell = (cell[0],cell[1]-1)
                    path[nextCell] = cell
                    frontier.append(nextCell)
                    visited.add(nextCell)
                if self.maze_map[cell]['S'] and (cell[0]+1,cell[1]) not in visited:    
                    nextCell = (cell[0]+1,cell[1])
                    path[nextCell] = cell
                    frontier.append(nextCell)
                    visited.add(nextCell)
                if self.maze_map[cell]['E'] and (cell[0],cell[1]+1) not in visited:
                    nextCell = (cell[0],cell[1]+1)
                    path[nextCell] = cell
                    frontier.append(nextCell)
                    visited.add(nextCell)
                if self.maze_map[cell]['N'] and (cell[0]-1,cell[1]) not in visited:
                    nextCell = (cell[0]-1,cell[1])
                    path[nextCell] = cell
                    frontier.append(nextCell)
                    visited.add(nextCell)
            fwdPath={}
            while cell!=(self.rows,self.cols):
                try:
                    fwdPath[path[cell]]=cell
                    cell=path[cell]
                except:
                    print('Path to goal not found!')
                    return
            return fwdPath

        with open('createmaze.csv','r') as f:
            last=list(f.readlines())[-1]
            c=last.split(',')
            c[0]=int(c[0].lstrip('"('))
            c[1]=int(c[1].rstrip(')"'))
            self.rows=c[0]
            self.cols=c[1]
            self.grid=[]

        with open('createmaze.csv','r') as f:
            r=csv.reader(f)
            next(r)
            for i in r:
                c=i[0].split(',')
                c[0]=int(c[0].lstrip('('))
                c[1]=int(c[1].rstrip(')'))
                self.maze_map[tuple(c)]={'E':int(i[1]),'W':int(i[2]),'N':int(i[3]),'S':int(i[4])}
        self.path=BFS((self.rows,self.cols))

    def run(self):
        pass