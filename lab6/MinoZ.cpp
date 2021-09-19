#include "MinoZ.h"

char Z_arr[2][4][4]={
    {
        {'0','0','0','0'},
		{'1','1','0','0'},
		{'0','1','1','0'},
		{'0','0','0','0'}
    },
	{
        {'0','0','0','0'},
		{'0','0','1','0'},
		{'0','1','1','0'},
		{'0','1','0','0'}
    }
};

MinoZ::MinoZ():Mino(1){}

void MinoZ::paint()
{
    for(int i=0;i<4;++i)
    {
      for(int j=0;j<4;++j)
        cout<<Z_arr[rotate_index][i][j];
	cout<<endl;
    }      
}