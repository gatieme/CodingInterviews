#链接
------- 
>牛客OJ：[字符流中第一个不重复的字符](http://www.nowcoder.com/practice/00de97733b8e4f97a3fb5c680ee10720?tpId=13&tqId=11207&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
> 
>九度OJ：未收录
> 
>GitHub代码： [055-字符流中第一个不重复的字符](https://github.com/gatieme/CodingInterviews/tree/master/055-字符流中第一个不重复的字符)
>
>CSDN题解：[剑指Offer--055-字符流中第一个不重复的字符](http://blog.csdn.net/gatieme/article/details/51598809)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 |
| ------------- |:-------------:| -----:| -----:|
|[055-字符流中第一个不重复的字符](http://www.nowcoder.com/practice/00de97733b8e4f97a3fb5c680ee10720?tpId=13&tqId=11207&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking) | 未收录 | [剑指Offer--055-字符流中第一个不重复的字符](http://blog.csdn.net/gatieme/article/details/51598809) | [055-字符流中第一个不重复的字符](https://github.com/gatieme/CodingInterviews/tree/master/055-字符流中第一个不重复的字符) |


>类似的题目
>
>[剑指Offer--035-第一个只出现一次的字符位置](http://blog.csdn.net/gatieme/article/details/51598809)


#题目描述
-------


>请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。

>如果当前字符流没有存在出现一次的字符，返回#字符。

#分析
-------


>类似的题目
>
>[剑指Offer--035-第一个只出现一次的字符位置](http://blog.csdn.net/gatieme/article/details/51598809)

但是第35题只要求我们找到一个字符串中第一个只出现一次字符即可, 但是这道题相当于一个在线算法, 要求我们能对一个源源不断的输入流进行处理

字符只能一个接着一个从字符流中读取出来, 因此我们可以定义一个数据容器来保存字符在字符流中的位置, 当一个字符第一次从字符流中拂去出来的时候, 把它保存在字符流中的位置保存到容器中。

当这个字符再次从字符流中被读取出来的时候, 那么它就不是只出现一次的字符, 也就是被忽略了。这时候就把在数据容器里保存的值更新成一个特殊的值即可。

为了更加高效的解决这个问题, 需要在O(1)的时间内往数据容器里插入一个字符, 以及更新一个字符对应的值。


#代码
-------

```cpp
#include <iostream>
#include <cstring>


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
    Solution()
    {
        str = "";
        memset(count, '\0', sizeof(count));
    }

    //  Insert one char from stringstream
    void Insert(char ch)
    {
        str += ch;
        count[(int)ch]++;
    }

    //  Return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int len = str.size( );

        for(int i = 0; i < len; i++)
        {
            if(count[(int)str[i]] == 1)
            {
                return str[i];
            }
        }

        return '#';
    }

private:
    std::string     str;
    int             count[256];


};

int __tmain( )
{
    Solution solu;

    solu.Insert('g');
    cout <<solu.FirstAppearingOnce( ) <<endl;

    solu.Insert('o');
    cout <<solu.FirstAppearingOnce( ) <<endl;

    solu.Insert('o');
    cout <<solu.FirstAppearingOnce( ) <<endl;

    solu.Insert('g');
    cout <<solu.FirstAppearingOnce( ) <<endl;

    solu.Insert('l');
    cout <<solu.FirstAppearingOnce( ) <<endl;

    solu.Insert('e');
    cout <<solu.FirstAppearingOnce( ) <<endl;


    return 0;
}
```


