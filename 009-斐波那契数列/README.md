#链接
------- 

>牛客OJ：[斐波那契数列](http://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&tqId=11160&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-rankingg) 
>
>九度OJ：http://ac.jobdu.com/problem.php?pid=1387
>
>GitHub代码： [009-斐波那契数列](https://github.com/gatieme/CodingInterviews/tree/master/009-%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E6%95%B0%E5%88%97)
>
>CSDN题解：[剑指Offer--009-斐波那契数列](http://blog.csdn.net/gatieme/article/details/51115810)



| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 |
| ------------- |:-------------:| -----:|
|[斐波那契数列](http://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&tqId=11160&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-rankingg)  | [1387-斐波那契数列](http://ac.jobdu.com/problem.php?pid=1387)   | [剑指Offer--009-斐波那契数列](http://blog.csdn.net/gatieme/article/details/51115810) | [009-斐波那契数列](https://github.com/gatieme/CodingInterviews/tree/master/009-%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E6%95%B0%E5%88%97)|



>参考：
>
>[剑指Offer面试题9（java版）斐波那契数列](http://blog.csdn.net/jsqfengbao/article/details/47121489)
>
>[O(logn)时间复杂度求Fibonacci数列](http://blog.csdn.net/dadoneo/article/details/6776272)
>
>[剑指offer第9题及扩展 斐波那契数列](http://www.xuebuyuan.com/1959920.html)


#题意

-------

题目描述


大家都知道斐波那契数列，
现在要求输入一个整数n，
请你输出斐波那契数列的第n项。

#递推公式
-------
我们很容易的想到了递推公式$f(n) =$ 
*    $=0, 当n=0$
*    $=1, 当n=1$
*    $=f(n - 1) + f(n - 2), 其他$
因此我们马上想到了如下递归代码
```cpp
    int Fibonacci(int n)
    {
        if(n <= 1)
        {
            return n;
        }
        else
        {
            return Fibonacci(n - 1) + Fibonacci(n - 2);
        }
    }
```
但是很抱歉StackOverFlow了。
事实上，用递归的方法计算的时间复杂度是以n的指数的方式递增的。读者不妨求Fibonacci的第100项..

#递归展开--迭代方法$O(N)$
-------
因此我们只能用最普通的方法，将递推公式进行展开
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
    int Fibonacci(int n)
    {
        if(n <= 1)
        {
            return n;
        }
        long one = 0;
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
    cout <<solu.Fibonacci(3) <<endl;;

    return 0;
}

```

这个算法这还不是最快的方法。下面介绍一种时间复杂度是O(logn)的方法。

#时间复杂度是O(logn)的但是不够实用的算法
-------

在介绍这种方法之前，先介绍一个数学公式：

{f(n), f(n-1), f(n-1), f(n-2)} ={1, 1, 1,0}n-1

(注：{f(n+1), f(n), f(n), f(n-1)}表示一个矩阵。在矩阵中第一行第一列是f(n+1)，第一行第二列是f(n)，第二行第一列是f(n)，第二行第二列是f(n-1)。)

有了这个公式，要求得f(n)，我们只需要求得矩阵{1, 1, 1,0}的n-1次方，因为矩阵{1, 1, 1,0}的n-1次方的结果的第一行第一列就是f(n)。这个数学公式用数学归纳法不难证明。感兴趣的朋友不妨自己证明一下。

现在的问题转换为求矩阵{1, 1, 1, 0}的乘方。如果简单第从0开始循环，n次方将需要n次运算，并不比前面的方法要快。但我们可以考虑乘方的如下性质：

```

        /  an/2*an/2                      n为偶数时
an=
        \  a(n-1)/2*a(n-1)/2            n为奇数时

```



要求得n次方，我们先求得n/2次方，再把n/2的结果平方一下。如果把求n次方的问题看成一个大问题，把求n/2看成一个较小的问题。这种把大问题分解成一个或多个小问题的思路我们称之为分治法。这样求n次方就只需要logn次运算了。

实现这种方式时，首先需要定义一个2×2的矩阵，并且定义好矩阵的乘法以及乘方运算。当这些运算定义好了之后，剩下的事情就变得非常简单。完整的实现代码如下所示。





原理：
观察: a(n)  = a(n - 1) + a(n - 2)
                  = 2 * a(n - 2) + a  (n - 3)
                  = 3 * a(n - 3) + 2 * a(n - 4)
                  = 5 * a(n - 4) + 3 * a(n - 5)
                  = ... ...
                  = a(k)  *  a(n - k + 1) + a(k - 1) * a(n - k)
1、若令 n = 2k
     得 a(2k) = a(k)  * a(k + 1) + a(k-1) * a(k)
                   = a(k) * [a(k) + a(k - 1)] + a(k-1) * a(k)
                   = a(k) ^ 2 + 2 * a(k)  *  a(k - 1) 
2、若令 n = 2k - 1 
     得 a(2k - 1) = a(k) * a(k) + a(k - 1)  * a(k - 1) 
                         = a(k)  ^ 2 +  a(k - 1) ^ 2



代码如下

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

```
