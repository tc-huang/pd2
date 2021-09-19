#include<iostream>
#include"HugeInt.h"
using namespace std;

int main()
{
    HugeInt x; //   + or -
    HugeInt y(28825252);
    HugeInt z("314159265358979323846");
    HugeInt result;

    cout << "type in a num: ";
    cin >> x;
    result = x + y;
    cout << x << " + " << y << " = " << result << endl;

    result = z - x;
    cout << z << " - " << x << " = " << result << endl;

    return 0;
}

//  positive x:
//  x + y;  z - x;

//  negtive x;
//  y - x;  z + x