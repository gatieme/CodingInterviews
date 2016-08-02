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
        Reverse(str.begin( ), str.begin( ) + n - 1);
        Reverse(str.begin( ) + n, str.end( ) - 1);
        Reverse(str.begin( ), str.end( ) - 1);

        return str;
    }

    void Reverse(string::iterator left, string::iterator right)
    {
        while(left < right)
        {
            debug <<*left <<", " <<*right <<endl;
            swap(*left, *right);

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
