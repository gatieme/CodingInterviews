#链接
------- 

>牛客OJ：[调整数组顺序使奇数位于偶数前面](http://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?tpId=13&tqId=11166&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
> 
>九度OJ：http://ac.jobdu.com/problem.php?pid=1516
> 
>GitHub代码： [014-调整数组顺序使奇数位于偶数前面](https://github.com/gatieme/CodingInterviews/tree/master/014-调整数组顺序使奇数位于偶数前面)
>
>CSDN题解：[剑指Offer--014-调整数组顺序使奇数位于偶数前面](http://blog.csdn.net/gatieme/article/details/51133277)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 | 
| ------------- |:-------------:| -----:| 
|[调整数组顺序使奇数位于偶数前面](http://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?tpId=13&tqId=11166&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | [1516-调整数组顺序使奇数位于偶数前面](http://ac.jobdu.com/problem.php?pid=1516) | [剑指Offer--014-调整数组顺序使奇数位于偶数前面](http://blog.csdn.net/gatieme/article/details/51133277) | [014-调整数组顺序使奇数位于偶数前面](https://github.com/gatieme/CodingInterviews/tree/master/014-调整数组顺序使奇数位于偶数前面) |


<br>
**您也可以选择[回到目录-剑指Offer--题集目录索引](http://blog.csdn.net/gatieme/article/details/51916802)**




#题意
-------

**题目描述**

>输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

**样例输入**

>5
>1 2 3 4 5

**样例输出**

>1 3 5 2 4


>下面我们考虑**算法复杂度**的同时还会考虑其**稳定性**，（排序的稳定型则是指相同元素在数组中的相对位置是否发生变化），这里的稳定性我们理解为，顺序交换后，各个奇数（或者偶数）在数组中的相对位置是否发生变化

#暴力解法以及冒泡解法
-------
最简单的思路就是从头到尾扫描一遍数组，每遇见一个偶数时，就拿出这个数字，并把位于这个数字之后的所有数字往前挪动一位,然后把当前这个偶数放到最后。

这样每次遇到一个偶数就要挪动$O(n)$个数字，因此总的时间复杂度是$O(n^2)$

但是这种方法不仅暴力而且还需要复杂的挪动工作，因此我们对比一下冒泡排序，每次循环前偶后奇就交换

同时我们设立一个标识，来标识数组是否已经符合要求

当再次循环时，发现没有要交换的数据，说明数组已经符合要求
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
    void reOrderArray(vector<int> &array)
    {
        if(array.size( ) <= 1)
        {
            return ;
        }
        bool isSwap = false;
        for (int i = 0; i < array.size( ); i++)
        {
            isSwap = false;
            for (int j = array.size() - 1; j > i; j--)
            {
                if (array[j] % 2 == 1 && array[j - 1]%2 == 0) //前偶后奇交换
                {
                    swap(array[j], array[j-1]);
                    isSwap = true;
                }
            }
            if(isSwap == false)
            {
                break;
            }
        }


    }
};


int __tmain( )
{
    int array[] = { 1, 2, 3, 4, 5, 6, 7};
    vector<int> vec(array, array + 7);
    for(int i = 0; i < 7; i++)
    {
        cout <<vec[i] <<" ";
    }
    cout <<endl;
    Solution solu;
    solu.reOrderArray(vec);

    for(int i = 0; i < 7; i++)
    {
        cout <<vec[i] <<" ";
    }
    cout <<endl;
    return 0;
}

```
由于冒泡法比较相邻两个元素，因此奇数或者偶数的相对顺序不变，是稳定的

#辅助数组完成
-------
我们也可以利用一个辅助的数组空间来实现

*    在原来的数组中遇到偶数就放进新数组中，然后将该偶数从原来数组中删除，当整个遍历结束后，原来数组中只剩下奇数，新的数组总只剩下偶数，最后我们将新的数组追加在原来数组的末尾即可

```cpp
class Solution
{
public:
    void reOrderArray(vector<int> &array)
    {
        if(array.size( ) <= 1)
        {
            return ;
        }

        vector<int> array_temp;
        vector<int>::iterator ib1, ie1;
        ib1 = array.begin();


        for (; ib1 != array.end();)
        {            //遇见偶数，就保存到新数组，同时从原数组中删除
            if (*ib1 % 2 == 0)
            {
                array_temp.push_back(*ib1);
                ib1 = array.erase(ib1);
            }
            else{
                ib1++;
            }

        }
        vector<int>::iterator ib2, ie2;
        ib2 = array_temp.begin();
        ie2 = array_temp.end();

        for (; ib2 != ie2; ib2++)             //将新数组的数添加到老数组
        {
            array.push_back(*ib2);
        }
    }
};
```
这种算法也是稳定的。

#高效但是只完成基本功能的解法
-------

由于题目中只要求记奇数在偶数之前，那么我们在扫描这个数组的时候，如果发现一个偶数出现在奇数之前就交换他们的位置，这样一趟后就满足要求了。

因此我们
*    维护两个索引或者指针，一个指向数组的第一个元素，并向后移动，一个指向数组的最后一个元素，并向前移动。

*    如果第一个指针指向的元素是偶数，而第二个指针指向的元素是奇数，说明偶数在奇数前面，那么就交换这两个数。

*    直到两个指针相遇为止

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
    void reOrderArray(vector<int> &array)
    {
        if(array.size( ) <= 1)
        {
            return ;
        }
        vector<int>::iterator left = array.begin( );
        vector<int>::iterator right = array.end( ) - 1;

        // 三种顺序容器中只有deque和vector容器的迭代器支持大小的比较和算术运算。

        while(left < right)
        //while(left != right)
        {
            //system("PAUSE");

            //  left向后移动指向第一个偶数
            while(left < right && (*left & 0x01) == 1)
            {
                left++;
            }

            // right向前移动指向第一个奇数
            while(left < right && (*right &0x01) == 0)
            {
                right--;
            }
            debug <<"left = " <<*left <<", right = " <<*right <<endl;

            if(left < right)
            {
                swap(*left, *right);
            }
        }

    }
};


int __tmain( )
{
    int array[] = { 1, 2, 3, 4, 5, 6, 7};
    vector<int> vec(array, array + 7);
    for(int i = 0; i < 7; i++)
    {
        cout <<vec[i] <<" ";
    }
    cout <<endl;
    Solution solu;
    solu.reOrderArray(vec);

    for(int i = 0; i < 7; i++)
    {
        cout <<vec[i] <<" ";
    }
    cout <<endl;
    return 0;
}

```

很明显，这种算法不能保证相同类型数据的相对位置不变，因此不稳定

比如要求
测试用例:

>[1,2,3,4,5,6,7]

对应的稳定输出

>[1,3,5,7,2,4,6]

我们算法的输出

>[1,7,3,5,4,6,2]


