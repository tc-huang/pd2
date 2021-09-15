#include<vector>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include "Clock.h"
using namespace std;

void insertion_sort(vector<int>& v)
{
    int insert, moveItem;

    for (int next = 1; next < v.size(); ++next)
    {
        insert = v.at(next);
        moveItem = next;

        while((moveItem > 0) && (v.at(moveItem - 1) > insert))
        {
            v.at(moveItem) = v.at(moveItem - 1);
            --moveItem;
        }
        v.at(moveItem) = insert;
    }
}

int main(){
    Clock clk;
    int const size_list[4] = {1000, 10000, 100000, 1000000};
    int len = sizeof(size_list) / sizeof(size_list[0]);

    cout << endl;
    cout << "size\t" << "sort()\t" << "insertion_sort()\t"<< "(time in second)" << endl;

    for (int const *size_ptr = size_list; size_ptr < size_list + len; ++size_ptr)
    {
        vector<int> v1, v2;
        srandom(time(NULL));
        
        for (int i = 0; i < *size_ptr; ++i)
            v1.push_back(random());
        
        v2 = v1;
        cout << *size_ptr << "\t\t";

        clk.start();
        sort(v1.begin(), v1.end());
        cout << clk.getElapsedTime() << "\t\t";
        clk.start();
        insertion_sort(v2);
        cout << clk.getElapsedTime() << endl;
    }
    return 0;
}