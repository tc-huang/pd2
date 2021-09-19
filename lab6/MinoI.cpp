#include "MinoI.h"

char I_arr[2][4][4] = {
    {
        {'0','0','1','0'},
        {'0','0','1','0'},
        {'0','0','1','0'},
        {'0','0','1','0'}
    },
    {
        {'0','0','0','0'},
        {'0','0','0','0'},
        {'1','1','1','1'},
        {'0','0','0','0'}
    }
}

MinoI::MinoI():Mino(1){}
void MinoI::paint()
{
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
            cout << I_arr[ratate_index][i][j];
        cout << endl;
    }
}