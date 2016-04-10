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
    int jumpFloor(int n)
    {
        if(n <= 2)
        {
            return n;
        }
        long one = 1;
        long two = 2;;
        long res = 0;

        for(int i = 3; i <= n; i++)
        {
            res = one + two;

            one = two;
            two = res;
        }

        return res;
    }


};

int __tmain( )
{
    Solution solu;
    cout <<solu.jumpFloor(2) <<endl;;

    return 0;
}
