#ifndef HUGEINT_H
#define HUGEINT_H

#include <string>
using namespace std;

class HugeInt
{
    friend istream &operator>>(istream&, HugeInt&);
    friend ostream &operator<<(ostream&, const HugeInt&);
    
    public:
        HugeInt();
        HugeInt(long long);
        HugeInt(string);

        const HugeInt & operator=(const HugeInt &);
        const HugeInt operator+(const HugeInt &);
        const HugeInt operator-(const HugeInt &);
    
    private:
       string value;
};
#endif