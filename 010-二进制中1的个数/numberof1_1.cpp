#include <iostream>

using namespace std;

//  µ÷ÊÔ¿ª¹Ø
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain


class Solution
{
public:
    int NumberOf1(int n)
    {
        int count = 0;

        while(n)
        {
            if(n & 1 == 1)
            {
                count++;
            }
            n >>= 1;
            debug <<"right turn 1, n = " <<n <<endl;
        }
        return count;
    }
};


int __tmain( )
{
    Solution solu;
    cout <<solu.NumberOf1(1) <<endl;;
    cout <<solu.NumberOf1(2) <<endl;;
    cout <<solu.NumberOf1(-3) <<endl;;

    return 0;
}
