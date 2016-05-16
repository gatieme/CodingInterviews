#链接
------- 
>牛客OJ：[扑克牌顺子](http://www.nowcoder.com/practice/762836f4d43d43ca9deb273b3de8e1f4?tpId=13&tqId=11198&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
> 
>九度OJ：http://ac.jobdu.com/problem.php?pid=1355
> 
>GitHub代码： [044扑克牌顺子](https://github.com/gatieme/CodingInterviews/tree/master/044扑克牌顺子)
>
>CSDN题解：[剑指Offer--044扑克牌顺子](http://blog.csdn.net/gatieme/article/details/51427573)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 | 
| ------------- |:-------------:| -----:| -----:|
|[044扑克牌顺子](http://www.nowcoder.com/practice/762836f4d43d43ca9deb273b3de8e1f4?tpId=13&tqId=11198&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | [1355-扑克牌顺子](http://ac.jobdu.com/problem.php?pid=1355) | [剑指Offer--044扑克牌顺子](http://blog.csdn.net/gatieme/article/details/51427573) | [044扑克牌顺子](https://github.com/gatieme/CodingInterviews/tree/master/044扑克牌顺子) |



#题意
-------

**题目描述**

LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...

他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票
,嘿嘿！！“红心A,黑桃3,小王,大王,方片5”,
“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。
上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。

LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何。为了方便起见,你可以认为大小王是0。

**样例输入**


>3 5 1 0 4
>
>3 5 4 7 6
>
>3 5 7 4 8


**样例输出**

>So Lucky!
>
>So Lucky!
>
>Oh My God!



#排序后看0能不能填补空缺
-------
可以把5张牌看成由5个数字组成的数组。大、小王是特殊的数字，我们不妨把它们定义为0，这样就能和其他扑克牌区分开来了。



接下来我们分析怎样判断5个数字是不是连续的，最直观的方法是把数组排序。值得注意的是，由于0可以当成任意数字，我们可以用0去补满数组中的空缺。如果排序之后的数组不是连续的，即相邻的两个数字相隔若干个数字，但只要我们有足够的0可以补满这两个数字的空缺，这个数组实际上还是连续的。举个例子，数组排序之后为{0，1，3，4，5}，在1和3之间空缺了一个2，刚好我们有一个0，也就是我们可以把它当成2去填补这个空缺。



于是我们需要做3件事：



1.    首先把数组排序



2.    再统计数组中的0的个数



3.    最后统计排序之后的数组中相邻数字之间的空缺总数。



<font color = 00ff66>如果空缺的总数小于或者等于0的个数，那么这个数组就是连续的；反之则不连续。</font>



最后，我们还需要注意一点：



<font color = 00ff66>如果数组中的非0数字重复出现，则该数组不是连续的。</font>



```cpp
#include <iostream>
#include <vector>
#include <algorithm>

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
    bool IsContinuous(vector<int> numbers)
    {
        if(numbers.size( ) == 0)
        {
            return false;
        }
        sort(numbers.begin( ), numbers.end( ));

        /// 统计前面0的个数
        int left = 0;
        while(numbers[left] == 0)
        {
            left++;
        }
        debug <<"left = " <<left <<endl;

        ///  然后看0能不能填补两个数之间的空缺
        for(int i = left + 1; i < numbers.size( ); i++)
        {
            debug <<numbers[i - 1] <<", " <<numbers[i] <<endl;

            // 如果数组中的非0数字重复出现，则该数组不是连续的。
            if(numbers[i] == numbers[i - 1])
            {
                return false;
            }
            else        //  否则填补空缺, 无空缺的情况不用单独判断(空缺为0)
            {
                left -= (numbers[i] - numbers[i - 1] - 1);
            }
        }
        debug <<"left = " <<left <<endl;
        if(left >= 0)
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

    int arr1[] = { 1, 3, 2, 6, 4 };
    vector<int> vec1(arr1, arr1 + 5);
    cout <<solu.IsContinuous(vec1) <<endl;

    int arr2[] = { 3, 5, 1, 0, 4, };
    vector<int> vec2(arr2, arr2 + 5);
    cout <<solu.IsContinuous(vec2) <<endl;

    int arr3[] = { 1, 0, 0, 1, 0 };
    vector<int> vec3(arr3, arr3 + 5);
    cout <<solu.IsContinuous(vec3) <<endl;
    return 0;
}
```



#考虑题目的特殊含义

-------



但是我们考虑一下子题目中特殊条件对顺子有什么要求



**条件：   5张牌，顺子，除0之外不能重复**



**结论：  非0元素的极差（最大值最小值的差）不超过4， 非0元素不重复**



*    非0元素的极差不查过4

首先5张牌的顺子，即使包含了0，那么最大值和最小值的差值肯定不超过4，否则的话一定不是顺子

>比如{ 1，2，3，4，6 }，最大最小值的差（极差）为6-1=5>4

>正好满足的情况，{1, 2, 3, 4, 5}，极差刚好是4

>可以填补的情况，0填补的位置分四种情况，前面 {0, 2, 3, 4, 5},，中间{1, 2, 0, 4, 5}和结尾{1, 2, 3, 4, 0,},以及混合情况，这些情况下极差都不可能超过4



这个比较好判断，我们维护一个非0的最大最小值，那么判断极差即可



*    非0元素不重复



接着是怎么判断非0元素是否重复呢？

我们可以通过位运算，设置一个标识flag

```

    #define BIT_GET(number, pos) ((number) >> (pos) & 1)     /// 用宏得到某数的某位

    #define BIT_SET(number, pos) ((number) |= 1 << (pos))    /// 把某位置1


```

首次遇见一个元素number时候，就设置标识flag的第number位为1，下次通过检测第number即可发现此元素是否重复



代码如下

```cpp
#define BIT_GET(number, pos) ((number) >> (pos) & 1)     /// 用宏得到某数的某位

#define BIT_SET(number, pos) ((number) |= 1 << (pos))    /// 把某位置1

#define BIT_CLR(number, pos) ((number) &= ~(1 << (pos))) /// 把某位清0

#define BIT_CPL(number, pos) ((number) ^= 1 << (pos))    /// 把number的POS位取反

class Solution
{
public:


    bool IsContinuous(vector<int> numbers)
    {
        if(numbers.size( ) != 5)
        {
            return false;
        }
        int min = INT_MAX;
        int max = INT_MIN;
        int flag = 0;

        for(int i = 0; i < numbers.size( ); i++)
        {
            int num = numbers[i];

            if(num < 0 || num > 13) //  牌只能在0~13之间
            {
                return false;
            }
            else if(num == 0)       //  0用来答题任何牌，因此不能参与最大最小牌的比对
            {
                continue;
            }

            //  非0元素不能重复
            if(BIT_GET(flag, num) == 1)     //  如果flag的第num位为1, 说明num重复
            {
                debug <<i <<", " <<num <<endl;
                return false;
            }
            else
            {
                BIT_SET(flag, num);     //  将标识flag的第num位置为0
            }
            //  寻找最大最小的牌
            if(num > max)
            {
                max = num;
            }
            if(num < min)
            {
                min = num;
            }
            debug <<"max = " <<max <<", min = " <<min <<endl;

            //  如果最大值和最小值的差值大于4, 那么必应不能补齐
            if(max - min > 4)
            {
                debug <<"max = " <<max <<", min = " <<min <<endl;
                return false;
            }
        }
        return true;
    }
};
```

