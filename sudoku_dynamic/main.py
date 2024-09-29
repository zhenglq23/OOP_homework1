from sudoku import Sudoku

if __name__ == "__main__":
    input = "017903600000080000900000507072010430000402070064370250701000065000030000005601720"
    #input = input("输入") 
    sudoku = Sudoku(9, 3)
    sudoku.parse(input)

    print("初始棋盘：")
    sudoku.print()
    print('推理棋盘：')
    sudoku.printWithInference()