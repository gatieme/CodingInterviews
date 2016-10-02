#链接
------- 
>牛客OJ：[求1+2+3+...+n](http://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1?tpId=13&tqId=11200&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
> 
>九度OJ：http://ac.jobdu.com/problem.php?pid=1506
> 
>GitHub代码： [046-求1+2+3+...+n](https://github.com/gatieme/CodingInterviews/tree/master/046-求1+2+3+...+n)
>
>CSDN题解：[剑指Offer--046-求1+2+3+...+n](http://blog.csdn.net/gatieme/article/details/51485713)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 |
| ------------- |:-------------:| -----:| -----:|
|[046-求1+2+3+...+n](http://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1?tpId=13&tqId=11200&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | [1506-求1+2+3+...+n](http://ac.jobdu.com/problem.php?pid=1506) | [剑指Offer--046-求1+2+3+...+n](http://blog.csdn.net/gatieme/article/details/51485713) | [046-求1+2+3+...+n](https://github.com/gatieme/CodingInterviews/tree/master/046-求1+2+3+...+n) |



#题意
-------


**题目描述**


>求1+2+3+...+n，


要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

**样例输入**
>3
>
>5

**样例输出**

>6
>
>15





#递归+短路判断终止
-------

计算1+2+3+...+n, 可以认为是一个**递归**的过程, 这点很容易理解

但是怎么不用分支判断来保证递归的终止呢

还记得我们的调试语句么
```cpp
#ifdef __tmain
    #define debug cout
#else
    #define debug 0 && cout
#endif // __tmain
```

如果不希望使用调试模式，则通过短路运算`0 && cout`使条件为假值, 从而不执行输出语句，那么我们也可以通过短路来实现循环终止, 

*    从n开始递减进程递归的相加运算
*    当递归至0时使递归短路即可

代码如下

```cpp
class Solution
{
public:
    int SumRecursion(int n)
    {
        int ans = n;
        //debug <<n <<endl;
        n && (ans += SumRecursion(n - 1));
        return ans;
    }
};
```

其实也可以用下面的语句

>ans && (ans += Sum_Solution(n - 1));

ans每次均被初始化为n, 因此用n或者ans进行短路运算都可以，其本质就是通过n进行短路运算判断

#位运算计算$1+2+3+...+n=n(n+1)/2$
-------

我们其实知道，等差数列求和的问题

$1+2+3+...+n=\frac{n(n+1)}{2}$

但是$\frac{n(n+1)}{2}$是一个乘除的运算, 本题限制使用乘除，因此我们得另寻它法

我们知道a*b运算在计算机内部其实是通过移位和加法来完成的

```c
int Multi(int a, int b)
{
    int res = 0;
    while(a != 0)
    {
        if((a & 1) != 0)
        {
            res += b;
        }
        a >>= 1;
        b <<= 1;

    }

    return res;
}
```

那么我们的结果就是

>Multi(n, n + 1) >>1
但是我们的乘法函数中仍然有循环和判断, 因此我们需要进一步优化, 

还是上面的策略，
*    循环用递归来代替
*    分支用短路运算来代替

那么我们的乘法运算就成为
```c
int MultiRecursion(int a, int b)
{
    static int res = 0;
    a && MultiRecursion(a >> 1, b << 1);    //  递归的进行运算
    (a & 1) && (res += b);                  //  短路

    return res;
}
```

最后完成代码如下
```c
class Solution
{
public:
    int res;
    int Sum_Solution(int n)
    {
        res = 0;
        return (MultiRecursion(n, n + 1) >> 1);
    }

    int MultiRecursion(int a, int b)
    {
        a && MultiRecursion(a >> 1, b << 1);    //  递归的进行运算

        (a & 1) && (res += b);                  //  短路


        return res;
    }

};
```

网上还有类似的写法，如下,
```cpp
 bool f(int k,int n,int &ans,int s,int t)
    {
        ans = ans + ((t<<s)&(~(p+(n&1))));
        return k<32 &&  f(k+1,n>>1,ans,s+1,t);
    }
    int Sum_Solution(int n)
    {
        int t = n+1;
        int k = 0;
        int ans = 0;
        int s = 0;
        f(k,n,ans,s,t);
        ans>>=1;
        return ans;
    }
};
```

#利用构造函数求解
-------

循环操作也只是累加了N次, 重复的让相同的代码执行了N次

还记得我们C++里面类对象里面的静态计数器么的设计么, 静态的count可以在构造函数中进行累加, 从而维护出类对象的个数

那么我们采用相同的思路, 在类的构造函数里面进行计数器的累加和求和操作, 构造出N个对象即可完成所需操作
```c
class Temp
{
public :
    Temp( )
    {
        ++N;
        Sum += N;
    }

    static void Reset( )
    {
        N = 0;
        Sum = 0;
    }

    static unsigned int GetSum( )
    {
        return Sum;
    }

private :
    static unsigned int N;
    static unsigned int Sum;
};

unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;

class Solution
{
public:
    int res;
    int Sum_Solution(int n)
    {
        Temp::Reset( );

        Temp *a = new Temp[n];
        delete[] a;
        a = NULL;

        return Temp::GetSum( );
    }
};
```




#利用虚函数求解
-------

我们同样可以围绕递归做文章, 既然不能在一个函数中通过分支判断是不是终止递归

我们可以<font color = 0x00ffff>定义两个函数, 一个函数充当递归函数的角色，另一个函数处理终止递归的情况, </font>

而我们需要在两个函数中二选一, 从二选一我们自然的想到了布尔变量, 比如值为true的时候调用第一个, 值为false的时候, 调用第二个函数, 

那么我们怎么把一个值n转换为布尔类型呢, 如果对n连续做两次反运算, 即!!n, 那么非零的n转换为true, 0转换为false

代码如下


```cpp
class base;
base *parray[2];

class base{
public:
    virtual unsigned int sum(unsigned int n)
    {
        //  递归的终止
        return 0;
    }
};

class derive :public base{
public:
    virtual unsigned int sum(unsigned int n)
    {
        //  !!n两次非运算, 从而将n转换为bool类型, 来选择函数
        //  sum(n) = sum(n - 1) + n 则是递归公式
        return parray[!!n]->sum(n - 1) + n;
    }
};


class Solution
{
public:
    int Sum_Solution(int n)
    {

        base a;
        derive b;

        parray[0] = &a;
        parray[1] = &b;

        return parray[1]->sum(n);
    }
};


int main(){

    Solution s;

    cout<<s.Sum_Solution(10);

    return 0;
}
```

#利用函数指针求解
-------

前面那个例子我们通过了C++的虚函数和多态的特性来实现了函数的选择, 但是其实我们用函数指针也可以实现选择函数

```c
typedef int (*func)(int);

// 递归的终止函数
int Teminator(int n)
{
    return 0;
}

//  递归函数, 选择函数进行递归
int Recursion(int n)
{
    static func pf[2] =
    {
        Teminator,
        Recursion,
    };

    return n + pf[!!n](n - 1);
}


class Solution
{
public :
    int Sum_Solution(int n)
    {
        return Recursion(n);
    }

};
```

#利用模板类型求解
-------

利用编译器帮助完成类似于递归的运算
```cpp
#include <iostream>

using namespace std;

template < unsigned int n>
struct Sum
{
    enum Value
    {
        N = Sum< n - 1 >::N + n
    };
};

template <>
struct Sum<1>
{
    enum Value
    {
        N = 1
    };
};


int main( )
{

    cout <<Sum<100>::N <<endl;

    return 0;
}
```

Sum<100>::N就是1+2++...+100的结果, 当编译器看到Sum<100>::N时, 就会为模板类Sum以参数100生成对象, 而由于这个类的定义是递归的, 因此编译器会一直递归的操作, 直至参数为1, 递归结束。

缺陷

1.    由于这个过程是由编译器在编译阶段完成的, 因此要求n必须是一个编译期间就能确定的常量, 不能动态定义

2.    编译器对递归编译代码的递归深度是由限制的, 因此要去n不能太大。



#数组指针+求和公式
-------


>感谢[网友aheadlead](https://github.com/aheadlead)提供了方法,
>
> 参见https://github.com/gatieme/CodingInterviews/commit/82641aa505c99983339a7fb64fc57df6d30bbaef

使用经典的求和公式。但是使用数组指针绕开了不能使用乘法的问题。

```c
printf("%d\n", ( (int)( &( (uint8_t (*) [n])0)[1+n][0])) >> 1
);
```

完整代码如下

```cpp
#include <stdio.h>
#include <stdint.h>

int rich(int n)
{
    return ( (int)( &((uint8_t (*) [n])0)[1+n][0]) ) >> 1;
}

int main()
{
    printf("%d\n", rich(10));

    return 0;
}
```