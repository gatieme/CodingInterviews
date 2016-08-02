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
        if(str.size( ) == 0)
        {
            return "";
        }
        n %= str.size( );

        Reverse(str, 0, n - 1);
        Reverse(str, n, str.size( ) - 1);
        Reverse(str, 0, str.size( ) - 1);

        return str;
    }

    void Reverse(string &str, int left, int right)
    {
        while(left < right)
        {
            swap(str[left], str[right]);

            left++;
            right--;
        }
    }
};


int __tmain( )
{
    Solution solu;

    cout <<solu.LeftRotateString("abcXYZdef", 3) <<endl;

    return 0;
}
