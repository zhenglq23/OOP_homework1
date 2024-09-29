#ifndef _GRID_H_
#define _GRID_H_
using namespace std;

class Grid{
	protected:
		int BOX_SIZE; //box每行的格子数 
		int GRID_SIZE;  //grid每行的格子数 
		char* grid;	//gird数据 
	
	public:	
		Grid(int grid_size=9, int box_size=3);
		char* getRow(int row, char* data);	//获取row行的数据 
		char* getCol(int col, char* data);	//获取col列的数据 
		char* getBox(int row, int col, char* data);	//获取row行,col列的所在box的数据 
		~Grid();
};

#endif //_GRID_H_
