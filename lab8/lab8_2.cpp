#include <iostream>
using namespace std;
int main(){
    try{
        throw static_cast<float>(3.0);
    }catch(float){
        cout << "exception caught" << endl;
    }
    cout << "I love C++" << endl;
    return 0;
}