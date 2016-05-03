#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain



template<class T>
string ToString(const T& t)
{

    ostringstream oss;  //  创建一个流

    oss <<t;            //  把值传递如流中
    return oss.str( );  //  获取转换后的字符转并将其写入result
}

class Compare
{

public:

bool operator( )(string &left, string &right)
{
    string leftright = left + right;
    string rightleft = right + left;
    if(leftright > rightleft)
    {
        debug <<leftright <<" > " <<rightleft <<" -- " <<rightleft <<endl;
    }
    else
    {
        debug <<leftright <<" < " <<rightleft <<" -- " <<leftright <<endl;
    }

    return leftright < rightleft;
}

};
class Solution
{
public:


    string PrintMinNumber(vector<int> numbers)
    {
        string res = "";

        vector<string> strNum;
        string str;
        for(unsigned int i = 0; i < numbers.size( ); i++)
        {
            str = ToString(numbers[i]);
            strNum.push_back(str);
            debug <<str <<endl;
        }

        sort(strNum.begin( ), strNum.end( ), Compare());

        for(unsigned int i = 0; i < strNum.size( ); i++)
        {
            debug <<strNum[i];
            res += strNum[i];
        }
        debug <<endl;
        return res;
    }
};


int __tmain( )
{
    Solution solu;

    int arr[] = { 321, 32, 3 };
    vector<int> vec(arr, arr + 3);
    cout <<solu.PrintMinNumber(vec) <<endl;
    return 0;
}
