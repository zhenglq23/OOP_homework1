#ifndef _SUDOKU_H_
#define _SUDOKU_H_

#include "grid.h"
#include <string> 
using namespace std;

class Sudoku : public Grid {
	public:
		Sudoku();
		Sudoku(int grid_size, int box_size);
		void parse(char* input); 
		char* getInference(int row, int col, char* inference);	//得到row行，col列的格子的提示	
		char* check(char* data);
		void print(); //初始棋盘输出 
		void printWithInference();	//推理棋盘输出 
		~Sudoku();
};

#endif //_GRID_H_
