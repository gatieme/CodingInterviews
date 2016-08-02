#链接
------- 
>牛客OJ：[左旋转字符串](http://www.nowcoder.com/practice/12d959b108cb42b1ab72cef4d36af5ec?tpId=13&tqId=11196&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
> 
>九度OJ：http://ac.jobdu.com/problem.php?pid=1362
> 
>GitHub代码： [042-左旋转字符串](https://github.com/gatieme/CodingInterviews/tree/master/042-左旋转字符串)
>
>CSDN题解：[剑指Offer--042-左旋转字符串](http://blog.csdn.net/gatieme/article/details/51357308)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 |
| ------------- |:-------------:| -----:| -----:|
|[042-左旋转字符串](http://www.nowcoder.com/practice/12d959b108cb42b1ab72cef4d36af5ec?tpId=13&tqId=11196&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | [1362-左旋转字符串](http://ac.jobdu.com/problem.php?pid=1362) | [剑指Offer--042-左旋转字符串](http://blog.csdn.net/gatieme/article/details/51357308) | [042-左旋转字符串](https://github.com/gatieme/CodingInterviews/tree/master/042-左旋转字符串) |



<br>**您也可以选择[回到目录-剑指Offer--题集目录索引](http://blog.csdn.net/gatieme/article/details/51916802)**



#题意
-------

**题目描述**

>汇编语言中有一种移位指令叫做循环左移（ROL）
>
>现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
>对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。

例如，字符序列S=”abcXYZdef”,
要求输出循环左移3位后的结果，即“XYZdefabc”。

是不是很简单？OK，搞定它！


#直接找到旋转后的对应关系
-------
我们可以很明显的发现，将一个字符串循环左移，那么新串和原来串位的对应关系就如下
*    新串i位置的元素，其实是原来串i+n位置的元素，
*    当然i+n如果超过了字符串的长度，就会被循环移位到左侧，即(i+n) % str.size()
*    另外，如果移位n超过了字符串长度，那么只需要移动n%str.size()位即可

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
    string LeftRotateString(string str, int n)
    {
        if(str.size( ) == 0)
        {
            return "";
        }
        /// 012345678
        /// abcXYZdef
        /// XYZdefabc
        /// 012345678
        ///
        /// res[i] = str[(i + n) % str.size( )];
        /// res[(i - n + str.size( )) % str.size()] = str[i];

        string res(str);
        if(n > str.size( ))
        {
            n %= str.size( );
        }
        debug <<"length = " <<str.size( ) <<", n = " <<n <<endl;
        for(int i = 0; i < str.size( ); i++)
        {
            debug <<"i = " <<i <<", ori = " <<((i + n) % str.size( )) <<endl;
            res[i] = str[(i + n) % str.size( )];
        }

        return res;
    }

    string Reverse(string str)
    {
        int left = 0, right = str.size( ) - 1;

        while(left < right)
        {
            swap(str[left], str[right]);
            left++;
            right--;
        }

        return str;
    }
};


int __tmain( )
{
    Solution solu;

    cout <<solu.LeftRotateString("abcXYZdef", 3) <<endl;

    return 0;
}
```

#新串是str+str串第n位到底n+str.size()的字串
-------

这个很好理解，由于是循环移位，那么对于`abcXYZdef`，考虑他的自连接串`abcXYZdefabcXYZdef`，新的串正好是链接串的一个子串

```cpp
class Solution
{
public:
    string LeftRotateString(string str, int n)
    {
        /// abcXYZdef
        /// abcXYZdefabcXYZdef
        /// 012345678
        /// 新的串是两倍串第len位起始长度为n字串
        int length = str.size( );

        if(length == 0)
        {
            return "";
        }
        n = n % len;
        str += str;

        return str.substr(n, len);
    }
};
```

#通过翻转直线循环移位
-------
通过reverse操作
一个序列abcdefg，如果向左循环移动n位，
例如3位，则会编程(defg)(abc)，我们把原序列分成两部分，A=(abc)，B=(defg)，原序列为AB，我们要的结果为BA，则可以这么做：(ArBr)r = ((B)r)r((A)r)r=BA
假设原序列有n位，循环左移i位的过程如下：

1.    reverse(0,i-1);

2.    reverse(i,n-1);

3.    reverse(1,n-1);

例如原序列：abcdefg，循环左移3位：

1.    abc defg -=> cba defg

2.    cba defg -=> cba gfed

3.     cba gfed -=> defg abc

代码就非常简单了，而且reverse操作非常简单，效率高也不容易出错，要记住一点就是STL中的迭代器是左闭右开区间，所以reverse操作的第二个参数需要往后移动一位

使用迭代器的方法

```cpp
class Solution
{
public:
    string LeftRotateString(string str, int n)
    {
        if(str.size( ) == 0)
        {
            return "";
        }
        n %= str.size( );

        Reverse(str, 0, n - 1);
        Reverse(str, n, str.size( ) - 1);
        Reverse(str, 0, str.size( ) - 1);

        return str;
    }

    void Reverse(string &str, int left, int right)
    {
        while(left < right)
        {
            swap(str[left], str[right]);

            left++;
            right--;
        }
    }
};
```
不使用迭代器

```cpp
class Solution
{
public:
    string LeftRotateString(string str, int n)
    {
        if(str.size( ) == 0)
        {
            return "";
        }
        n %= str.size( );

        Reverse(str, 0, n - 1);
        Reverse(str, n, str.size( ) - 1);
        Reverse(str, 0, str.size( ) - 1);

        return str;
    }

    void Reverse(string &str, int left, int right)
    {
        while(left < right)
        {
            swap(str[left], str[right]);

            left++;
            right--;
        }
    }
};
```

