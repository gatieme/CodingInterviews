#链接 ------- 
>牛客OJ：[二进制中1的个数](http://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8?tpId=13&tqId=11164&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
> 
>九度OJ：http://ac.jobdu.com/problem.php?pid=1513
> 
>GitHub代码： [010-二进制中1的个数](https://github.com/gatieme/CodingInterviews/tree/master/010-二进制中1的个数) 
>
>CSDN题解：[剑指Offer--010-二进制中1的个数](http://blog.csdn.net/gatieme/article/details/51122144)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 | 
| ------------- |:-------------:| -----:| 
|[二进制中1的个数](http://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&tqId=11160&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-rankingg) | [1513-二进制中1的个数](http://ac.jobdu.com/problem.php?pid=1513) | [剑指Offer--010-二进制中1的个数](http://blog.csdn.net/gatieme/article/details/51122144) | [010-二进制中1的个数](https://github.com/gatieme/CodingInterviews/tree/master/010-二进制中1的个数)|

<br>
**您也可以选择[回到目录-剑指Offer--题集目录索引](http://blog.csdn.net/gatieme/article/details/51916802)**



#题意

-------

**题目描述**


>输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

**样例输入**

>3
>4
>5
>-1

**样例输出**

>1
>2
>32



#通过移位测试每一位
-------
我们很容易想到的算法就是

通过移位的方法，挨个判断其每一位

```cpp
class Solution
{
public:
    int NumberOf1(int n)
    {
        int count = 0;

        while(n)
        {
            if(n & 1 == 1)
            {
                count++;
            }
            n >>= 1;
        }
        return count;
    }
};
```

但是这个算法有致命的缺陷，我们假设通过移位的方式可以获取到其每一位，但是并不总是对的

##逻辑右移与算术右移
-------

比如一个有符号位的8位二进制数11001101，逻辑右移就不管符号位，如果移一位就变成01100110。算术右移要管符号位，右移一位变成10100110。

*    逻辑左移=算数左移，右边统一添0
*    逻辑右移，左边统一添0
*    算数右移，左边添加的数和符号有关


>e.g:1010101010，其中[]位是添加的数字
>
>逻辑左移一位：010101010[0]
>
>算数左移一位：010101010[0]
>
>逻辑右移一位：[0]101010101
>
>算数右移一位：[1]101010101

因此如果输入负数，那么我们的算法简单的判断是不是0来终结，岂不是要死循环

#避免负数移位的死循环
-------

为了负数时候避免死循环，我们可以**不右移数字n，转而去移动测试位**

那么思考我们的循环结束条件，flag一直左移（乘以2），当超出表示标识范围的时候，我们就可以终止了，但是这样子的话，最高位的符号位没有测试，因此要单独测试，同时由于会溢出，我们的flag需要用long来标识

| 类型 | 范围 |
| ------------- |:-------------:|
|unsigned   int   | 0～4294967295   |
| int  | 2147483648～2147483647 |
| unsigned long |0～4294967295|
| long   |2147483648～2147483647|
| long long|最大值：9223372036854775807|
| long long|最小值：-9223372036854775808|
| unsigned long long|最大值：1844674407370955161|
| __int64|最大值：9223372036854775807|
| __int64|最小值：-9223372036854775808|
| unsigned __int64|最大值：18446744073709551615


代码如下

```cpp
class Solution
{
public:
    int NumberOf1(int n)
    {
        int count = 0;
        int i = 0;
        unsigned long flag = 1;

        while(flag <= INT_MAX)
        {
            debug <<n <<" & " <<flag <<" == "<<(n & flag) <<endl;
            if((n & flag) != 0)
            {
                count++;
            }
            flag <<= 1;
        }

        //  由于循环终结，我们使用的是flag <= INT_MAX
        //  因此前面的循环只会执行31次
        if((n & flag) != 0)    //  最后测试符号位
        {
            count++;
        }

        return count;
    }

};
```

继续考虑，有没有什么能够精简我们的循环条件,
考虑这点，如果数据发生溢出的话，会被截断，截断以后是多少呢，0
代码如下
```cpp
class Solution
{
public:
    int NumberOf1(int n)
    {
        int count = 0;
        int i = 0;
        unsigned int flag = 1;

        while(flag != 0)
        {
            debug <<n <<" & " <<flag <<" == "<<(n & flag) <<endl;
            if((n & flag) != 0)
            {
                count++;
            }
            flag <<= 1;
        }
        debug <<n <<" & " <<flag <<" == "<<(n & flag) <<endl;

        return count;
    }

};
```

这种方法循环的次数正好是是整数二进制数的位数，比如int就是32位循环32次

那么有没有一种方法，整数中有几个1就循环几次呢？

#整数中有几个1就循环几次--lowbit优化
-------

我们分析n以n-1两个数的差别，

*    如果n!=0，那么其二进制位中至少有一个1

*    如果n的最低位是1（奇数），那么n-1正好把这个最低位的1变成0，其他位不变

*    如果n的最低位是0（偶数），那么假设其右起第一个1位于m位，即m位后面全是0，那么n-1的第m位由1变成0，而第m位后面的所有0均变成1，m位之前的所有位保持不变。

因此通过分析发现：

**把一个整数n减去1，再和原来的整数做与运算，会把该整数最右边一个1变成0，那么该整数有多少个1，就会进行多少次与运算**

即循环的次数，即二进制中1的个数

>如果一个整数不为0，那么这个整数至少有一位是1。如果我们把这个整数减1，那么原来处在整数最右边的1就会变为0，原来在1后面的所有的0都会变成1(如果最右边的1后面还有0的话)。其余所有位将不会受到影响。
>举个例子：一个二进制数1100，从右边数起第三位是处于最右边的一个1。减去1后，第三位变成0，它后面的两位0变成了1，而前面的1保持不变，因此得到的结果是1011.我们发现减1的结果是把最右边的一个1开始的所有位都取反了。这个时候如果我们再把原来的整数和减去1之后的结果做与运算，从原来整数最右边一个1那一位开始所有位都会变成0。如1100&1011=1000.也就是说，把一个整数减去1，再和原整数做与运算，会把该整数最右边一个1变成0.那么一个整数的二进制有多少个1，就可以进行多少次这样的操作。


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
    int NumberOf1(int n)
    {
        int count = 0;
        while(n)
        {
            count++;
            n = n & (n - 1);
        }

        return count;
    }

};


#include <cmath>

int __tmain( )
{
    cout <<sizeof(long) <<endl;
    Solution solu;
    cout <<solu.NumberOf1(1) <<endl;;
    cout <<solu.NumberOf1(2) <<endl;;
    cout <<solu.NumberOf1(-2147483648) <<endl;;

    return 0;
}

```

#STL-bitset
-------
STL中用来方便地管理一系列的bit位而不用程序员自己来写代码。
bitset除了可以访问指定下标的bit位以外，还可以把它们作为一个整数来进行某些统计

```cpp
class Solution
{
public:
    int NumberOf1(int n)
    {
        bitset<32> bit(n);
        return bit.count();

    }

};
```






