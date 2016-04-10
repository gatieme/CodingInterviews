
#扩展三--矩形覆盖
-------

##题目描述
-------

我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

##分析
-------
2*n的矩形方法数定义为f(n). 

第一个2*1的小矩形覆盖大矩形的左边，

*	要么竖着放，转化成f(n-1),

*	要么横着放两次，转化成f(n-2), 

因此f(n) = f(n-1) + f(n-2)

*	1 n = 0

*	1 n = 1

*	f(n - 1) + f(n - 2)


##代码
-------

```cpp
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
        long two = 1;
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
```