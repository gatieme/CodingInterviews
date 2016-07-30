#链接
-------
>牛客OJ：[把数组排成最小的数](http://www.nowcoder.com/practice/8fecd3f8ba334add803bf2a06af1b993?tpId=13&tqId=11185&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
>
>九度OJ：http://ac.jobdu.com/problem.php?pid=1504
>
>GitHub代码： [033-把数组排成最小的数](https://github.com/gatieme/CodingInterviews/tree/master/033-把数组排成最小的数)
>
>CSDN题解：[剑指Offer--033-把数组排成最小的数](http://blog.csdn.net/gatieme/article/details/51303662)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 |
| ------ |:------:| --------:|:----------:|
|[033-把数组排成最小的数](http://www.nowcoder.com/practice/8fecd3f8ba334add803bf2a06af1b993?tpId=13&tqId=11185&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | [1504-把数组排成最小的数](http://ac.jobdu.com/problem.php?pid=1504) | [剑指Offer--033-把数组排成最小的数](http://blog.csdn.net/gatieme/article/details/51303662) | [033-把数组排成最小的数](https://github.com/gatieme/CodingInterviews/tree/master/033-把数组排成最小的数) |



<br>**您也可以选择[回到目录-剑指Offer--题集目录索引](http://blog.csdn.net/gatieme/article/details/51916802)**




#题意
-------

**题目描述**


输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
**输入**
例如输入数组

>{3，32，321}

**输出**

则打印出这三个数字能排成的最小数字为

>321323

#按照拼接后的结果排序
-------
首先因为数组可能非常长，所以要定义一个整数类，使得其大小可以容纳所有的数组元素组成的数不大现实。因此我们直接输出这个数组，让其看起来像一个整数，这样我们就可以把问题转化为：如何给这个数组排序，使其看做一个数字的时候最小。
第一个想到的可能是按字典序排序，小的在前面。可惜这个是不可行的，比如32的字典序比322小，但是32322比32232大，
所以在这里自定义一个比较大小的函数，比较两个字符串s1, s2大小的时候，先将它们拼接起来，比较s1+s2,和s2+s1那个大，如果s1+s2大，那说明s2应该放前面，所以按这个规则，s2就应该排在s1前面。

<font color=#0099ff face="黑体"> 思路：先将整数数组转为字符串数组，然后字符串数组进行排序，最后依次输出字符串数组即可。这里注意的是字符串的比较函数需要重新定义，不是比较a和b，而是比较ab与 ba。如果ab < ba，则a < b；如果ab > ba，则a > b；如果ab = ba，则a = b。比较函数的定义是本解决方案的关键。这道题其实就是希望我们能找到一个排序规则，根据这个规则排出来的数组能排成一个最小的数字。<font>

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain



template<class T>
string ToString(const T& t)
{

    ostringstream oss;  //  创建一个流

    oss <<t;            //  把值传递如流中
    return oss.str( );  //  获取转换后的字符转并将其写入result
}


class Solution
{
public:

    ///  比较函数
    //  我们比较的不是两个字符串本身的大小，而是他们拼接后的两个数字的大小
    static bool Compare(const string &left, const string &right)
    {
        string leftright = left + right;
        string rightleft = right + left;
        if(leftright > rightleft)
        {
            debug <<leftright <<" > " <<rightleft <<" -- " <<rightleft <<endl;
        }
        else
        {
            debug <<leftright <<" < " <<rightleft <<" -- " <<leftright <<endl;
        }

        return leftright < rightleft;
    }


    string PrintMinNumber(vector<int> numbers)
    {
        string res = "";
        string str;

        vector<string> strNum;

        ///  将整数转换成字符串
        for(unsigned int i = 0; i < numbers.size( ); i++)
        {
            str = ToString(numbers[i]);
            strNum.push_back(str);
            debug <<str <<endl;
        }

        ///  对字符串按照拼接后的大小进行排序
        sort(strNum.begin( ), strNum.end( ), Compare);

        ///  拼接结果
        for(unsigned int i = 0; i < strNum.size( ); i++)
        {
            debug <<strNum[i];
            res += strNum[i];
        }
        debug <<endl;
        return res;
    }
};


int __tmain( )
{
    Solution solu;

    int arr[] = { 321, 32, 3 };
    vector<int> vec(arr, arr + 3);
    cout <<solu.PrintMinNumber(vec) <<endl;
    return 0;
}
```
