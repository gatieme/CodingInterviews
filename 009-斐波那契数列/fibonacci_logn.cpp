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
public :
    static int pre;
    static int post;
    int temp;
    int Fibonacci(int n)
    {
        /**
         * 每次Fibonacci调用结束后:
         *      pre:  存的都是Fibonacci(n)的值
         *      post: 存的都是Fibonacci(n-1)的值
         */

        // if   n = 0            #=> 0
        // else n = 1 || n = 2   #=> 1
        if(n <= 2)
        {
            if (n == 0) return 0;
            pre = 1;
            post = 1;
            return pre;
        }

        // n 为奇数， 则做减一操作， 函数回调时
        //        pre：        f(n) = f(n - 1) + f(n - 2)
        //        post：   f(n - 1) = f(n) - f(n - 2)
        if(n%2 == 1)
        {
            Fibonacci(n-1);
            pre = pre + post;
            post = pre - post;
            return pre;
        }

        // n为偶数时不断除二
        // 函数回调时,f(n) 通过 f(n/2) 来计算:
        //
        //  设 n = 2k：
        //          f(2k) = f(k)  * f(k + 1) + f(k-1) * f(k)
        //                = f(k) * [f(k) + f(k - 1)] + f(k-1) * f(k)
        //                = f(k) ^ 2 + 2 * f(k) * f(k - 1)
        // 设 n = 2k-1：
        //      f(2k - 1) = f(k) * f(k) + f(k - 1)  * f(k - 1)
        //                = f(k)^2 + f(k - 1)^2
        //
        Fibonacci(n/2);
        temp = pre;
        // f(2k) = f(k)^2 + 2 * f(k) * f(k - 1)
        pre = pre * pre + 2 * pre * post;
        // f(2k - 1) = f(k) * f(k) + f(k - 1) * f(k - 1)
        post = temp*temp + post*post;
        return pre;
    }
};

int Solution::pre = 0;
int Solution::post = 0;


int __tmain( )
{
    Solution solu;
    cout <<solu.Fibonacci(3) <<endl;;

    return 0;
}
