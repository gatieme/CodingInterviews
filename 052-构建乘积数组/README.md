#链接
------- 
>牛客OJ：[构建乘积数组](http://www.nowcoder.com/practice/94a4d381a68b47b7a8bed86f2975db46?tpId=13&tqId=11204&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
> 
>九度OJ：未收录
> 
>GitHub代码： [052-构建乘积数组](https://github.com/gatieme/CodingInterviews/tree/master/052-构建乘积数组)
>
>CSDN题解：[剑指Offer--052-构建乘积数组](http://blog.csdn.net/gatieme/article/details/51541100)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 | 
| ------------- |:-------------:| -----:| -----:|
|[052-构建乘积数组](http://www.nowcoder.com/practice/94a4d381a68b47b7a8bed86f2975db46?tpId=13&tqId=11204&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | 未收录 | [剑指Offer--052-构建乘积数组](http://blog.csdn.net/gatieme/article/details/51541100) | [052-构建乘积数组](https://github.com/gatieme/CodingInterviews/tree/master/052-构建乘积数组) |


#题意
-------


**题目描述**

>给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
>
>不能使用除法。

**样例输入**

> [1, 2, 3, 4, 5]


**样例输出**

>[120, 60, 40, 30, 24]

#分析
-------

>那么对于新数组ans[i]，我们从前往后遍历，可求得了A[1]*A[2]*...*A[i-1]，
>
>然后我们再从尾到头扫描一遍，对于当前第i位，我们任然按照前面的思想，累乘A[len-1]*...A[i+1]

例如：A[]={1,2,3}求B[]

B[0]=A[1]×A[2]=2×3=6


B[1]=A[0]×A[2]=1×3=3


B[2]=A[0]×A[1]=1×2=2



1.    B[0]初始化为1，从下标i=1开始，先求出C[i]的值并放入B[i],即B[i]=C[i]=C[i-1]×A[i-1]，所以B[1]=B[1-1]×A[1-1]=B[0]×A[0]=1×1=1,i++



2.    B[2]=B[2-1]×A[2-1]=B[1]×A[1]=1×2=2,i++超出长度停止循环



3.    C[i]计算完毕求D[i],设置一个临时变量temp初始化为1



4.    从后往前变量数组，LengthA=3初始化i=LengthA-2=1,结束条件为i>=0



5.    第一次循环，temp=temp×A[i+1]=1×A[2]=3,计算出A中最后一个元素的值放入temp,temp相当于D[i]的值



6.    因为之前的B[i]=C[i],所以让B[i]×D[i]就是要保存的结果，即B[i]=B[1]=B[1]×temp=1×3=3,i–=0



7.    计算B[i]=B[0],temp上一步中的值是A[2],在这次循环中temp=temp×A[0+1]=A[2]×A[1]=3×2=6



8.    B[i]=B[0]=B0]×temp=1×6=6,i–<0循环结束



所以B数组为{6,3,2}



#代码

-------

```cpp
#include <iostream>
#include <vector>

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
    vector<int> multiply(const vector<int>& A)
    {
        int n = A.size();
        vector<int> res(n);
        // C[i] = A[0] * A[1] * ... *A[i - 1]
        for(int i = 0, temp = 1; i < n; i++)
        {
            res[i] = temp;
            temp *= A[i];
        }

        // D[i] = A[i + 1] * A[i + 2] * ... *A[n - 1]
        for(int i = n - 1, temp = 1; i >= 0; i--)
        {
            res[i] *= temp;
            temp *= A[i];

        }
        return res;
    }
};

int __tmain( )
{
    debug <<"test" <<endl;
    return 0;
}
```