#链接
-------


>牛客OJ：[数组中只出现一次的数字](http://www.nowcoder.com/practice/e02fdb54d7524710a7d664d082bb7811?tpId=13&tqId=11193&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
>
>九度OJ：http://ac.jobdu.com/problem.php?pid=1351
>
>GitHub代码： [040-数组中只出现一次的数字](https://github.com/gatieme/CodingInterviews/tree/master/040-数组中只出现一次的数字)
>
>CSDN题解：[剑指Offer--040-数组中只出现一次的数字](
http://blog.csdn.net/gatieme/article/details/51352156)



| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 |
| ------ |:------:| --------:|:----------:|
|[040-数组中只出现一次的数字](http://www.nowcoder.com/practice/e02fdb54d7524710a7d664d082bb7811?tpId=13&tqId=11193&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | [1351-数组中只出现一次的数字](http://ac.jobdu.com/problem.php?pid=1351) | [剑指Offer--040-数组中只出现一次的数字](http://blog.csdn.net/gatieme/article/details/51352156) | [040-数组中只出现一次的数字](https://github.com/gatieme/CodingInterviews/tree/master/040-数组中只出现一次的数字) |


<br>**您也可以选择[回到目录-剑指Offer--题集目录索引](http://blog.csdn.net/gatieme/article/details/51916802)**


#题意
-------


**题目描述**


>一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字



**样例输入**


>2 4 3 6 3 2 5 5


**样例输出**

>4 6


#分析
-------

此题考察的是异或运算的特点：即两个相同的数异或结果为0。

此题用了两次异或运算特点：

*    第一次使用异或运算，得到了两个只出现一次的数相异或的结果。

*    因为两个只出现一次的数肯定不同，即他们的异或结果一定不为0，一定有一个位上有1。

另外一个此位上没有1，我们可以根据此位上是否有1，将整个数组重新划分成两部分，

一部分此位上一定有1，另一部分此位上一定没有1，

然后分别对每部分求异或，因为划分后的两部分有这样的特点：其他数都出现两次，只有一个数只出现一次。因此，我们又可以运用异或运算，分别得到两部分只出现一次的数。

#代码
-------

```cpp
#include <iostream>
#include <vector>
#include <bitset>

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
    #define INT_SIZE (sizeof(int) * 8)

    #define IS_BIT(number, index) (((number) & (1 << (index))) >>index)

    void FindNumsAppearOnce(vector<int> array, int *num1, int *num2)
    {
        *num1 = *num2 = 0;
        if(array.size( ) < 2)
        {
            return ;
        }
        int XOR = array[0];
        for(int i = 1; i < array.size( ); i++)
        {
            XOR ^= array[i];
        }

        debug <<bitset<INT_SIZE>(XOR) <<endl;

        ///  查找到1的位置
        int index = 0, temp = 1;
        for(; index < INT_SIZE; index++)
        {
            if((XOR & temp) == temp)
            {
                break;
            }
            temp <<= 1;
        }
        debug <<index <<endl;
        if(index == INT_SIZE)
        {
            debug <<"no two numbers which once" <<endl;
            return;
        }
        debug <<"find 1 in index = " <<index <<endl;
        debug <<IS_BIT(XOR, index) <<endl;
        //  于是我们知道那两个只出现一次的数字, 第index位必然不相同
        //  因此 我们将数组划分成两部分
        //  一部分index位是0
        //  另外一部分index位是1
        *num1 = *num2 = 0;// 也可以等于XOR
        for(int i = 0; i < array.size( ); i++)
        {
            if(IS_BIT(array[i], index) == 1)
            {
                *num1 ^= array[i];
            }
            else
            {
                *num2 ^= array[i];
            }
        }
    }
};


int __tmain( )
{
    Solution solu;

    int arr[] = { 2, 4, 3, 6, 3, 2, 5, 5, };
    vector<int> vec(arr, arr + 8);

    int num1, num2;
    solu.FindNumsAppearOnce(vec, &num1, &num2);
    cout <<"RESULT : " <<num1 <<", " <<num2 <<endl;
    return 0;
}
```


找xor中最后一个1的位置的时候，可以用$(XOR & (-XOR))$

由于计算机内部整数按照补码来存储，补码的表示方法是:

* 正数的补码就是其本身

* 负数的补码是在其原码（原码就是符号位加上真值的绝对值, 即用第一位表示符号, 其余位表示值.）的基础上, 符号位不变, 其余各位取反, 最后+1. (即在反码的基础上+1)

* 更简单的方法是，符号位不变，从最低位开始，指导遇见第一个1，这个1后面的都不变，前面的所有位依次取反。

因此我们会发现，XOR与-XOR的区别就是最低位起始的第一个1相同，然后前面的bit位置正好相反

因此XOR & (-XOR)的值正好就是仅有一位为1，而这个位置正好是XOR最低位1的位置

代码
```cpp
class Solution
{
public:
    #define INT_SIZE (sizeof(int) * 8)

    #define IS_BIT(number, index) (((number) & (1 << (index))) >>index)

    void FindNumsAppearOnce(vector<int> array, int *num1, int *num2)
    {
        *num1 = *num2 = 0;
        if(array.size( ) < 2)
        {
            return ;
        }
        int XOR = array[0];
        for(int i = 1; i < array.size( ); i++)
        {
            XOR ^= array[i];
        }

        debug <<bitset<INT_SIZE>(XOR) <<endl;

        ///  查找到1的位置
        int flag = XOR & (-XOR);
        debug <<bitset<INT_SIZE>(flag) <<endl;
        *num1 = *num2 = XOR;// 也可以等于XOR
        for(int i = 0; i < array.size( ); i++)
        {
            if((array[i] & flag) == flag)
            {
                *num1 ^= array[i];
            }
            else
            {
                *num2 ^= array[i];
            }
        }
    }
};
```
