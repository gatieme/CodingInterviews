#include <iostream>

using namespace std;

//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain


class Solution
{
public:
    string LeftRotateString(string str, int n)
    {
        /// abcXYZdef
        /// abcXYZdefabcXYZdef
        /// 012345678
        /// 新的串是两倍串第len位起始长度为n字串
        int length = str.size( );

        if(length == 0)
        {
            return "";
        }
        n = n % len;
        str += str;

        return str.substr(n, len);
    }
};


int __tmain( )
{
    Solution solu;

    cout <<solu.LeftRotateString("abcXYZdef", 3) <<endl;

    return 0;
}
