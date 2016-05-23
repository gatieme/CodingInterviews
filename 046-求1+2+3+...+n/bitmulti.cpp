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
    int res;
    int Sum_Solution(int n)
    {
        res = 0;
        return (MultiRecursion(n, n + 1) >> 1);
    }



    int MultiRecursion(int a, int b)
    {
        a && MultiRecursion(a >> 1, b << 1);    //  递归的进行运算

        (a & 1) && (res += b);                  //  短路


        return res;
    }

};
// 5 4 3 2 1
int __tmain(void)
{
    Solution solu;
    cout <<solu.Sum_Solution(3) <<endl;
    cout <<solu.Sum_Solution(5) <<endl;

}
