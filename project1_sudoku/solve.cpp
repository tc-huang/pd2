#include <iostream>
#include "sudoku.h"
using namespace std;

int main()
{
    // finish your solve code...
    int arr[81] = {
        3, 0, 2, 0, 0, 5, 6, 9, 0,
        0, 4, 0, 0, 9, 6, 0, 3, 0,
        0, 5, 0, 0, 0, 8, 0, 0, 0,
        1, 9, 0, 0, 8, 0, 7, 0, 3,
        0, 0, 0, 0, 0, 0, 0, 0, 0,
        5, 0, 7, 0, 3, 0, 0, 6, 1,
        0, 0, 0, 8, 0, 0, 0, 2, 0,
        0, 8, 0, 9, 6, 0, 0, 7, 0,
        0, 6, 5, 7, 0, 0, 3, 0, 9,
    };
    // int arr2[81] = {
    //     0, 7, 2, 1, 4, 5, 6, 9, 8,
    //     8, 0, 1, 2, 9, 6, 5, 3, 7,
    //     9, 5, 0, 3, 7, 8, 2, 1, 4,
    //     1, 9, 4, 0, 8, 2, 7, 5, 3,
    //     6, 3, 8, 5, 0, 7, 9, 4, 2,
    //     5, 2, 7, 4, 3, 0, 8, 6, 1,
    //     7, 1, 9, 8, 5, 3, 0, 2, 6,
    //     2, 8, 3, 9, 6, 4, 1, 0, 5,
    //     4, 6, 5, 7, 2, 1, 3, 8, 0,
    // }; 
    Sudoku sudoku_q(arr);
    // Sudoku sudoku_q;
    // int num, result;

    // for (int i = 0; i < 9; i++)
    // {
    //     for (int j = 0; j < 9; j++)
    //     {
    //         cin >> num;
    //         sudoku_q.setElement(9 * i + j, num);
    //     }
    // }
    cout << "Loading... it may take a while to solve(depends on the question's complexity)" << endl;
    int result = sudoku_q.solve();
    cout << result << endl;
    if (result == 1)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << sudoku_q.getElement(9 * i + j) << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
