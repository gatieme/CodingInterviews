#链接
-------


Leetcode题目:https://leetcode.com/problems/string-to-integer-atoi/

Github题解 : https://github.com/gatieme/LeetCode

CSDN解题：http://blog.csdn.net/gatieme/article/details/51046065

#题目
-------

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.


将一个字符串表示的数字的转换成整数类型

#分析
-------


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

#前面的空白字符
-------
```
//  排除前导的空格
while (*str == ' '  || *str == '\n' || *str == '\t')          //  排除前导的空格
{
    str++;
}
```

#数字前面可能有符号位+/-
-------

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

#overflow问题
-------

我的解决方案是在循环的过程中，只要一发生溢出就结束
```
//  解决OVER_FLOW的问题
if(value > INT_MAX)
{
    break;
}
```

如果最后再判断可能出现的问题，因为不管我们value用什么保存，long,long long，他们都有表示范围，都存在溢出，字符串过长时都会溢出，溢出后可能会发生截断，或者甚至读取成一个负数，那么我们循环结束后再判断就不可行。


