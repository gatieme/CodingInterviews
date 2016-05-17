#include <iostream>
#include <vector>
#include <iterator>

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
    int LastRemaining_Solution(unsigned int n, unsigned int m)
    {
        if(n < 1 || m < 1)
        {
            return -1;
        }
        else if(n == 1)
        {
            return 0;
        }
        else
        {
            // F[n] = (F[n - 1] + m) % n
            return (LastRemaining_Solution(n - 1, m) + m) % n;
        }
    }
};

int __tmain( )
{
    Solution solu;
    /*
    0 1 2 3 4 -=> 1 leave, last = 0, m = 2, step = 2,
    0 2 3 4   -=> 3 leave, last = 0, m = 2, step = 3,
    0 2 4     -=> 0 leave, last = 2, m = 2, step = 4,
    2 4       -=> 4 leave
    2         -=> 2 win
    */
    cout <<solu.LastRemaining_Solution(5, 2) <<endl;

    //cout <<solu.LastRemaining_Solution(8, 5) <<endl;;

    //cout <<solu.LastRemaining_Solution(6, 6) <<endl;;

    return 0;
}
