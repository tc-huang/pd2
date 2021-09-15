#include<iostream>
#include<fstream>
#include "calculate.h"

using namespace std;

int main(){
    ifstream inFile("file_in", ios::in);
    if(!inFile)
    {
        cerr << "Failed to open file_in" << endl;
        exit(1);
    }
    ofstream outFile("file_out", ios::out);
    if(!outFile)
    {
        cerr << "Failed to open file_out" << endl;
    }

    int ra, rb, k;
    double scoreA;
    Rating Record;
    inFile >> k >> ra >> rb;
    Record.setRnK(ra, rb, k);
    outFile << ra << " " << rb << "\n\n";

    while(inFile >> scoreA)
    {
        Record.calculateR(scoreA);
        outFile << Record.getRA() << " " << Record.getRB() << "\n\n";
    }
}