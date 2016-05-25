#链接
------- 
>牛客OJ：[把字符串转换成整数](http://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&tqId=11202&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
> 
>九度OJ：http://ac.jobdu.com/problem.php?pid=1508
> 
>GitHub代码： [049-把字符串转换成整数](https://github.com/gatieme/CodingInterviews/tree/master/049-把字符串转换成整数)
>
>CSDN题解：[剑指Offer--049-把字符串转换成整数](http://blog.csdn.net/gatieme/article/details/51502651)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 | 
| ------------- |:-------------:| -----:| -----:|
|[049-把字符串转换成整数](http://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&tqId=11202&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | [1508-把字符串转换成整数](http://ac.jobdu.com/problem.php?pid=1508) | [剑指Offer--049-把字符串转换成整数](http://blog.csdn.net/gatieme/article/details/51502651) | [049-把字符串转换成整数](https://github.com/gatieme/CodingInterviews/tree/master/049-把字符串转换成整数) |



>相同题目 [LeetCode题解--8. String to Integer (atoi)](http://blog.csdn.net/gatieme/article/details/51046065)

#题意
-------


**题目描述**

>写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

**样例输入**

>1a33
>
>-2147483648


**样例输出**


>0
>
>-2147483648



#分析
-------

>同样的题目在LeetCode上
>
>相同题目 [LeetCode题解--8. String to Integer (atoi)](http://blog.csdn.net/gatieme/article/details/51046065)



简单问题，如下代码即是主要框架


```
for (; *str != '\0'; str++)
{

    if ('0' <= *str && *str <= '9')
    {
        value *= 10;
        value += *str - '0';
#ifdef DEBUG
        printf("value = %lld\n", value);
#endif
    }
    else
    {
        break;
    }
}
```


但是需要注意的问题，

*   前面的空白字符
```
//  排除前导的空格
while (*str == ' '  || *str == '\n' || *str == '\t')          //  排除前导的空格
{
    str++;
}
```

*   数字前面可能有符号位+/-

```
//  判断符号位+ -
if (*str == '+')
{
    str++;
}
else if (*str == '-')
{
    str++;
    minus = true;
}
```

*   overflow问题

我的解决方案是在循环的过程中，只要一发生溢出就结束
```
//  解决OVER_FLOW的问题
//  INT_MAX     2147483647
//  INT_MIN     -2147483648  minus = true
if((minus == true  && value > (unsigned long)(INT_MAX) + 1)     //  负数绝对值最大为INT_MAX + 1
 || (minus == false && value > INT_MAX))                         //  正数最大值为INT_MAX
{
    debug <<value <<", " <<INT_MAX + 1 <<endl;
    debug <<"to max than int" <<endl;
    break;
 }
```


如果最后再判断可能出现的问题，因为不管我们value用什么保存，long,long long，他们都有表示范围，都存在溢出，字符串过长时都会溢出，溢出后可能会发生截断，或者甚至读取成一个负数，那么我们循环结束后再判断就不可行。


分析的已经很好了，我们直接上代码吧


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
    int StrToInt(string str)
    {
        string::iterator pstr = str.begin( );
        //  排除前导的空格
        while (*pstr == ' ')          //  排除前导的空格
        {
            pstr++;
        }

        bool minus = false;

        //  判断符号位+ -
        if (*pstr == '+')
        {
            pstr++;
        }
        else if (*pstr == '-')
        {
            pstr++;
            minus = true;
        }


        long long int value = 0;
        for (; pstr != str.end( ); pstr++)
        {
            if ('0' <= *pstr && *pstr <= '9')
            {
                value *= 10;
                value += *pstr - '0';
                debug <<"value = "<<value <<endl;
            }
            else
            {
                break;
            }

            //  解决OVER_FLOW的问题
            //  INT_MAX     2147483647
            //  INT_MIN     -2147483648  minus = true
            if((minus == true  && value > (unsigned long)(INT_MAX) + 1)     //  负数绝对值最大为INT_MAX + 1
            || (minus == false && value > INT_MAX))                         //  正数最大值为INT_MAX
            {
                debug <<value <<", " <<INT_MAX + 1 <<endl;
                debug <<"to max than int" <<endl;
                break;
            }

        }
        if(pstr != str.end( ))
        {
            return 0;
        }
        else
        {

            if (minus == true)
            {
                value = -value;
            }

            if (value >= INT_MAX)
            {
                value = INT_MAX;
            }
            else if (value <= INT_MIN)
            {
                value = INT_MIN;
            }

            return (int)value;

        }
    }
};


int __tmain(void)
{
    Solution solu;
    cout <<"INT_MAX" <<INT_MAX <<endl;
    cout <<"INT_MIN" <<INT_MIN <<endl;
    cout <<solu.StrToInt("1a33") <<endl;
    cout <<solu.StrToInt("-2147483648") <<endl;


    return EXIT_SUCCESS;
}
```
