#链接
-------

>牛客OJ：[丑数](http://www.nowcoder.com/practice/6aa9e04fc3794f68acf8778237ba065b?tpId=13&tqId=11186&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
>
>九度OJ：http://ac.jobdu.com/problem.php?pid=1214
>
>GitHub代码： [034-丑数](https://github.com/gatieme/CodingInterviews/tree/master/034-丑数)
>
>CSDN题解：[剑指Offer--034-丑数](http://blog.csdn.net/gatieme/article/details/51308037)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 |
| ------ |:------:| --------:|:----------:|
|[034-丑数](http://www.nowcoder.com/practice/6aa9e04fc3794f68acf8778237ba065b?tpId=13&tqId=11186&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | [1214-丑数](http://ac.jobdu.com/problem.php?pid=1214) | [剑指Offer--034-丑数](http://blog.csdn.net/gatieme/article/details/51308037) | [034-丑数](https://github.com/gatieme/CodingInterviews/tree/master/034-丑数) |



<br>**您也可以选择[回到目录-剑指Offer--题集目录索引](http://blog.csdn.net/gatieme/article/details/51916802)**




#题意
-------

**题目描述**

>把只包含因子2、3和5的数称作丑数（Ugly Number）。
>
>例如6、8都是丑数，但14不是，因为它包含因子7。
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。



#暴力方法
-------
最简单直接的方法，就是**逐个判断每个整数是不是丑数**，循环所有数字，判断它是不是丑数
首先我们需要判断某个整数number是不是丑数
```cpp
bool IsUglyNumber(int number)
{
    while(number % 5 == 0)
    {
        number /= 5;
    }

    while(number % 3 == 0)
    {
        number /= 3;
    }

    while(number % 2 == 0)
    {
        number /= 2;
    }

    return (number == 1);
}
```
然后接下来，就是按照顺序判断每一个整数是不是丑数
```cpp
int GetUglyNumber_Solution(int index)
{
    if(index <= 0)
    {
        return -1;
    }

    int count = 1;
    int num = 0;

    while(count <= index)
    {
        num++;
        if(IsUglyNumber(num) == 1)
        {
            debug <<"count = "<<count <<", " <<num <<" is " <<endl;
            count++;
        }
    }

    return num;
}
```


#寻找所有的丑数
-------
根据丑数的定义，丑数应该是另一个丑数乘以2、3或者5的结果（1除外）。
因此我们可以创建一个数组，里面的数字是排好序的丑数。里面的每一个丑数是前面的丑数乘以2、3或者5得到的。那关键就是确保数组里的丑数是有序的了。
我们假设数组中已经有若干个丑数，排好序后存在数组中。我们把现有的最大丑数记做M。
现在我们来生成下一个丑数，该丑数肯定是前面某一个丑数乘以2、3或者5的结果。
我们首先考虑把已有的每个丑数乘以2。在乘以2的时候，能得到若干个结果小于或等于M的。由于我们是按照顺序生成的，小于或者等于M肯定已经在数组中了，我们不需再次考虑；
我们还会得到若干个大于M的结果，但我们只需要第一个大于M的结果，因为我们希望丑数是按从小到大顺序生成的，其他更大的结果我们以后再说。
我们把得到的第一个乘以2后大于M的结果，记为M2。同样我们把已有的每一个丑数乘以3和5，能得到第一个大于M的结果M3和M5。那么下一个丑数应该是M2、M3和M5三个数的最小者。
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
protected:
    int ugly[10000];
    int min(int a, int b, int c)
    {
        int temp = (a < b ? a : b);

        return (temp < c ? temp : c);
    }

public:
    int GetUglyNumber_Solution(int N)
    {
        ugly[0] = 1;
        int index2 = 0;
        int index3 = 0;
        int index5 = 0;
        int index = 1;
        while (index < N)
        {
            //竞争产生下一个丑数
            int val = min(ugly[index2]*2,
                          ugly[index3]*3,
                          ugly[index5]*5);

            if (val == ugly[index2] * 2) //将产生这个丑数的index*向后挪一位；
            {
                ++index2;
            }
            if (val == ugly[index3] * 3)   //这里不能用elseif，因为可能有两个最小值，这时都要挪动；
            {
                ++index3;
            }
            if (val == ugly[index5] * 5)
            {
                ++index5;
            }

            ugly[index++] = val;
        }
        int result = ugly[N - 1];
        return result;
    }
};

int __tmain( )
{
    Solution solu;
    cout <<solu.GetUglyNumber_Solution(3) <<endl;
    return 0;
}
```


