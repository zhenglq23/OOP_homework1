import numpy as np

class Grid:
    def __init__(self, grid_size=9, box_size=3):
        self.GRID_SIZE = grid_size
        self.BOX_SIZE = box_size
        self.grid = np.zeros((grid_size, grid_size)).astype(int)

    def getRow(self, row):
        return self.grid[row]
    
    def getCol(self, col):
        return self.grid[:,col].reshape(1,-1)
    
    def getBox(self, row, col):
        org_row = row // self.BOX_SIZE
        org_col = col // self.BOX_SIZE
        return self.grid[org_row:org_row+self.BOX_SIZE, org_col:org_col+self.BOX_SIZE].reshape(1,-1)

