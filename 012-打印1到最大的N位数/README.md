#链接
------- 

>牛客OJ：未收录
> 
>九度OJ：http://ac.jobdu.com/problem.php?pid=1515
> 
>GitHub代码： [012-打印1到最大的N位数](https://github.com/gatieme/CodingInterviews/tree/master/012-%E6%89%93%E5%8D%B01%E5%88%B0%E6%9C%80%E5%A4%A7%E7%9A%84N%E4%BD%8D%E6%95%B0)
>
>CSDN题解：[剑指Offer--012-打印1到最大的N位数](http://blog.csdn.net/gatieme/article/details/51132108)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 | 
| ------------- |:-------------:| -----:| 
| 未收录  | [1515-打印1到最大的N位数](http://ac.jobdu.com/problem.php?pid=1515) | [剑指Offer--012-打印1到最大的N位数](http://blog.csdn.net/gatieme/article/details/51132108) | [012-打印1到最大的N位数](https://github.com/gatieme/CodingInterviews/tree/master/012-%E6%89%93%E5%8D%B01%E5%88%B0%E6%9C%80%E5%A4%A7%E7%9A%84N%E4%BD%8D%E6%95%B0)|



<br>
**您也可以选择[回到目录-剑指Offer--题集目录索引](http://blog.csdn.net/gatieme/article/details/51916802)**



#题意
-------

**题目描述**


>给定一个数字N，打印从1到最大的N位数。

**输入**


>每个输入文件仅包含一组测试样例。
>
>对于每个测试案例，输入一个数字N(1<=N<=5)。
**输出**
>对应每个测试案例，依次打印从1到最大的N位数。

**样例输入**

>1

**样例输出**

>1
>2
>3
>4
>5
>6
>7
>8
>9

#最简单的解法--跳进面试官的陷阱
-------
```cpp
#include <iostream>
#include <cmath>

using namespace std;

//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain



class Solutin
{
public :
    void Print(int n)
    {
        int max = pow(10, n);
        for(int i = 1; i < max; i++)
        {
            cout <<i <<endl;
        }
    }

};


int __tmain( )
{
    Solutin solu;

    int n;
    while(cin >> n)
    {

        solu.Print(n);
    }
    return 0;
}

```

好像没有什么问题，但是仔细分析你就会发现，N的范围并不确定，我们没法保证这些数是不是超出了INT_MAX的表示范围。

当n过大的时候，就会溢出，这时候我们的程序输出的值是不确定或者说是被截断的


#字符串是大数问题最值得信赖的方案
-------
我们的思路是：
*    初始就开辟一个N+1大小的串，用来存储数字

*    用字符串模拟数字的自增，进位，输出

*    当串长度超过N+1时，或者第0位产生进位时就溢出

```cpp
#include <iostream>
#include <cstring>
using namespace std;

//  调试开关
//#define DEBUG
#define __tmain main

#ifdef DEBUG

#define debug cout

#else

#define debug 0 && cout

#endif // DEBUG



class Solutin
{
public :
    Solutin(int n)
    {
        this->m_N = n;
        this->m_isOverFlow = false;

        this->m_number = new char[n + 1];
        memset(m_number, '\0', n + 1);
        this->m_number[n - 1] = '1';
        this->m_length = 1;

        //  m_N 总是 >= m_length
        //  真正的信息串存储在m_number[m_N - length, m_N);
    }

    void Print( )
    {
        if(m_N <= 0)
        {
            return;
        }
        while(this->m_isOverFlow != true)
        {
            PrintNumber( );
            Increment( );

        }




    }

    void PrintNumber( )
    {
        //  m_N 总是 >= m_length
        //  真正的信息串存储在m_number[m_N - length, m_N);
        debug <<"number is stroge in [" <<m_N - m_length <<", " <<m_N <<")" <<endl;
        for(int i = m_N - m_length; i < m_N; i++)
        {
            cout<<m_number[i];
        }
        cout <<endl;
    }


    bool Increment( )
    {
        int nSum = 0;               //  当前位
        int takeOver = 0;           //  进位
        for(int i = m_N - 1; i >= m_N - m_length; i--)
        {
            if(m_number[i] != '\0')
            {
                nSum = m_number[i] - '0' + takeOver;
            }
            else
            {
                nSum = 0;
            }
            nSum++;
            debug <<"nSum = " <<nSum <<endl;

            if(nSum >= 10)      //  需要进位
            {
                if(i == 0)      //  溢出了, 则循环终止
                {
                    m_isOverFlow = true;
                    debug <<"Over Flow now" <<endl;
                    delete m_number;
                }
                else
                {
                    nSum -= 10;
                    m_number[i] = '0' + nSum;

                    takeOver = 1;                   //  需要进位, 继续循环
                    if(i == m_N - m_length)           //  此时说明进位在最高位, 长度会增加1
                    {
                        m_length++;
                        debug <<"take over now ( length = " <<m_length <<" )";
                    }
                }
            }
            else                //  没有进位, 则当前位增加1以后循环立即结束
            {
                if(takeOver == 1)
                {
                    debug <<"it's a take over" <<endl;
                }
                m_number[i] = '0' + nSum;
                break;
            }
        }
    }
private :
    int             m_N;                    //  N位数
    char            *m_number;              //  存储数据的字符串
    bool            m_isOverFlow;           //  是否溢出, 溢出时说明无需继续输出
    volatile int    m_length;               //  当前数字的位数

};


int __tmain( )
{


    int n;
    while(cin >> n)
    {
        Solutin solu(n);
        solu.Print( );
    }
    return 0;
}

```

#递归--转换为数字排列的解法
-------

上面的算法已经很不错了，但是代码复杂，要在短时间内完成这样思路清晰而缜密的代码有点困难，因此我们需要更加简洁的方法

>如果我们在数字前面补上0的话，那么我们发现，n位所有的十进制数起始就是n个从0到9的全排列。
>
>也就是说，我们把数字的每一位都从0到9排列一遍，就得到了所有的十进制数。

只要我们在打印的时候，数字排在前面的0不用打印出来而已。

*    全排列用递归很容易表示，数字的每一位都可能是0~9中的一个数，然后设置下一位。

*    递归结束的条件是我们已经设置了数字的最后一位
```cpp
#include <iostream>
#include <cstring>
using namespace std;

//  调试开关
#define DEBUG
#define __tmain main

#ifdef DEBUG

#define debug cout

#else

#define debug 0 && cout

#endif // DEBUG



class Solutin
{
public :
    void PrintToMaxOfNDigits(int n)
    {
        if(n <= 0)
        {
            return ;
        }

        char *number = new char[n + 1];
        number[n] = '\0';

        //  最地位循环0~9
        for(int i = 0; i < 10; i++)
        {
            debug <<"now list all " <<i <<"in the low position" <<endl;
            number[0] = i + '0';
            PrintToMaxOfNDigitsRecursively(number, n, 0);
        }

        delete[] number;
    }

    void PrintToMaxOfNDigitsRecursively(char *number, int length, int index)
    {
        if(index == length - 1)
        {
            debug <<"we find a number" <<endl;
            PrintNumber(number);
            return ;
        }

        //  当前位循环0~9
        for(int i = 0; i < 10; i++)
        {
            number[index + 1] = i + '0';
            debug <<"now, index = " <<index <<", digit = " << number[index + 1] <<endl;
            PrintToMaxOfNDigitsRecursively(number, length , index + 1);
        }
    }

    void PrintNumber(char *number)
    {
        int i = 0;
        int length = strlen(number);
        for(i = 0; i < length; i++)
        {
            if(number[i] != '0')
            {
                break;
            }
        }
        if(i != length)         //  开始的0不应该输出
        {
            cout <<&number[i] <<endl;
        }

    }
};


int __tmain( )
{


    int n;
    Solutin solu;

    while(cin >> n)
    {
        solu.PrintToMaxOfNDigits(n);
    }
    return 0;
}

```


