#include "sudoku.h"
#include <iostream>
using namespace std;
int main()
{
    // finish your generate code...
    Sudoku new_sudoku = Sudoku::generate();
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cout << new_sudoku.getElement(9 * i + j) << " ";
        }
        cout << endl;
    }
    return 0;
}
