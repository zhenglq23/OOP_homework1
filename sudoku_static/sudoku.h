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
		char* getInference(int row, int col, char* inference);	//�õ�row�У�col�еĸ��ӵ���ʾ	
		char* check(char* data);
		void print(); //��ʼ������� 
		void printWithInference();	//����������� 
		~Sudoku();
};

#endif //_GRID_H_
