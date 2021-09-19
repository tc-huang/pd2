#include<iostream>
#include<new>
#include"HugeInt.h"
using namespace std;

int main()
{   
    try
    {
        HugeInt* x_ptr = new HugeInt; //   + or -
        HugeInt* y_ptr = new HugeInt(28825252);
        HugeInt* z_ptr = new HugeInt("314159265358979323846");
        HugeInt* result_ptr = new HugeInt;

        cout << "type in a num: ";
        cin >> *x_ptr;
        *result_ptr = *x_ptr + *y_ptr;
        cout << *x_ptr << " + " << *y_ptr << " = " << *result_ptr << endl;

        *result_ptr = *z_ptr - *x_ptr;
        cout << *z_ptr << " - " << *x_ptr << " = " << *result_ptr << endl;
    }
    catch(bad_alloc &memoryAlloc)
    {
        cerr << "Exception: " << memoryAlloc.what() << endl;
    }
    return 0;
}

//  positive x:
//  x + y;  z - x;

//  negtive x;
//  y - x;  z + x