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
    int rectCover(int n)
    {
        if(n  == 0)
        {
            return 1;
        }
        else if(n == 1)
        {
            return 1;
        }

        long one = 1;
        long two = 1;;
        long res = 0;

        for(int i = 2; i <= n; i++)
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
    cout <<solu.rectCover(2) <<endl;;

    return 0;
}
