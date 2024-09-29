from grid import Grid 
import copy
import pickle

class Sudoku(Grid):
    def __init__(self, grid_size=9, box_size=3):
        super().__init__(grid_size, box_size)
    
    def parse(self, input):
        for i in range(self.GRID_SIZE*self.GRID_SIZE):
            self.grid[i//self.GRID_SIZE, i%self.GRID_SIZE] = int(input[i])

    def getInference(self, row, col):
        data_for_check = []
        inference = [1,2,3,4,5,6,7,8,9]

        data_for_check.extend(self.getRow(row).tolist())
        data_for_check.extend(self.getCol(col).tolist())
        data_for_check.extend(self.getBox(row, col).tolist())

        for data in data_for_check:
            if data in inference:
                inference.remove(data)

        return inference
    
    # 打印初始棋盘
    def print(self):
        for row in self.grid:
            print(' '.join(map(str, row)))

    # 打印推理棋盘
    def printWithInference(self):
        for row in range(self.GRID_SIZE):
            row_data = self.grid[row]
            for col,data in enumerate(row_data):
                # 无内容 回溯
                if data==0:
                    print(self.getInference(row,col),end='|')
                else:
                    print(data,end='|')
            print(' ')

    # 克隆
    def clone(self):
        return copy.deepcopy(self)

    # 序列化
    def serialize(self, file_path):
        with open(file_path, 'wb') as file:
            pickle.dump(self, file)
    
    # 反序列化
    def deserialize(file_path):
        with open(file_path, 'rb') as file:
            return pickle.load(file)
