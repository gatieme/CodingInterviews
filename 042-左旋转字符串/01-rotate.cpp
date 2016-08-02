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
        /// 012345678
        /// abcXYZdef
        /// XYZdefabc
        /// 012345678
        ///
        /// res[i] = str[(i + n) % str.size( )];
        /// res[(i - n + str.size( )) % str.size()] = str[i];

        string res(str);
        if(n > str.size( ))
        {
            n %= str.size( );
        }
        debug <<"length = " <<str.size( ) <<", n = " <<n <<endl;
        for(int i = 0; i < str.size( ); i++)
        {
            debug <<"i = " <<i <<", ori = " <<((i + n) % str.size( )) <<endl;
            res[i] = str[(i + n) % str.size( )];
        }

        return res;
    }

    string Reverse(string str)
    {
        int left = 0, right = str.size( ) - 1;

        while(left < right)
        {
            swap(str[left], str[right]);
            left++;
            right--;
        }

        return str;
    }
};


int __tmain( )
{
    Solution solu;

    cout <<solu.LeftRotateString("abcXYZdef", 3) <<endl;

    return 0;
}
