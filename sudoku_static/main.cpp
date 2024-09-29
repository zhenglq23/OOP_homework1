#include <iostream>
#include "sudoku.h"
using namespace std; 

void output_grid(string grid);

int main(){
	int grid_size = 9, box_size = 3;
	Sudoku sudoku = Sudoku(grid_size, box_size);
	
	// 接受输入
	int input_size = grid_size*grid_size+1;
	char* input = new char[input_size];
	cout<<"输入：";
	cin.getline(input, input_size);
	sudoku.parse(input);
	
	// 展示初始棋盘 
	cout<<"初始棋盘："<<endl;
	sudoku.print();
	
	// 展示推理棋盘 
	cout<<"推理棋盘："<<endl;
	sudoku.printWithInference();
	
	delete[] input;
	return 0;
}
