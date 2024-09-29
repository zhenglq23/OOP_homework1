#include "sudoku.h"
#include <iostream>
#include <cstring>
using namespace std;

Sudoku::Sudoku(int grid_size, int box_size){
	Grid(grid_size, box_size);
}

void Sudoku::parse(char* input){
	strcpy(Grid::grid,input);
}

char* Sudoku::getInference(int row, int col, char* inference){
	for (int i=0; i<GRID_SIZE; i++)
		inference[i] = char(i+49);
	
	char* all_data_for_check = new char[3*GRID_SIZE];
	char* data_for_check = new char[GRID_SIZE];
	data_for_check = Grid::getRow(row,data_for_check);
	strcpy(all_data_for_check, data_for_check);
	data_for_check = Grid::getCol(col,data_for_check);
	strcat(all_data_for_check, data_for_check);
	data_for_check = Grid::getBox(row,col,data_for_check);
	strcat(all_data_for_check, data_for_check);
	
	for (int i=0; i<3*Grid::GRID_SIZE; i++){
		if (all_data_for_check[i] != '0'){
			inference[all_data_for_check[i]-49] = ' ';
		}
	}
	
	delete[] data_for_check;
	delete[] all_data_for_check;
	return inference;
}

void Sudoku::print(){
	char* row_data = new char[Grid::GRID_SIZE];
	string row_bound =   "#####################################"; 
	string row_bland =   "#   |   |   #   |   |   #   |   |   #";
	string row_interval = "#-----------#-----------#-----------#";
	
	for (int r=0; r<Grid::GRID_SIZE; r++){
		if (r==0)
			cout<<row_bound<<endl<<row_bland<<endl;
		else if (r%BOX_SIZE==0)
			cout<<row_bland<<endl<<row_bound<<endl<<row_bland<<endl;
		else
			cout<<row_bland<<endl<<row_interval<<endl<<row_bland<<endl;
		row_data = Grid::getRow(r, row_data);
		for (int c=0; c<Grid::GRID_SIZE; c++){
			if (c%Grid::BOX_SIZE==0)
				cout<<"#";
			else
				cout<<"|";
			if (row_data[c]!='0')
				cout<<" "<<row_data[c]<<" ";
			else
				cout<<"   ";
		}
		cout<<"#"<<endl;
	}
	cout<<row_bland<<endl<<row_bound<<endl;;
	
	delete[] row_data;
}

void Sudoku::printWithInference(){
	char* row_data = new char[Grid::GRID_SIZE];
	char* inference = new char[Grid::GRID_SIZE];
	string row_bound =   "#####################################";
	string row_interval = "#-----------#-----------#-----------#";
	
	for (int r=0; r<Grid::GRID_SIZE; r++){
		string line1 = "", line2 = "", line3 = "";
		if (r%BOX_SIZE==0)
			cout<<row_bound<<endl;
		// 获取数独在该行的数据 
		row_data = Grid::getRow(r, row_data);
	    // 进行列循环 
		for (int c=0; c<Grid::GRID_SIZE; c++){
			// 格式打印 
			if (c%Grid::BOX_SIZE==0){
				line1 += '#';
				line2 += '#';
				line3 += '#';
			}
			else{
				line1 += '|';
				line2 += '|';
				line3 += '|';
			}
			
			// 若该格有内容则在中间格打印，否则进行推理
			if (row_data[c]!='0'){
				line1 += "   ";
				line2 += " ";
				line2 +=row_data[c];
				line2 +=" ";
				line3 += "   ";
			}
			else{
				inference = getInference(r,c,inference);
				//cout<<"inference:"<<inference<<endl; 
				line1 += inference[0]; 
				line1 += inference[1]; 
				line1 += inference[2];
				line2 += inference[3];
				line2 += inference[4];
				line2 += inference[5];
				line3 += inference[6];
				line3 += inference[7];
				line3 += inference[8];
			}
		}
		cout<<line1<<"#"<<endl;
		cout<<line2<<"#"<<endl;
		cout<<line3<<"#"<<endl;
		cout<<row_interval<<endl;
	}
	cout<<row_bound<<endl;
	
	delete[] inference;
	delete[] row_data;
}

Sudoku::~Sudoku(){
}
