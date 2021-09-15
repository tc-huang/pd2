#include<fstream>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int main(){
    int num = 0, total = 0, tmp = 0;
    vector<int> weights;
    
    ifstream inFile("file.in", ios::in);
    if(!inFile)
    {
        cerr << "Failed to open file.in" << endl;
        exit(-1);
    }
    
    inFile >> num;
    
    for (int i = 0; i < num; ++i)
    {
        inFile >> tmp;
        weights.push_back(tmp);
    }

    sort(weights.begin(), weights.end());
    for (int i = num - 1; i >= num - 5; --i)
        total += weights.at(i);

    cout << total << endl;
    return 0;
}