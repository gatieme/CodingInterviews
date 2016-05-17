#链接
------- 
>牛客OJ：[孩子们的游戏(圆圈中最后剩下的数)](http://www.nowcoder.com/practice/f78a359491e64a50bce2d89cff857eb6?tpId=13&tqId=11199&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
> 
>九度OJ：http://ac.jobdu.com/problem.php?pid=1356
> 
>GitHub代码： [045-孩子们的游戏(圆圈中最后剩下的数)](https://github.com/gatieme/CodingInterviews/tree/master/045-孩子们的游戏(圆圈中最后剩下的数))
>
>CSDN题解：[剑指Offer--045-孩子们的游戏(圆圈中最后剩下的数)](http://blog.csdn.net/gatieme/article/details/51435055)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 | 
| ------------- |:-------------:| -----:| -----:|
|[045-孩子们的游戏(圆圈中最后剩下的数)](http://www.nowcoder.com/practice/f78a359491e64a50bce2d89cff857eb6?tpId=13&tqId=11199&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | [1356-孩子们的游戏(圆圈中最后剩下的数)](http://ac.jobdu.com/problem.php?pid=1356) | [剑指Offer--045-孩子们的游戏(圆圈中最后剩下的数)](http://blog.csdn.net/gatieme/article/details/51435055) | [045-孩子们的游戏(圆圈中最后剩下的数)](https://github.com/gatieme/CodingInterviews/tree/master/045-孩子们的游戏(圆圈中最后剩下的数)) |



#题意
-------

**题目描述**

每年六一儿童节,NowCoder都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。

HF作为NowCoder的资深元老,自然也准备了一些小游戏。

其中,有个游戏是这样的:

首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。

每次喊到m的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一个小朋友,可以不用表演,

并且拿到NowCoder名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。

请你试着想下,哪个小朋友会得到这份礼品呢？


**样例输入**

>1 10
>
>8 5
>
>6 6

**样例输出**

>1
>
>3
>
>4


#模拟环形链表
-------


既然题目中有一个数字圆圈，很容易想到用环形链表来模拟这个圆圈。我们可以创建一个有n个结点的环形链表，然后每次在这个链表中删除第m个结点。 

可以使用STL中的list或者vector来模拟一个环形链表。t本身不是环形结构，所以每次当迭代器扫描到链表的末尾时，我们要将迭代器移到链表头。 

代码如下:


```cpp
#include <iostream>
#include <vector>
#include <iterator>

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
    int LastRemaining_Solution(unsigned int n, unsigned int m)
    {
        if(n < 1 || m < 1)
        {
            return -1;
        }


        vector<int> numbers;

        for(int i = 0; i < n; i++)
        {
            numbers.push_back(i);
            debug <<i <<" ";
        }
        debug <<endl;

        unsigned int cntN = 0;
        unsigned int cntM = -1;
        while(numbers.size( ) > 1)
        {
            debug <<"count = " <<1 <<", num[" <<cntN <<"] = " <<numbers[cntN] <<endl;
            for(int cntM = 1; cntM < m; cntM++)
            {
                ++cntN;
                cntN %= numbers.size( );
                debug <<"count = " <<cntN + 1 <<", num[" <<cntN <<"] = " <<numbers[cntN] <<endl;
            }

            debug <<numbers[cntN] <<" leave the list" <<endl;
            numbers.erase(numbers.begin( ) + cntN);

#ifdef debug
            copy(numbers.begin( ),
                 numbers.end( ),
                 ostream_iterator< int >(cout, " "));
            debug <<endl;
#endif // debug

        }

        //  循环结束的时候, cntN = 1
        debug <<"count = " <<1 <<", num[" <<cntN <<"] = " <<numbers[cntN] <<endl;
        return numbers[0];
    }
};

int __tmain( )
{
    Solution solu;

    cout <<solu.LastRemaining_Solution(5, 2) <<endl;

    //cout <<solu.LastRemaining_Solution(8, 5) <<endl;;

    //cout <<solu.LastRemaining_Solution(6, 6) <<endl;;

    return 0;
}
```

#递推公式-获取最后的胜利者的序号
-------

无论是用链表实现还是用数组实现都有一个共同点：要模拟整个游戏过程，不仅程序写起来比较烦，而且时间复杂度高达$O(nm)$，当n，m非常大（例如上百万，上千万）的时候，几乎是没有办法在短时间内出结果的。我们注意到原问题仅仅是要求出最后的胜利者的序号，而不是要读者模拟整个过程。因此如果要追求效率，就要打破常规，实施一点数学策略。

为了讨论方便，先把问题稍微改变一下，并不影响原意：
我们知道第一个人（编号一定是（m-1）) 出列之后，剩下的n-1个人组成了一个新的约瑟夫环（以编号为k=m mod n的人开始）：

>k k+1 k+2 ... n-2,n-1,0,1,2,... k-2

并且从k开始报0。
我们把他们的编号做一下转换：

```
k --> 0
k+1 --> 1
k+2 --> 2
...
...
k-2 --> n-2
```

变换后就完完全全成为了（n-1）个人报数的子问题，假如我们知道这个子问题的解：例如x是最终的胜利者，那么根据上面这个表把这个x变回去不刚好就是n个人情况的解吗？！！变回去的公式很简单，相信大家都可以推出来：x'=(x+k) mod n
如何知道（n-1）个人报数的问题的解？对，只要知道（n-2）个人的解就行了。（n-2）个人的解呢？当然是先求（n-3）的情况 ---- 这显然就是一个倒推问题！好了，思路出来了，下面写递推公式：
令f表示i个人玩游戏报m退出最后胜利者的编号，最后的结果自然是f[n]

递推公式

>让f[i]为i个人玩游戏报m退出最后的胜利者的编号，最后的结果自然是f[n]
>
>f[1] = 0;
>f[i] = (f[i - 1] + m) mod i;

有了这个公式，我们要做的就是从1-n顺序算出f的数值，最后结果是f[n]。

注意我们的编号是从0开始，如果从1开始可以返回f[n] + 1


```cpp
class Solution
{
public:
    int LastRemaining_Solution(unsigned int n, unsigned int m)
    {
        if(n < 1 || m < 1)
        {
            return -1;
        }

        int last = 0;
        debug <<"F[" <<0 <<"] = " <<last <<endl;

        for(int step = 2; step <= n; step++)
        {
            last = (last + m) % step;
            debug <<"F[" <<step - 1 <<"] = " <<last <<endl;
        }
        return last;
    }
};

```

当然也可以使用递归方式


```cpp
class Solution
{
public:
    int LastRemaining_Solution(unsigned int n, unsigned int m)
    {
        if(n < 1 || m < 1)
        {
            return -1;
        }
        else if(n == 1)
        {
            return 0;
        }
        else
        {
            // F[n] = (F[n - 1] + m) % n
            return (LastRemaining_Solution(n-1,m)+m)%n;
        }
    }
};
```