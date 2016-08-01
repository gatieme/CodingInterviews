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

我们先考虑个简单的

>参见 
>
>[LeetCode题解--1. Two Sum](http://blog.csdn.net/gatieme/article/details/50596965)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 | 
| ------------- |:-------------:| -----:|
|[041-和为S的两个数字](http://www.nowcoder.com/practice/390da4f7a00f44bea7c2f3d19491311b?tpId=13&tqId=11195&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | [1352-和为S的连续正数序列](http://ac.jobdu.com/problem.php?pid=1352) | [剑指Offer--041-和为S的连续正数序列](http://blog.csdn.net/gatieme/article/details/51357308) | [041-和为S的两个数字](https://github.com/gatieme/CodingInterviews/tree/master/041-和为S的两个数字) |

##题目描述
-------

>输入一个递增排序的数组和一个数字s，在数组中查找两个数，得它们的和正好是s。如果有多对数字的和等于s，输出乘积最小的即可。
>
>
>举例说明
>
>例如输入数组｛1 、2 、4、7 、11 、15 ｝和数字15. 
>
>由于4+ 11 = 15 ，因此输出4 和11 。


##解题思路　　
-------

>考虑**韦达定理**
>
>设一元二次方程$x^2 + qx + q = 0$的两个根$x_{1}，x_{2}$，那么
>
>$x_{1} + x_{2} = -p$
>
>$x_{1}  * x_{2} = q$
>
>即以$x_{1}，x_{2}$的一元二次方程是$x^2 - (x_{1} + x_{2})x + (x_{1}  * x_{2}) = 0$
>
>而该方程有根的判别式子为：$q^2-4q>= 0$
>

数列满足递增，设两个头尾两个指针i和j，
*	若ai + aj == sum，就是答案（相差越远乘积越小）

*	若ai + aj > sum，aj肯定不是答案之一（前面已得出 i 前面的数已是不可能），j -= 1

*	若ai + aj < sum，ai肯定不是答案之一（前面已得出 j 后面的数已是不可能），i += 1

那么怎么保证输出的两个数最小呢？

>比如
> 1 2 3 4 5 6
> 
>相隔距离越远。乘积也越大
> $1*6 < 2 * 5 < 3 * 4$

因此我们从两端分别向中间走，先找到的那一对和一定最小

##代码
-------

```cpp
class Solution
{
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum)
    {
        vector<int> res;

        if (array.size( ) < 2)
        {
            return res;
        }

        int start = 0, end = array.size( ) - 1;
        long curSum;

        while (start < end)
        {
            curSum = array[start] + array[end];

            if (curSum == sum)
            {
                ///  左右夹逼
                ///  同时能保证乘积最小的
                /// 和为sum的最大的两个数最接近sqrt(sum)  
                res.push_back(array[start]);
                res.push_back(array[end]);

                break;
            }
            else if (curSum < sum)
            {
                start++;
            }
            else
            {
                end--;
            }
        }

        return res;
    }
};
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
