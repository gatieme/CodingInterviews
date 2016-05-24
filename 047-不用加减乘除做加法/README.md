#链接
------- 
>牛客OJ：[不用加减乘除做加法](http://www.nowcoder.com/practice/59ac416b4b944300b617d4f7f111b215?tpId=13&tqId=11201&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
> 
>九度OJ：http://ac.jobdu.com/problem.php?pid=1507
> 
>GitHub代码： [047-不用加减乘除做加法](https://github.com/gatieme/CodingInterviews/tree/master/047-不用加减乘除做加法)
>
>CSDN题解：[剑指Offer--047-不用加减乘除做加法](http://blog.csdn.net/gatieme/article/details/51493414)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 | 
| ------------- |:-------------:| -----:| -----:|
|[047-不用加减乘除做加法](http://www.nowcoder.com/practice/59ac416b4b944300b617d4f7f111b215?tpId=13&tqId=11201&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | [1507-不用加减乘除做加法](http://ac.jobdu.com/problem.php?pid=1507) | [剑指Offer--047-不用加减乘除做加法](http://blog.csdn.net/gatieme/article/details/51493414) | [047-不用加减乘除做加法](https://github.com/gatieme/CodingInterviews/tree/master/047-不用加减乘除做加法) |



#题意
-------


**题目描述**

>写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。


**样例输入**


>3 4
>
>7 9


**样例输出**


>7
>
>16


#C/C++内敛汇编
-------

通过内敛汇编我们直接使用add指令来进行相加操作

>C/C++内敛汇编使用AT&T汇编语法
>
>在INTEL语法中，第一个表示目的操作数，第二个表示源操作数，赋值方向从右向左。
>
>AT&T语法第一个为源操作数，第二个为目的操作数，方向从左到右，合乎自然。 

```cpp
class Solution
{
public:
    int Add(int left, int right)
    {
        __asm__ __volatile__
        (
            //"lock;\n"
            "addl %1,%0;\n"     /* 相当于 add b, a结果存储在a中*/
            : "=m"(left)
            : "r"(right), "m"(left)
          //  :
        );

        return left;
    }
};
```


#位运算模拟加法
-------
如何用位运算来模拟加法操作呢

基本的位操作符有与、或、异或、取反、左移、右移这6种，它们的运算规则如下所示：

| 符号 | 描述 | 运算规则 |
| ----- |:-----:| ----------:|
| & | 与 | 有0则0, 全1则1(两个位都为1时，结果才为1) |
|  \|  | 或 | 有1则1, 全0则0(两个位都为0时，结果才为0) |
| ^ | 异或 | 相同则0, 不同则1 |
| ~ | 取反 | 0变1, 1变0 |
| << | 左移 | 各二进位全部左移若干位，高位丢弃，低位补0 |
| \>> | 右移 | 各二进位全部右移若干位，对无符号数，高位补0，有符号数，各编译器处理方法不一样，有的补符号位（算术右移），有的补0（逻辑右移）|

有这么多位运算的规则, 我们从中看看有没有能够利用的

**怎么模拟加法**
>用异或可以模拟不带进位的加法运算, 因为异或相同则0, 不同则1, 正好与不带进位的加法结果相同
>

**那么怎么判断出进位呢**

>进位的产生主要是1+1=10, 我们看到与操作可以判断两个位是不是需要进位, 
>
>可见用与运算可以模拟出每一位的是否有进位

**但是怎么表示进位呢?**

>进位无非是进到上一位去, 因此我们直接与的结果左移一位即得进位

由此我们得到了两个数, 

*    一个是异或运算得出的不带进位的结果, 
*    一个是两个相加的所有进位

发现什么, 我们反复的将两个数进行加法操作, 直到没有进位的时候, 那么结果就是我们想要的

过程如下

首先看十进制是如何做的： 5+7=12，三步走

1.    相加各位的值，不算进位，得到5 + 7 = 2（不算进位）

2.    计算进位值，得到10. 如果这一步的进位值为0，那么第一步得到的值就是最终结果。

3.    重复上述两步，只是相加的值变成上述两步的得到的结果2和10，得到12。

我们可以用三步走的方式计算二进制值相加： 

>  5 -=> 101
>  7 -=> 111 

1.    相加各位的值，不算进位，得到010，二进制每位相加就相当于各位做异或操作，101^111=010

2.    计算进位值，得到1010，相当于各位做与操作得到101，再向左移一位得到1010，(101&111)<<1。

3.    重复上述两步， 各位相加 010^1010=1000，进位值为100=(010&1010)<<1。
     
4.    继续重复上述两步：1000^100 = 1100，进位值为0，跳出循环，1100为最终结果。

代码如下

```cpp
class Solution
{
public:
    int Add(int left, int right)
    {
        int temp;
        while(right != 0)
        {
            temp = left ^ right;                //  计算不带进位的情况
            right = (left & right) <<1;         //  计算带进位的情况
            left = temp;
            //  now left = 不带进位的情况, right = 带进位的情况
        }

        return left;
    }
};
```

当然我们也可以用递归来是实现
```cpp
class Solution
{
public:
    int Add(int left, int right)
    {

        return right == 0 ? left : Add(left ^ right, (left & right) << 1);
    }
};
```


