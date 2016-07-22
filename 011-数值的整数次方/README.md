#链接 ------- 
>牛客OJ：[数值的整数次方](http://www.nowcoder.com/practice/1a834e5e3e1a4b7ba251417554e07c00?tpId=13&tqId=11165&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
> 
>九度OJ：http://ac.jobdu.com/problem.php?pid=1514
> 
>GitHub代码： [011-数值的整数次方](https://github.com/gatieme/CodingInterviews/tree/master/011-数值的整数次方)
>
>CSDN题解：[剑指Offer--011-数值的整数次方](http://blog.csdn.net/gatieme/article/details/51123043)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 | 
| ------------- |:-------------:| -----:| 
|[数值的整数次方](http://www.nowcoder.com/practice/1a834e5e3e1a4b7ba251417554e07c00?tpId=13&tqId=11165&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking) | [1514-数值的整数次方](http://ac.jobdu.com/problem.php?pid=1514) | [剑指Offer--011-数值的整数次方](http://blog.csdn.net/gatieme/article/details/51123043) | [011-数值的整数次方](https://github.com/gatieme/CodingInterviews/tree/master/011-数值的整数次方)|

<br>
**您也可以选择[回到目录-剑指Offer--题集目录索引](http://blog.csdn.net/gatieme/article/details/51916802)**




#题意

-------

**题目描述**



>给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

#自以为很简单的解法
-------
```cpp
class Solution
{
public:
    double Power(double base, int exponent)
    {
        double res = 1;
        for(int i = 0; i < exponent; i++)
        {
            res *= base;
        }

        return res;
    }
};
```

貌似我们已经完美的解决了问题，但是真的这样么？
我们输入一个指数为负数的情况
```cpp
    Solution solu;
    cout <<solu.Power(2, -3) <<endl;
```


可见我们的算法是多么的自以为是啊？


#简单的处理边界的情况（全面但是不够高效）
-------

前面所说的指数为负数只是边界的一种情况，学习算法，必须全面了解所有的边界

指数幂的所有边界包括

*    指数为0的情况，不管底数是多少都应该是1

*    指数为负数的情况，求出的应该是其倒数幂的倒数

*    指数为负数的情况下，底数不能为0

```cpp
#include <iostream>
#include <cmath>
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
    double Power(double base, int exponent)
    {
        //  指数为0的情况，不管底数是多少都应该是0
        if(exponent == 0)
        {
            return 1.0;
        }
        //  指数为负数的情况下，底数不能为0
        if(Equal(base, 0.0) == true && exponent < 0)
        {
            debug <<"异常, 指数为负数的情况下，底数不能为0" <<endl;
            return 0.0;
        }

        double res = 1.0;
        if(exponent > 0.0)
        {
            res = PowerNormal(base, exponent);
        }
        else
        {
            res = PowerNormal(base, -exponent);
            res = 1 / res;
        }

        return res;
    }

private :
    double PowerNormal(double base, int exponent)
    {

        double res = 1;
        for(int i = 0; i < exponent; i++)
        {
            res *= base;
        }

        return res;

    }
    double Equal(double left, double right)
    {
        if(fabs(left - right) <  0.0000001)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};



int __tmain( )
{
    Solution solu;

    cout <<solu.Power(2, 0) <<endl;
    cout <<solu.Power(2, -3) <<endl;
    return 0;
}

```


#位运算（全面而且高效的算法）
-------
那么还有没有更加快速的办法呢？

别急，我们慢慢来分析

1.    写出指数的二进制表达，例如13表达为二进制1101。

2.    举例:10^1101 = 10^0001*10^0100*10^1000。

3.    通过&1和>>1来逐位读取1101，为1时将该位代表的乘数累乘到最终结果。

简单明了，看来结果根指数中1的个数和位置有关系，那么就简单了，还记得[剑指Offer--010-二进制中1的个数](http://blog.csdn.net/gatieme/article/details/51122144)

```cpp
double PowerNormal(double base, int exponent)
    {
        if(exponent == 0)
        {
            return 1;
        }
        else if(exponent == 1)
        {
            return base;
        }

        int res = 1, temp = base;
        while(exponent != 0)
        {
            if((exponent & 1) == 1) //  当前指数为不为0
            {
                res *= temp;        //  就计算一个乘积
            }
            //  移位后, curr需要翻倍, 这样到下个
            temp *= temp;           // 翻倍
            exponent >>= 1;         // 右移一位
        }
        return res;
    }
```

当然也可以用递归的写法

```cpp
    double PowerNormal(double base, int exponent)
    {
        if(exponent == 0)
        {
            return 1;
        }
        else if(exponent == 1)
        {
            return base;
        }
        double res = PowerNormal(base, exponent >> 1);
        res *= res;
        if((exponent & 1) == 1)
        {
            res *= base;
        }

        return res;
    }
```