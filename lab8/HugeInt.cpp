#include "HugeInt.h"
#include<iostream>
#include<string>
#include<algorithm> //  for reverse
using namespace std;


ostream &operator <<(ostream &out, const HugeInt& target)
{
    out << target.value;
    return out;
}
istream &operator >>(istream &in, HugeInt& target)
{
    in >> target.value;
    return in;
}


HugeInt::HugeInt(){}
HugeInt::HugeInt(long long num):value(to_string(num)){}
HugeInt::HugeInt(string num_s):value(num_s){}

const HugeInt& HugeInt::operator=(const HugeInt& right)
{
    this->value = right.value;
    return *this;
}


string str_add(string s1, string s2)
{
    if(s1.length() < s2.length())
        s1.swap(s2);

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    for(int i = 0; i < s2.length(); ++i)
        s1.at(i) += s2.at(i) - '0';
    
    int over_9 = '0' + 9;

    for(int i = 0; i < s1.length() - 1; ++i)
    {
        if(s1.at(i) > over_9)
        {
            s1.at(i) = s1.at(i) - 10;
            ++s1.at(i + 1);    
        }
    }

    if(s1.at(s1.length() - 1) > over_9)
    {
        s1.at(s1.length() - 1) -= 10;
        s1.append("1");
    }

    for(int i = s1.length() - 1; i >= 0; --i)
    {
        if(s1.at(i) > 0)
        {
            s1.erase(i + 1, s1.length());
            break;
        }
    }

    reverse(s1.begin(), s1.end());
    return s1;
}

const HugeInt HugeInt::operator+(const HugeInt& right)
{
     
    
    if(this->value.at(0) == '-')
        return HugeInt::operator-(right);

    HugeInt tmp;
    string r_value;
    int r_len = 0;
    
    if (right.value.at(0) == '-')
    {
        r_len = right.value.length() - 1;
        r_value = right.value.substr(1, r_len);
    }
    else
        r_value = right.value; 
    tmp.value = str_add(this->value, r_value);     
    return tmp;
}


int compare(string s1, string s2)
{
    int result = -1; // 0:s1 and s2 equal; 1: s1 larger; 2: s2 larger; 
    int len_s1 = 0, len_s2 = 0;
    
    len_s1 = s1.length();
    len_s2 = s2.length();

    if(len_s1 > len_s2)
        return 1;
    else if(len_s1 < len_s2)
        return 2;
    else
    {
        for(int i = 0; i < len_s1; ++i)
        {
            if(s1.at(i) > s2.at(i))
                return 1;
            else if(s1.at(i) < s2.at(i))
                return 2;
        }
        return 0;
    }
}

string str_sub(string s1, string s2)
{
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int diff = 0;
    for(int i = 0; i < s1.length(); ++i)
    {
        if(i < s2.length())
        {
            diff = s1.at(i) - s2.at(i);
            if(diff < 0)
            {
                s1.at(i) = diff + '0' + 10;
                --s1.at(i + 1);
            }
            else
                s1.at(i) = diff + '0';
        }
        else if(s1.at(i) < '0')
        {
            s1.at(i) += 10;
            --s1.at(i + 1); 
        } 
    }

    for(int i = s1.length() - 1; i >= 0; --i)
    {
        
        if(s1.at(i) > '0')
        {
            s1.erase(i + 1, s1.length());
            break;
        }
    }
    reverse(s1.begin(), s1.end());
    return s1;
}

const HugeInt HugeInt::operator-(const HugeInt& right)
{   
    if(right.value.at(0) == '-')
        return HugeInt::operator+(right);

    HugeInt tmp;

    string r_value, l_value;

    int r_len, l_len;
    r_value = right.value;
    
    if (this->value.at(0) == '-')
    {
        l_len = this->value.length() - 1;
        l_value = this->value.substr(1, l_len);
        l_value.swap(r_value);
    }
    else
        l_value = this->value;    
    
    r_len = r_value.length();
    l_len = l_value.length(); 
    switch(compare(l_value, r_value))
    {
        case 0: //  l_value, r_value equal
            tmp.value = "0";
            break;
        case 1: //  l_value larger
            tmp.value = str_sub(l_value, r_value) ;
            break;
        case 2: //  r_value larger
            tmp.value = str_sub(r_value, l_value).insert(0, "-");
            break;
    }
    return tmp;
}