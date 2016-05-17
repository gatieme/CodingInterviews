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

        int last = 0;
        debug <<"F[" <<0 <<"] = " <<last <<endl;

        for(int step = 2; step <= n; step++)
        {
            last = (last + m) % step;
            debug <<"F[" <<step - 1 <<"] = " <<last <<endl;
        }
        return last;
    }
};

int __tmain( )
{
    Solution solu;
    /*
    0 1 2 3 4 -=> 1 leave, last = 0, m = 2, step = 2, last = 0
    0 2 3 4   -=> 3 leave, last = 0, m = 2, step = 3, last = 2
    0 2 4     -=> 0 leave, last = 2, m = 2, step = 4, last = 0
    2 4       -=> 4 leave, last = 0, m = 2, step = 5, last = 2
    2         -=> 2 win
    */
    cout <<solu.LastRemaining_Solution(5, 2) <<endl;

    /*
    [0]  1  2 3 [4] 5 6 7 -=> 4 leave
     0  [1] 2 3 [5] 6 7   -=> 1 leave
     0  [2] 3  5 6 [7]    -=> 7 leave
    [0]  2  3  5 [6]      -=> 6 leave
    [0]  2  3  5          -=> 0 leave
    [2] [3] 5             -=> 3 leave
     2 [5]                -=> 5 leave
     2
    */
    cout <<solu.LastRemaining_Solution(8, 5) <<endl;;

    //cout <<solu.LastRemaining_Solution(6, 6) <<endl;;

    return 0;
}
