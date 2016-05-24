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
    int Add(int left, int right)
    {
        __asm__ __volatile__
        (
            //"lock;\n"
            "addl %1,%0;\n"     /* 相当于 add b, a结果存储在a中*/
            : "=m"(left)
            : "r"(right), "m"(left)
          //  :
        );

        return left;
    }
};

int __tmain( )
{
    Solution solu;


    cout <<solu.Add(3, 5) <<endl;
    return 0;
}
