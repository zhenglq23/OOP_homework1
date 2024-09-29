#ifndef _GRID_H_
#define _GRID_H_
using namespace std;

class Grid{
	protected:
		int BOX_SIZE; //boxÿ�еĸ����� 
		int GRID_SIZE;  //gridÿ�еĸ����� 
		char* grid;	//gird���� 
	
	public:	
		Grid(int grid_size=9, int box_size=3);
		char* getRow(int row, char* data);	//��ȡrow�е����� 
		char* getCol(int col, char* data);	//��ȡcol�е����� 
		char* getBox(int row, int col, char* data);	//��ȡrow��,col�е�����box������ 
		~Grid();
};

#endif //_GRID_H_
