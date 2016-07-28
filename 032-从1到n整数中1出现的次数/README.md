#链接
-------
>牛客OJ：[从1到n整数中1出现的次数](http://www.nowcoder.com/practice/bd7f978302044eee894445e244c7eee6?tpId=13&tqId=11184&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
>
>九度OJ：http://ac.jobdu.com/problem.php?pid=1373
>
>GitHub代码： [032-从1到n整数中1出现的次数](https://github.com/gatieme/CodingInterviews/tree/master/032-从1到n整数中1出现的次数)
>
>CSDN题解：[剑指Offer--032-从1到n整数中1出现的次数](http://blog.csdn.net/gatieme/article/details/51292339)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 |
| ------ |:------:| --------:|:----------:|
|[032-从1到n整数中1出现的次数](http://www.nowcoder.com/practice/bd7f978302044eee894445e244c7eee6?tpId=13&tqId=11184&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | [1373-从1到n整数中1出现的次数](http://ac.jobdu.com/problem.php?pid=1373) | [剑指Offer--032-从1到n整数中1出现的次数](http://blog.csdn.net/gatieme/article/details/51292339) | [032-从1到n整数中1出现的次数](https://github.com/gatieme/CodingInterviews/tree/master/032-从1到n整数中1出现的次数) |


<br>**您也可以选择[回到目录-剑指Offer--题集目录索引](http://blog.csdn.net/gatieme/article/details/51916802)**



#暴力方法
-------

最简单直接的方法就是我们循环所有的1~n中的每个number，计算每个number出现的次数

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
    /**
     * [NumberOf1Between1AndN_Solution 统计1到n的整数中1出现的次数]
     * @Author   gatieme
     * @DateTime 2016-05-01T22:03:43+0800
     * @param    n                        [整数n]
     * @return                            [1到n的整数中1出现的次数]
     */
    int NumberOf1Between1AndN_Solution(int n)
    {
        int count = 0;

        for(int i = 1;
            i <= n;
            i++)
        {
            count += NumberOf1(i);
        }

        return count;
    }

protected:
    /**
     * [NumberOf1 统计number中1出现的次数]
     * @Author    gatieme
     * @DateTime 2016-05-01T22:01:08+0800
     * @param    number                   [待处理的数字]
     * @return                            [number中1出现的次数]
     */
    int NumberOf1(int number)
    {
        int count = 0;
        while(number != 0)
        {
            if(number % 10 == 1)
            {
                count++;
            }

            number /= 10;
        }

        return count;
    }
};


int __tmain( )
{
    Solution solu;
    cout <<solu.NumberOf1Between1AndN_Solution(12) <<endl;
    cout <<solu.NumberOf1Between1AndN_Solution(100) <<endl;
    cout <<solu.NumberOf1Between1AndN_Solution(1000) <<endl;
    return 0;
}
```

此方法简单，容易理解，但它的问题是效率，时间复杂度为$O(N * lgN)$，N比较大的时候，需要耗费很长的时间。

#分治递归
-------
我们重新分析下这个问题，

对于任意一个个位数n，只要n>=1,它就包含一个"1"；

n<1，即n=0时，则包含的"1"的个数为0。

于是我们考虑用分治的思想将任意一个n位数不断缩小规模分解成许多个个位数，这样求解就很方便。

但是，我们该如何降低规模？

仔细分析，我们会发现，

<font color=#0099ff face="黑体">
**任意一个n位数中"1"的个位可以分解为两个n-1位数中"1"的个数的和，最后再加上一个与最高位数相关的常数C**

</font>

例如，
>对于n=12，可以拆分为01~09,10~12，即 f(12) = f(10 - 1) + f(12 - 10) + 3,其中3是表示最高位为1的数字个数，这里就是10,11,12；
>
>对于n=132，可以拆分为0~99，100~132，即f(132)=f(100 -1) + f(132 - 100) + 33，33代表最高位为1的数字的个数，这里就是100~132百位数字的1出新了33次
>
>对于232，可以拆分为0~99，100~232，即f(232) = 2*f(100 - 1) + f(32) + 100，因为232大于199，所以它包括了所有最高位为1的数字即100~199，共100个。

综上，我们分析得出，<font color=#0099ff face="黑体">最后加的常数C只跟最高位n1是否为1有关</font>

*    当最高位为1时，常数C为原数字N去掉最高位后剩下的数字+1，如N=12时，$C = 2 + 1 = 3$，N=132时，$C = 32 + 1 = 33$

*    当最高位大于1时，常数C为$10^(bit-1)$，其中bit为N的位数，如N=232时，bit=3，$C = 10^(bit-1) = 10^2 = 100$。
于是，我们可以列出递归方程如下：

```
if(n1 == 1)
    f(n) = f(10bit-1) + f(n - 10bit) + n - 10bit+ 1;
else
    f(n) = n1*f(10bit-1) + f(n – n1*10bit) + 10bit;
```

进一步可以归结为
```c
f(n) = n1*f(10bit-1) + f(n – n1*10bit) + LEFT;
其中
if(n1 == 1)
    LEFT = n - 10bit+ 1;
else
    LEFT = 10bit;
```

此算法的优点是不用遍历1~N就可以得到f(N)。经过我测试，此算法的运算速度比解法一快了许多许多，数字在1010内时，算法都可以在毫秒级内结束，

```cpp

class Solution
{
public:
    /**
     * [NumberOf1Between1AndN_Solution 统计1到n的整数中1出现的次数]
     * @Author   gatieme
     * @DateTime 2016-05-01T22:03:43+0800
     * @param    n                        [整数n]
     * @return                            [1到n的整数中1出现的次数]
     */
    int NumberOf1Between1AndN_Solution(int n)
    {
        return CountOne(n);
    }

    int CountOne(int n)
    {
        long count = 0;

        if (n == 0)
        {
            count = 0;
        }
        else if (n > 1 && n < 10)
        {
            count =  1;
        }
        else
        {
            // 计算n的位数
            long highest = n;       //表示最高位的数字
            int bit = 0;
            while (highest >= 10)
            {
                highest = highest / 10;
                bit++;
            }
            //  循环结束时, bit表示n的位数, 而highest是其最高位的数字

            //int weight = (int)Math.Pow(10, bit);//代表最高位的权重，即最高位一个1代表的大小
            int weight = pow(10, bit);//代表最高位的权重，即最高位一个1代表的大小

            if (highest == 1)
            {
                count = CountOne(weight - 1)
                      + CountOne(n - weight)
                      + (n - weight + 1);
            }
            else
            {
                count = highest * CountOne(weight - 1)
                      + CountOne(n - highest * weight)
                      + weight;
            }
        }

        return count;
    }
};
```

或者直接
```c
class Solution
{
public:
    /**
     * [NumberOf1Between1AndN_Solution 统计1到n的整数中1出现的次数]
     * @Author   gatieme
     * @DateTime 2016-05-01T22:03:43+0800
     * @param    n                        [整数n]
     * @return                            [1到n的整数中1出现的次数]
     */
    int NumberOf1Between1AndN_Solution(int n)
    {
        return CountOne(n);
    }

    int CountOne(int n)
    {
        debug <<"now N = " <<n <<endl;
        long count = 0;

        if (n == 0)
        {
            debug <<"Fun(0) = " <<0 <<endl;
            count = 0;
        }
        else if (n > 1 && n < 10)
        {
            debug <<"Fun(" <<n <<") = " <<1 <<endl;
            count =  1;
        }
        else
        {
            // 计算n的位数
            long highest = n;       //表示最高位的数字
            int bit = 0;
            while (highest >= 10)
            {
                highest /= 10;
                bit++;
            }
            //  循环结束时, bit表示n的位数, 而highest是其最高位的数字

            //int weight = (int)Math.Pow(10, bit);//代表最高位的权重，即最高位一个1代表的大小
            int weight = pow(10, bit);//代表最高位的权重，即最高位一个1代表的大小
            int left = (highest == 1) ? (n - weight + 1) : weight;

            debug <<"Fun(" <<n <<") = "
                  /*
                  <<"Fun(10^" <<bit <<" - 1) + "
                  <<"Fun(" <<n <<" - 10^" <<bit <<") + "
                  <<weight <<" = "
                  */
                  <<highest <<" * Fun(" <<weight <<" - 1) + "
                  <<"Fun(" <<n <<" - " <<highest <<" * " <<weight <<") + "
                  <<weight <<endl;
            count = highest * CountOne(weight - 1)
                      + CountOne(n - highest * weight)
                      + left;
            debug <<"Now will continue " <<weight - 1 <<", " <<n - highest * weight <<endl <<endl;
        }

        return count;
    }
};
```
这种思路每次去掉最高位然后进行递归，递归的次数和位数相同。

一个数字n有$O(logN)$位，因此算法的时间复杂度是$O(logN)$

总结

<font color=#0099ff>
任意一个n位数中"1"的个位可以分解为两个n-1位数中"1"的个数的和，最后再加上一个与最高位数相关的常数LEFT
</font>


>f(n) = n1*f(10bit-1) + f(n – n1*10bit) + LEFT;

<font color=#0099ff>
最后加的常数LEFT只跟最高位n1是否为1有关, 它是最高位出现的次数
</font>

*   如果最高为n1 = 1, 如132, 则剩余100~132的最高位百位的1出现了LEFT = n - 10 * bit+ 1次

*   如果最高位n1 > 1, 如232, 则100~199(其实是到232)最高位的1出现了LEFT=10*bit次
</font>



#发现规律
-------



解法二（分治法）告诉我们1~ N中"1"的个数跟最高位有关，那我们换个角度思考，给定一个N，我们分析1~N中的数在每一位上出现1的次数的和，看看每一位上"1"出现的个数的和由什么决定。

**1位数的情况**

*    在解法二中已经分析过，大于等于1的时候，有1个，小于1就没有。



**2位数的情况**

*    N=13,个位数出现的1的次数为2，分别为1和11，十位数出现1的次数为4，分别为10,11,12,13，所以f(N) = 2+4。

*    N=23,个位数出现的1的次数为3，分别为1，11，21，十位数出现1的次数为10，分别为10~19，f(N)=3+10。

由此我们发现，



<font color=#0099ff face="黑体">**个位数出现1的次数不仅和个位数有关，和十位数也有关**<font>

1.    如果个位数大于等于1，则个位数出现1的次数为十位数的数字加1；

2.    如果个位数为0，个位数出现1的次数等于十位数数字。



<font color=#0099ff face="黑体">**而十位数上出现1的次数也不仅和十位数相关，也和个位数相关**<font>

1.    如果十位数字等于1，则十位数上出现1的次数为个位数的数字加1

2.    假如十位数大于1，则十位数上出现1的次数为10。



**3位数的情况**

N=123，个位出现1的个数为13:1,11,21，…，91,101,111,121。十位出现1的个数为20:10~19,110~119。百位出现1的个数为24:100~123。



**4，5位数的情况**

我们可以继续分析4位数，5位数，推导出下面一般情况：

假设N，<font color=#0099ff face="黑体">我们要计算百位上出现1的次数，将由三部分决定：百位上的数字，百位以上的数字，百位以一下的数字。<font>

1.    如果百位上的数字为0，则百位上出现1的次数仅由更高位决定，比如12013，百位出现1的情况为100~199,1100~1199,2100~2199，…，11100~11199，共1200个。等于更高位数字乘以当前位数，即12 * 100。

2.    如果百位上的数字大于1，则百位上出现1的次数仅由更高位决定，比如12213，百位出现1的情况为100~199,1100~1199,2100~2199，…，11100~11199，12100~12199共1300个。等于更高位数字加1乘以当前位数，即（12 + 1）*100。

3.    如果百位上的数字为1，则百位上出现1的次数不仅受更高位影响，还受低位影响。例如12113，受高位影响出现1的情况：100~199,1100~1199,2100~2199，…，11100~11199，共1200个，但它还受低位影响，出现1的情况是12100~12113，共114个，等于低位数字113+1。

```cpp
class Solution
{
public:
    /**
     * [NumberOf1Between1AndN_Solution 统计1到n的整数中1出现的次数]
     * @Author   gatieme
     * @DateTime 2016-05-01T22:03:43+0800
     * @param    n                        [整数n]
     * @return                            [1到n的整数中1出现的次数]
     */
    int NumberOf1Between1AndN_Solution(int n)
    {
        long count = 0;

        long i = 1;

        long current = 0,after = 0,before = 0;

        while((n / i) != 0)
        {
            before = n / (i * 10);
            current = (n / i) % 10;
            after = n - (n / i) * i;
            if (current > 1)
            {
                count = count + (before + 1) * i;
            }
            else if (current == 0)
            {
                 count = count + before * i;
            }
            else if(current == 1)
            {
                count = count + before * i + after + 1;
            }
            debug <<before <<" " <<current <<" " <<after <<", count = " <<count <<endl;


            i = i * 10;

        }

        return count;

    }
};
```

以下分析摘自[每日一题(58) - 从1到n整数中1出现的次数](http://blog.csdn.net/insistgogo/article/details/9672603)，方便大家理解
假设数字为abcde，对于abcde中的每一个数字，可以根据该数字与1的关系，求在该数字对应位置上1出现的次数。

具体来说：

假设我们要求百位出现1的次数，此时我们可以根据c与1的关系，求出百位1出现的次数。
（1）如果c = 0，则1出现的次数等于ab * 100，即 c前面的数 * c对应的基数
在该情况下，百位出现1的次数只与c前面的数有关。
（2）如果c = 1，则1出现的次数等于（ab * 100） + （de + 1），即（c前面的数 * c对应的基数） +（ c后面的数 + 1）
在该情况下，百位出现1的次数与c前面和c后面的数有关。
（3）如果c = 2，则1出现的次数等于（ab + 1）*100，即（c前面的数 +1）* c对应的基数
在该情况下，百位出现1的次数只与c前面的数有关。
举例：
对于12013，在百位处出现1的次数= 12 * 100 = 1200次
其分别是，00100 -00199,01100 -01199,02100 - 02199,...,11100 - 11199。
（1）由于因为百位 = 0，则以12为开头的数不会含有1。
（2）百位前面的数值能有00 - 11，即出现12次。由于百位后的数字有两位，因此其基数为100。
即，以00 - 11为开头的数，后面都可以由00 变化到99，即包含了所有1的情况。

对于12113，在百位处出现1的次数= （12 * 100 ） + （13+1）= 1214次
（1）包含足够1的情况：00100 - 00199,01100 - 01199,02100 - 02199,...,11100 - 11199
（2）包含部分1的情况：12100 - 12113
即，由于百位 = 1，则以00 - 12为开头的数在百位都含有1。
（1）当百位前面的数字为00-11时，此情况包含了所有1的情况。（00-99）
（2）当百位前面为数字为12时，此情况仅仅包含了部分1的情况（00-13）

对于12213，在百位处出现1的次数= （12+1） * 100 = 1300次
其分别是，00100 - 00199,01100 - 01199,02100 - 02199,...,11100 - 11199，12100 - 12199。
此时，百位前面的数无论怎么变化，后面都可以由00 变化到99，即包含了所有1的情况。
