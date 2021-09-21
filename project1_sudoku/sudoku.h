#ifndef SUDOKU_H
#define SUDOKU_H

/***************************************************
 * Finish your .cpp according to this header file. *
 * You can modify this file if needed.             *
 ***************************************************/

class Sudoku
{
    public:
        Sudoku();

        //  add those
        Sudoku(const int* init_map);
        void setMap(const int* set_map);
        int getElement(int index);
        void setElement(int index, int value);
        int getFirstZeroIndex();
        bool isCorrect();

        // generate
        static Sudoku generate();

        // transform
        void swapNum(int x, int y);
        void swapRow(int x, int y);
        void swapCol(int x, int y);
        void rotate(int x);
        void flip(int x);

        // solve
        int solve();

        static int solution_count;

    private:
        //  add those
        static const int sudokuSize = 81;
        int map[sudokuSize];
        bool checkUnity(int arr[]);
};

#endif // SUDOKU_H
