#链接
------- 
>牛客OJ：[和为S的连续正数序列](http://www.nowcoder.com/practice/c451a3fd84b64cb19485dad758a55ebe?tpId=13&tqId=11194&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
> 
>九度OJ：http://ac.jobdu.com/problem.php?pid=1354
> 
>GitHub代码： [041-和为S的连续正数序列](https://github.com/gatieme/CodingInterviews/tree/master/041-和为S的连续正数序列)
>
>CSDN题解：[剑指Offer--041-和为S的连续正数序列](http://blog.csdn.net/gatieme/article/details/51357308)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 | 
| ------------- |:-------------:| -----:|
|[041-和为S的连续正数序列](http://www.nowcoder.com/practice/c451a3fd84b64cb19485dad758a55ebe?tpId=13&tqId=11194&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | [1354-和为S的连续正数序列](http://ac.jobdu.com/problem.php?pid=1354) | [剑指Offer--041-和为S的连续正数序列](http://blog.csdn.net/gatieme/article/details/51357308) | [041-和为S的连续正数序列](https://github.com/gatieme/CodingInterviews/tree/master/041-和为S的连续正数序列) |



#题意
-------

**题目描述**

>小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck! 


>输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序

**输入描述**
>5
>
>100

**输出描述**

>2 3
>
>9 10 11 12 13 14 15 16
>18 19 20 21 22

#题目一：和为sum的两个数
-------

##题目描述
-------

>输入一个递增排序的数组和一个数字s，在数组中查找两个数，得它们的和正好是s。如果有多对数字的和等于s，输出任意一对即可。
>
>
>举例说明
>
>例如输入数组｛1 、2 、4、7 、11 、15 ｝和数字15. 
>
>由于4+ 11 = 15 ，因此输出4 和11 。

##解题思路　　
-------

我们先在数组中选择两个数字，如果它们的和等于输入的s，我们就找到了要找的两个数字。如果和小于s 呢？我们希望两个数字的和再大一点。由于数组已经排好序了，我们可以考虑选择较小的数字后面的数字。因为排在后面的数字要大一些，那么两个数字的和也要大一些， 就有可能等于输入的数字s 了。同样， 当两个数字的和大于输入的数字的时候，我们可以选择较大数字前面的数字，因为排在数组前面的数字要小一些。代码实现

##代码
-------

```cpp
public static List<Integer> findNumbersWithSum(int[] data, int sum)
{
    List<Integer> result = new ArrayList<>(2);

    if (data == null || data.length < 2)
    {
        return result;
    }

    int ahead = data.length - 1;
    int behind = 0;
    long curSum; // 统计和，取long是防止结果溢出

    while (behind < ahead)
    {
        curSum = data[behind] + data[ahead];

        if (curSum == sum)
        {
            result.add(data[behind]);
            result.add(data[ahead]);
            break;
        }
        else if (curSum < sum)
        {
            behind++;
        }
        else
        {
            ahead--;
        }
    }

    return result;
}
```

#和为S的连续正数序列
-------

**解题思路**

考虑用两个数start和end分别表示序列的最小值和最大值。首先把start初始化为1, end初始化为2。如果从start到end的序列的和大于s，我们可以从序列中去掉较小的值，也就是增大start的值。如果从start到end的序列的和小于s，我们可以增大big，让这个序列包含更多的数字。因为这个序列至少要有两个数字，我们一直增加start到(1+s)/2 为止。 

以求和为9 的所有连续序列为例，我们先把start初始化为1, end初始化为2。此时介于start和end之间的序列是｛1，2}，序列的和为3，小于9，所以我们下一步要让序列包含更多的数字。我们把end增加1 变成3,此时序列为｛ I, 2，坷。由于序列的和是6，仍然小于9，我们接下来再增加end变成4，介于start和end之间的序列也随之变成｛ l, 2, 3, 4｝。由于列的和10 大于9，我们要删去去序列中的一些数字， 于是我们增加start变成2，此时得到的序列是｛2, 3, 4｝， 序列的和E好是9。我们找到了第一个和为9 的连续序列，把它打印出来。接下来我们再增加big，重复前面的过程，可以找到第二个和为9 的连续序列｛4，5}。


```cpp
#include <iostream>
#include <vector>

using namespace std;

#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain


class Solution
{
public:
    vector< vector<int> > FindContinuousSequence(int sum)
    {
        vector< vector<int> > res;
        vector<int> currRes;

        if(sum < 3)
        {
            return res;
        }

        int begin = 1, end = 2, mid = (sum + 1) / 2;
        int currSum = begin + end;
        while(begin < mid && end < sum)
        {
            ///  和正好是sum的话, 就存储下来
            if(currSum == sum)
            {
                currRes.clear( );
                for(int i = begin; i <= end; i++)
                {
                    debug <<i <<" ";
                    currRes.push_back(i);
                }
                debug <<endl;
                res.push_back(currRes);

                ///  存储完以后, 进一步往下走
                end++;
                currSum += end;
            }
            else if(currSum > sum)  /// 如果和太大了, 缩短起始位置
            {
                currSum -= begin;
                begin++;
            }
            else if(currSum < sum)  ///  如果和太小了, 那么增加结束位置
            {
                end++;
                currSum += end;
            }
        }

        return res;
    }
};

int __tmain( )
{
    Solution solu;

    vector< vector<int> > res = solu.FindContinuousSequence(100);

    debug <<"Total Count = "<<res.size( ) <<endl;
    for(unsigned int i = 0; i < res.size( ); i++)
    {
        debug <<"Count = " <<i <<", Size = "<<res[i].size( ) <<endl;
        for(unsigned int j = 0; j < res[i].size( ); j++)
        {
            cout <<res[i][j] <<" ";
        }
        cout <<endl;
    }

    return 0;
}
```