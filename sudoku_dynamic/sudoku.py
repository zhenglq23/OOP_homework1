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
            if data in inference and data!=0:
                inference[data-1] = ' '
        return inference
    
    # 打印初始棋盘
    def print(self):
        """for row in self.grid:
            print(' '.join(map(str, row)))"""
        row_bound = "#####################################"
        row_bland = "#   |   |   #   |   |   #   |   |   #"
        row_interval = "#-----------#-----------#-----------#"
        for r in range(self.GRID_SIZE):
            if r == 0:
                print(row_bound)
                print(row_bland)
            elif r % self.BOX_SIZE == 0:
                print(row_bland)
                print(row_bound)
                print(row_bland)
            else:
                print(row_bland)
                print(row_interval)
                print(row_bland)
            
            row_data = self.getRow(r)
            for c in range(self.GRID_SIZE):
                if c % self.BOX_SIZE == 0:
                    print("#", end="")
                else:
                    print("|", end="")
                
                if row_data[c] == 0:
                    print("   ", end="")
                else:
                    print(f" {row_data[c]} ", end="")
                    
            print("#")

        print(row_bland)
        print(row_bound)

    # 打印推理棋盘
    def printWithInference(self):
        row_bound = "#####################################"
        row_interval = "#-----------#-----------#-----------#"

        for r in range(self.GRID_SIZE):
            line1, line2, line3 = "", "", ""
            if r % self.BOX_SIZE == 0:
                print(row_bound)
            
            # 获取数独在该行的数据
            row_data = self.getRow(r)
            
            # 进行列循环
            for c in range(self.GRID_SIZE):
                # 格式打印
                if c % self.BOX_SIZE == 0:
                    line1 += '#'
                    line2 += '#'
                    line3 += '#'
                else:
                    line1 += '|'
                    line2 += '|'
                    line3 += '|'
                
                # 若该格有内容则在中间格打印，否则进行推理
                if int(row_data[c]) == 0:
                    inference = self.getInference(r, c)
                    line1 += str(inference[0]) + str(inference[1]) + str(inference[2])
                    line2 += str(inference[3]) + str(inference[4]) + str(inference[5])
                    line3 += str(inference[6]) + str(inference[7]) + str(inference[8])
                else:
                    line1 += "   "
                    line2 += f" {row_data[c]} "
                    line3 += "   "
            
            print(line1 + "#")
            print(line2 + "#")
            print(line3 + "#")
            print(row_interval)

        print(row_bound)

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
