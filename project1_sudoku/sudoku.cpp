#include <iostream>
#include "sudoku.h"
using namespace std;

Sudoku::Sudoku()
{
    for (int i = 0; i < sudokuSize; ++i)
        map[i] = 0;
}

Sudoku::Sudoku(const int init_map[])
{
    for (int i = 0; i < sudokuSize; ++i)
        map[i] = init_map[i];
}

int Sudoku::solution_count = 0;
// int Sudoku::map[Sudoku::sudokuSize]; // for map is static

void Sudoku::setMap(const int set_map[])
{
    for (int i = 0; i < sudokuSize; ++i)
        map[i] = set_map[i];
}

int Sudoku::getElement(int index)
{
    return map[index];
}

bool Sudoku::checkUnity(int arr[])
{
    int arr_unity[9];

    for (int i = 0; i < 9; ++i)
        arr_unity[i] = 0;
    
    for (int i = 0; i < 9; ++i)
        ++arr_unity[arr[i] - 1];

    for (int i = 0; i < 9; ++i)
        if(arr_unity[i] != 1)
            return false;
    return true;
}

bool Sudoku::isCorrect()
{
    bool check_result;
    int check_arr[9];
    int location;

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
            check_arr[j] = map[9 * i + j];
        check_result = checkUnity(check_arr);
        if(check_result == false)
            return false;
    }
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
            check_arr[j] = map[i + 9 * j];
        check_result = checkUnity(check_arr);
        if(check_result == false)
            return false;
    }
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            location = 27 * (i / 3) + 3 * (i % 3) + 9 * (j / 3) + (j % 3);
            check_arr[j] = map[location];
        }
        check_result = checkUnity(check_arr);
        if(check_result == false)
            return false;
    }
    return true;
}

void Sudoku::setElement(int index, int value)
{
    map[index] = value;
}

int Sudoku::getFirstZeroIndex()
{
    for (int i = 0; i < sudokuSize; ++i)
        if(map[i] == 0)
            return i;
    return -1;
}

Sudoku Sudoku::generate()
{
    int arr[9][9] = {
        {3, 0, 2, 0, 0, 5, 6, 9, 0},
        {0, 4, 0, 0, 9, 6, 0, 3, 0},
        {0, 5, 0, 0, 0, 8, 0, 0, 0},
        {1, 9, 0, 0, 8, 0, 7, 0, 3},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {5, 0, 7, 0, 3, 0, 0, 6, 1},
        {0, 0, 0, 8, 0, 0, 0, 2, 0},
        {0, 8, 0, 9, 6, 0, 0, 7, 0},
        {0, 6, 5, 7, 0, 0, 3, 0, 9},
    };

    Sudoku tmp;

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
            tmp.map[9 * i + j] = arr[i][j]; //   only for non-static function
    }
    return tmp;
}

void Sudoku::swapNum(int x, int y)
{
    if (x && y != 0)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (map[9 * i + j] == x)
                    map[9 * i + j] = y;
                
                else if (map[9 * i + j] == y)
                    map[9 * i + j] = x;
            }
        }
    }
    else
        cout << "Cause you enter \'0\'for change number\n"
             << "Change no number this time" << endl;
}

void Sudoku::swapRow(int x, int y)
{
    if ((x >= 0 && x < 3) && (y >= 0 && y < 3))
    {
        int row1 = x * 3;
        int row2 = y * 3;
        int middle = 0;

        for (int times = 0; times < 3; ++times, ++row1, ++row2)
        {
            for (int column = 0; column < 9; ++column)
            {
                middle = map[9 * row1 + column];
                map[9 * row1 + column] = map[9 * row2 + column];
                map[9 * row2 + column] = middle;
            }
        }
    }
    else
        cout << "Cause you don't follow the rule\n"
             << "Change no row this time" << endl;
}

void Sudoku::swapCol(int x, int y)
{
    if ((x >= 0 && x < 3) && (y >= 0 && y < 3))
    {
        int column1 = x * 3;
        int column2 = y * 3;
        int middle = 0;
        for (int times = 0; times < 3; ++times, ++column1, ++column2)
        {
            for (int row = 0; row < 9; row++)
            {
                middle = map[9 * row + column1];
                map[9 * row + column1] = map[9 * row + column2];
                map[9 * row + column2] = middle;
            }
        }
    }

    else
        cout << "Cause you don't follow the rule\n"
             << "we dont change colume this time" << endl;
}
void Sudoku::rotate(int x)
{
    int midarray[9][9];
    for (int times = 0; times < x; ++times)
    {
        for (int row = 0; row < 9; ++row)
        {
            for (int column = 0; column < 9; ++column)
            {
                midarray[column][8 - row] = map[9 * row + column];
            }
        }
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                map[9 * i + j] = midarray[i][j];
            }
        }
    }
}


void Sudoku::flip(int x)
{
    int middle;
    switch(x)
    {
        case 0:
            for (int column = 0; column < 9; ++column)
            {
                for (int times = 0; times < 4; ++times)
                {
                    middle = map[9 * times + column];
                    map[9 * times + column] = map[9 * (8 - times) + column];
                    map[9 * (8 - times) + column] = middle;
                }
            }
            break;
        
        case 1:
            for (int row = 0; row < 9; ++row)
            {
                for (int times = 0; times < 4; ++times)
                {
                    middle = map[9 * row + times];
                    map[9 * row + times] = map[9 * row + (8 - times)];
                    map[9 * row + (8 - times)] = middle;
                }
            }
            break;
        
        default:
            cout << "Cause you dont follow the rule\n"
                 << "Don't flip this time." << endl;
    }
}


bool solve_recursive(Sudoku question, Sudoku &answer)
{
    int firstZero;
    firstZero = question.getFirstZeroIndex();
    
    if(question.solution_count <= 2)
    {
        if (firstZero == -1)
        {
            if (question.isCorrect())
            {
                // answer = *this;
                for (int i = 0; i < 81; ++i)
                    answer.setElement(i, question.getElement(i));
                ++question.solution_count;
                return true;
            }
            else
                return false;
        }
        else
        {
            for (int num = 1; num <= 9; ++num)
            {
                question.setElement(firstZero, num);

                if (solve_recursive(question, answer))
                    return true;
            }
            return false;
        }
    }
    else
        return true;
}


int Sudoku::solve()
{
    solution_count = 0;
    Sudoku tmp;
    bool check = solve_recursive(*this, tmp);
    if(solution_count > 0)
    {
        for (int i = 0; i < 81; ++i)
            map[i] = tmp.map[i];
    }
    return solution_count;
}