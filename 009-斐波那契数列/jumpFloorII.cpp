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

public :
    int jumpFloorII(int target)
    {
        if (target <= 0)
        {
            return -1;
        }
        else if (target == 1)
        {
            return 1;
        }
        else
        {
            return 2 * jumpFloorII(target - 1);
        }
    }
};



int __tmain( )
{
    Solution solu;
    cout <<solu.JumpFloorII(2) <<endl;;

    return 0;
}
