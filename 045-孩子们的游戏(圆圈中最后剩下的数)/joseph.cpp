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
        for(int step = 2; step <= n; step++)
        {
            last = (last + m) % step;
            debug <<"step = " <<(step - 1) <<", " <<last <<" leave" <<endl;
        }
        return (last);
    }
};

int __tmain( )
{
    Solution solu;

    cout <<solu.LastRemaining_Solution(5, 2) <<endl;

    //cout <<solu.LastRemaining_Solution(8, 5) <<endl;;

    //cout <<solu.LastRemaining_Solution(6, 6) <<endl;;

    return 0;
}
