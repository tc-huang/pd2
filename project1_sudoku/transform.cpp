#include <iostream>
#include <fstream>
#include "sudoku.h"
using namespace std;

int main()
{
    //  this is the input from example
    // int arr[9][9] = {
    //     {3, 0, 2, 0, 0, 5, 6, 9, 0},
    //     {0, 4, 0, 0, 9, 6, 0, 3, 0},
    //     {0, 5, 0, 0, 0, 8, 0, 0, 0},
    //     {1, 9, 0, 0, 0, 0, 7, 0, 3},
    //     {0, 0, 0, 0, 0, 0, 0, 0, 0},
    //     {5, 0, 7, 0, 3, 0, 0, 6, 1},
    //     {0, 0, 0, 8, 0, 0, 0, 2, 0},
    //     {0, 8, 0, 9, 6, 0, 0, 7, 0},
    //     {0, 6, 5, 7, 0, 0, 3, 0, 9},
    // };

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
    /*  task1: input sudoku problem */
    cout << "input problem" << endl;
    Sudoku sudoku_t(arr);
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cout << sudoku_t.getElement(9 * i + j) << " ";
        }
        cout << endl;
    }
    
    // Sudoku sudoku_t;
    // int num;
    // for (int i = 0; i < 9; i++)
    // {
    //     for (int j = 0; j < 9; j++)
    //     {
    //         cin >> num;
    //         sudoku_t.setElement(9 * i + j, num);
    //     }
    // }
    /*  task2: input transform comman */
    cout << "command" << endl;
    ifstream inFile("transform.in", ios::in);
    if (!inFile)
    {
        cerr << "Failed to open file.in" << endl;
        exit(1);
    }
    
    int transform, x, y;

    // while (cin >> transform && transform != 0)
    while (inFile >> transform && transform != 0)
    {
        cout << transform << " ";
        if (transform < 4)
        {
            // cin >> x >> y;
            inFile >> x >> y;
            cout << x << " " << y << endl;
            switch (transform)
            {
            case 1:
                sudoku_t.swapNum(x, y);
                break;
            case 2:
                sudoku_t.swapRow(x, y);
                break;
            case 3:
                sudoku_t.swapCol(x, y);
                break;
            }
        }
        else
        {
            // cin >> x;
            inFile >> x;
            cout << x << endl;
            switch (transform)
            {
            case 4:
                sudoku_t.rotate(x);
                break;
            case 5:
                sudoku_t.flip(x);
                break;
            }
        }
            
    }
    inFile.close();
    /*  task3: output transformed sudoku */
    cout << "output" << endl;
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cout << sudoku_t.getElement(9 * i + j) << " ";
        }
        cout << endl;
    }
    return 0;
}
