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
    int Sum_Solution(int n)
    {
        return 0;
    }

    int SumRecursion(int n)
    {
        int ans = n;
        debug <<ans <<endl;
        ans && (ans += SumRecursion(n - 1));
        return ans;
    }
};


int __tmain( )
{
    Solution solu;
    cout <<solu.SumRecursion(3) <<endl;
    cout <<solu.Sum(3) <<endl;




    return 0;
}
