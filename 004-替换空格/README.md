#链接
------- 

>牛客OJ：[替换空格](http://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?tpId=13&tqId=11155&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
>
>九度OJ：http://ac.jobdu.com/problem.php?pid=1510
>
>GitHub代码： [004-替换空格](https://github.com/gatieme/CodingInterviews/tree/master/004-%E6%9B%BF%E6%8D%A2%E7%A9%BA%E6%A0%BC)
>
>CSDN题解：[剑指Offer--004-替换空格](http://blog.csdn.net/gatieme/article/details/51100630)



| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 |
| ------------- |:-------------:| -----:|
| [替换空格](http://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?tpId=13&tqId=11155&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)  | [1510-替换空格](http://ac.jobdu.com/problem.php?pid=1510)   | [剑指Offer--004-替换空格](http://blog.csdn.net/gatieme/article/details/51100630)   | [004-替换空格](https://github.com/gatieme/CodingInterviews/tree/master/004-%E6%9B%BF%E6%8D%A2%E7%A9%BA%E6%A0%BC) |


#题意
-------
题目描述


请实现一个函数，将一个字符串中的空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
>We Are Happy
>
>We%20Are%20Happy


如果不考虑在原来的字符串上替换的话, 那么我们直接再开一个数组，从前往后依次赋值

遇见空格，就填上%20, 否则就填当前字符。

但是这个肯定不是面试官期待的

那么怎么在原字符串上进行高效的替换呢？

#暴力替换
-------

最原始的方法，我们遍历一遍字符串，对字符中每一个空格，都用%20来替换，
由于用%20替换空格会导致字符串长度的增加，因此需要注意
*    从后往前遍历字符串
*    每找到一个空格，需要将`' '`后面的字符串依次后移两位，预留出%20的空间

代码如下
```cpp
#include <iostream>

using namespace std;

#define __tmain main


class Solution
{
public:
	void replaceSpace(char *str,int length)
    {
        int i = length - 1, j;
        int len = length;

        //  从后往前遍历
        for(i = length - 1; i >= 0; i--)
        {
            //cout <<str[i] <<endl;
            //  如果当前字符是空格
            if(str[i] == ' ')
            {
                //  从空格变成%20长度增加了2
                len += 2;

                for(j = len - 1; j > i + 2; j--)
                {
                    str[j] = str[j - 2];
                }
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '\%';
            }
            //cout <<str <<endl;
        }
        str[len] = '\0';
	}
};


int __tmain( )
{
    char str[10 + 1] = "a b c d";

    Solution solu;
    solu.replaceSpace(str, 10);

    cout <<str <<endl;

    return 0;
}

``` 

#优化
-------

上面那个方法太暴力了，有没有什么更好的方法呢？

我们的代码，主要消耗的时间在于，如果有多个空格， 那么每遇到一个空格就进行移位

其实前面的移位是没必要的，因为如果再遇到空格，那么之前的移位全是无用功

因此我们可以考虑**先遍历一遍字符串, 计数空格的数目**, 

我们知道了空格的数目，其实就是知道了替换后字符串的长度，那么只需要进行一次替换就可以了

因为我们的工作变为

*	遍历一遍字符串， 统计字符出现的数目, 计算替换后的字符串长度

*	再遍历一遍字符串，完成替换

代码如下

```cpp
#include <iostream>

using namespace std;

#define __tmain main


class Solution
{
public:
	void replaceSpace(char *str,int length)
    {
        int i, j;
        int count = 0;
        int len = length;
        for(int i = 0; i < length; i++)
        {
            if(str[i] == ' ')
            {
                count++;
            }
        }

        len = length + count * 2;
        for(i = length - 1, j = len - 1;
            i >= 0 && j >= 0;)
        {
            if(str[i] == ' ')
            {
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
                i--;
            }
            else
            {
                str[j--]  = str[i--];
            }
        }
        str[len] = '0';

	}
};


int __tmain( )
{
    char str[10 + 1] = "a b c d";

    Solution solu;
    solu.replaceSpace(str, 10);

    cout <<str <<endl;

    return 0;
}

```