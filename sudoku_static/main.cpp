#include <iostream>
#include "sudoku.h"
using namespace std; 

void output_grid(string grid);

int main(){
	int grid_size = 9, box_size = 3;
	Sudoku sudoku = Sudoku(grid_size, box_size);
	
	// ��������
	int input_size = grid_size*grid_size+1;
	char* input = new char[input_size];
	cout<<"���룺";
	cin.getline(input, input_size);
	sudoku.parse(input);
	
	// չʾ��ʼ���� 
	cout<<"��ʼ���̣�"<<endl;
	sudoku.print();
	
	// չʾ�������� 
	cout<<"�������̣�"<<endl;
	sudoku.printWithInference();
	
	delete[] input;
	return 0;
}
