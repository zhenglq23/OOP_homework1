#include "grid.h"
#include<cstring>
using namespace std;

Grid::Grid(int grid_size, int box_size){
	GRID_SIZE = grid_size;
	BOX_SIZE = box_size;
	grid = new char[GRID_SIZE*GRID_SIZE];
}

char* Grid::getRow(int row, char* data){
	for (int i=0; i<GRID_SIZE; i++){
		data[i] = grid[row*GRID_SIZE+i];
	}
	
	return data;
}

char* Grid::getCol(int col, char* data){
	for (int i=0; i<GRID_SIZE; i++){
		data[i] = grid[i*GRID_SIZE+col];
	}
	return data;
}	

char* Grid::getBox(int row, int col, char* data){
	int org_row = row/BOX_SIZE; //box起始行
	int org_col = col/BOX_SIZE; //box起始列
	int idx = 0; 
	for (int r=org_row; r<org_row+BOX_SIZE; r++){
		for (int c=org_col; c<org_col+BOX_SIZE; c++){
			data[idx] = grid[r*GRID_SIZE+c];
			idx++;
		}
	}
	return data;
}

Grid::~Grid(){
	delete[] grid;
}
