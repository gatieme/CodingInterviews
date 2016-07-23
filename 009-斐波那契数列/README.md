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

<br>
**您也可以选择[回到目录-剑指Offer--题集目录索引](http://blog.csdn.net/gatieme/article/details/51916802)**


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


#扩展一--跳台阶
-------

##题目描述
-------

一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。



##分析
-------



每次只能跳一级或者跳两级，那么调N个台阶就可以分解为

*    先跳1级，然后剩余的是跳一个$N - 1$级的台阶，

*    先跳2级，然后剩余的是跳一个$N - 2$级的台阶，



那么它的递推公式为

*    $=0, 当n=0$
*    $=1, 当n=1$
*    $=2, 当n=2$
*    $=f(n - 1) + f(n - 2), 其他$

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
    int jumpFloor(int n)
    {
        if(n <= 2)
        {
            return n;
        }
        long one = 1;
        long two = 2;;
        long res = 0;

        for(int i = 3; i <= n; i++)
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
    cout <<solu.jumpFloor(2) <<endl;;

    return 0;
}

```




#扩展二--变态跳台阶
-------

##题目描述
-------

>一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

##分析
-------
关于本题，前提是n个台阶会有一次n阶的跳法。分析如下:

>f(1) = 1
>f(2) = f(2-1) + f(2-2)         //f(2-2) 表示2阶一次跳2阶的次数。
>f(3) = f(3-1) + f(3-2) + f(3-3) 
>...
>f(n) = f(n-1) + f(n-2) + f(n-3) + ... + f(n-(n-1)) + f(n-n) 
 
说明： 

1.	这里的f(n) 代表的是n个台阶有一次1,2,...n阶的 跳法数。

2.	n = 1时，只有1种跳法，f(1) = 1

3.	n = 2时，会有两个跳得方式，一次1阶或者2阶，这回归到了问题（1） ，f(2) = f(2-1) + f(2-2) 

4.	n = 3时，会有三种跳得方式，1阶、2阶、3阶，
    那么就是第一次跳出1阶后面剩下：f(3-1);第一次跳出2阶，剩下f(3-2)；第一次3阶，那么剩下f(3-3)
    因此结论是f(3) = f(3-1)+f(3-2)+f(3-3)

5.	n = n时，会有n中跳的方式，1阶、2阶...n阶，得出结论：
    f(n) = f(n-1)+f(n-2)+...+f(n-(n-1)) + f(n-n) => f(0) + f(1) + f(2) + f(3) + ... + f(n-1)
    
6.	由以上已经是一种结论，但是为了简单，我们可以继续简化：
    f(n-1) = f(0) + f(1)+f(2)+f(3) + ... + f((n-1)-1) = f(0) + f(1) + f(2) + f(3) + ... + f(n-2)
    f(n) = f(0) + f(1) + f(2) + f(3) + ... + f(n-2) + f(n-1) = f(n-1) + f(n-1)
可以得出：
 $ f(n) = 2*f(n-1)$
    
7.	得出最终结论,在n阶台阶，一次有1、2、...n阶的跳的方式时，总得跳法为：

*	1       ,(n=0 ) 

*	1       ,(n=1 )

*	2*f(n-1),(n>=2)


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
    cout <<solu.jumpFloorII(2) <<endl;;

    return 0;
}

```

或者
```cpp
class Solution
{

public :
    int jumpFloorII(int target)
    {
        if (target <= 0)
        {
            return -1;
        }
        else
        {
            return pow(2, target - 1);
        }
    }
};
```

或者更高效的
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
    int jumpFloorII(int target)
    {
        long long ret;
		if(target >= 32)//大于8字节后，需要分两次移位，否则出错
		{
			ret = 1 << 30;
			ret = ret << (target - 31);
		}
		else
        {
			ret = 1 << (target - 1);
        }

        return ret;
    }
};



int __tmain( )
{
    Solution solu;
    cout <<solu.jumpFloorII(2) <<endl;;

    return 0;
}

```

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
