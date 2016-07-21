#链接
------- 

>牛客OJ：[旋转数组的最小数字](http://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?tpId=13&tqId=11159&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-rankingg) 
>
>九度OJ：http://ac.jobdu.com/problem.php?pid=1386
>
>GitHub代码： [008-旋转数组的最小数字](https://github.com/gatieme/CodingInterviews/tree/master/008-%E6%97%8B%E8%BD%AC%E6%95%B0%E7%BB%84%E7%9A%84%E6%9C%80%E5%B0%8F%E6%95%B0%E5%AD%97)
>
>CSDN题解：[剑指Offer--008-旋转数组的最小数字](http://blog.csdn.net/gatieme/article/details/51115386)



| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 |
| ------------- |:-------------:| -----:|
|[旋转数组的最小数字](http://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?tpId=13&tqId=11159&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-rankingg)  | [1386-旋转数组的最小数字](http://ac.jobdu.com/problem.php?pid=1386)   | [剑指Offer--008-旋转数组的最小数字](http://blog.csdn.net/gatieme/article/details/51115386) | [008-旋转数组的最小数字](https://github.com/gatieme/CodingInterviews/tree/master/008-%E6%97%8B%E8%BD%AC%E6%95%B0%E7%BB%84%E7%9A%84%E6%9C%80%E5%B0%8F%E6%95%B0%E5%AD%97) |

<br>
**您也可以选择[回到目录-剑指Offer--题集目录索引](http://blog.csdn.net/gatieme/article/details/51916802)**

#题意

-------



题目描述


>把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个非递减序列的一个旋转，输出旋转数组的最小元素。

例如
>数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，
>
>该数组的最小值为1。

#一趟遍历寻找最小值-O(n)

最简单的思想就是一趟循环找到最小的那个
```cpp
#include <iostream>
#include <vector>
using namespace std;

//  调试开关
#define __tmain main


#ifdef __tmain
    #define dout cout
#else
    #define dout 0 && cout
#endif // __tmain


class Solution
{
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        if(rotateArray.size() == 0)
        {
            return 0;
        }

        int min = INT_MAX;
        for(int i = 0; i < rotateArray.size( ); i++)
        {
            if(rotateArray[i] < min)
            {
                min = rotateArray[i];
            }
        }
        return min;
    }


};


int __tmain( )
{

    int a[] = { 3, 4, 5, 1, 2 };
    vector<int> vec(a, a + 5);

    Solution solu;
    cout <<solu.minNumberInRotateArray(vec) <<endl;

    return 0;
}

```

#最大值后面那个就是最小值
-------

进一步我们发现，由于原序列基本有序，因此最大值后面那个就是最小值

```cpp
#include <iostream>
#include <vector>
using namespace std;

//  调试开关
#define __tmain main


#ifdef __tmain
    #define dout cout
#else
    #define dout 0 && cout
#endif // __tmain


class Solution
{
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        for(int i = 0; i < rotateArray.size( ); i++)
        {
            if(rotateArray[i] > rotateArray[i + 1])
            {
                return rotateArray[i + 1];
            }
        }
        return rotateArray[0];
    }
};


int __tmain( )
{
    dout <<"test" <<endl;
    return 0;
}

```

#分治--二分查找
-------

和二分查找法一样，用两个指针分别指向数组的第一个元素和最后一个元素。

我们注意到旋转之后的数组实际上可以划分为两个排序的子数组，而且前面的子数组的元素都大于或者等于后面子数组的元素。我们还可以注意到最小的元素刚好是这两个子数组的分界线。



我们试着**用二元查找法的思路在寻找这个最小的元素**。

首先我们用两个指针，分别指向数组的第一个元素和最后一个元素。按照题目旋转的规则，第一个元素应该是大于或者等于最后一个元素的（这其实不完全对，还有特例。后面再讨论特例）。



接着我们得到处在**数组中间的元素**



*    如果该中间元素位于前面的递增子数组，那么它应该大于或者等于第一个指针指向的元素。

此时数组中最小的元素应该位于该中间 元素的后面。我们可以把第一指针指向该中间元素，这样可以缩小寻找的范围。



*    同样，如果中间元素位于后面的递增子数组，那么它应该小于或者等于第二个指针指 向的元素。此时该数组中最小的元素应该位于该中间元素的前面。我们可以把第二个指针指向该中间元素，这样同样可以缩小寻找的范围。我们接着再用更新之后的 两个指针，去得到和比较新的中间元素，循环下去。



按照上述的思路，我们的第一个指针总是指向前面递增数组的元素，而第二个指针总是指向后面递增数组的元素。最后第一个指针将指向前面子数组的最后一个元素， 而第二个指针会指向后面子数组的第一个元素。也就是它们最终会指向两个相邻的元素，而第二个指针指向的刚好是最小的元素。这就是循环结束的条件。

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
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        if(rotateArray.size( ) == 0)
        {
            debug <<"非法输入" <<endl;
            return 0;
        }

        //  如果把排序数组前面0个元素搬到后面，也就是说其实没有旋转，
        //  那么第0个元素就是最小的元素
        //  因此我们将mid初始化为0
        int mid = 0;
        int low = 0, high = rotateArray.size( ) - 1;
        if(rotateArray[low] < rotateArray[high])
        {
            debug <<"数组未被旋转" <<endl;
        }
        while(rotateArray[low] >= rotateArray[high])
        {
            //  如果前一个元素与后一个元素差一位
            //  说明找到了最大最小的元素
            if(high - low == 1)
            {
                mid = high;
                debug <<"min = " <<low <<", high = " <<high <<endl;
                break;
            }

            mid = (low + high) / 2;
            debug <<rotateArray[low] <<", " <<rotateArray[mid] <<", " <<rotateArray[high] <<endl;

            //  如果该中间元素位于前面的递增子数组，那么它应该大于或者等于第一个指针指向的元素
            if(rotateArray[mid] >= rotateArray[low])
            {
                low = mid;          //  此时最小的元素位于中间元素的后面
            }
            // 如果中间元素位于后面的递增子数组，那么它应该小于或者等于第二个指针指 向的元素
            else if(rotateArray[mid] <= rotateArray[high])
            {
                high = mid;         //  此时最小的元素位于中间元素的前面
            }
        }

        return rotateArray[mid];
    }
};

int __tmain( )
{

    int a[] = { 1, 0, 1, 1, 1,};
    vector<int> vec(a, a + 5);

    Solution solu;
    cout <<solu.minNumberInRotateArray(vec) <<endl;

    return 0;
}

```



我们考虑下特殊情况，我们的循环判断是以`rotateArray[low] >= rotateArray[high]`为条件的，不满足这个的特殊情况有那些呢？



由于是把递增排序数组前面的若干个数据搬到后面去，因此第一个数字总是大于或者等于最后一个数字，但按照定义还有一个

特例：**开始时就rotateArray[low] < rotateArray[high]，那么循环不会执行**


*    如果数组旋转后仍然有序，即rotateArray[low] < rotateArray[high]


>如果把排序数组前面0个元素搬到后面，也就是说其实没有旋转，

>

>那么第0个元素就是最小的元素

>

>因此我们将mid初始化为0



现在可以了么，有没有特殊情况仍然未被处理的，

如果rotateArray[low] = rotateArray[high]



>测试用例:
>[1, 0, 1, 0, 1, 1]
>
>对应输出应该为:
>
>0
>
>你的输出为:
>
>1



此时

>rotateArray[low] rotateArray[mid] rotateArray[high]三者相等

>无法确定中间元素是属于前面还是后面的递增子数组

>只能顺序查找



因此我们的代码如下

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
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        if(rotateArray.size( ) == 0)
        {
            debug <<"非法输入" <<endl;
            return 0;
        }

        //  如果把排序数组前面0个元素搬到后面，也就是说其实没有旋转，
        //  那么第0个元素就是最小的元素
        //  因此我们将mid初始化为0
        int mid = 0;
        int low = 0, high = rotateArray.size( ) - 1;
        if(rotateArray[low] < rotateArray[high])
        {
            debug <<"数组未被旋转" <<endl;
        }
        while(rotateArray[low] >= rotateArray[high])
        {
            //  如果前一个元素与后一个元素差一位
            //  说明找到了最大最小的元素
            if(high - low == 1)
            {
                mid = high;
                debug <<"min = " <<low <<", high = " <<high <<endl;
                break;
            }

            mid = (low + high) / 2;
            debug <<rotateArray[low] <<", " <<rotateArray[mid] <<", " <<rotateArray[high] <<endl;

            // rotateArray[low] rotateArray[mid] rotateArray[high]三者相等
            // 无法确定中间元素是属于前面还是后面的递增子数组
            // 只能顺序查找
            if(rotateArray[low] == rotateArray[mid] && rotateArray[mid] == rotateArray[high])
            {
                debug <<"low == mid == high, so we should order it" <<endl;
                return MinOrder(rotateArray, low, high);
            }
            //  如果该中间元素位于前面的递增子数组，那么它应该大于或者等于第一个指针指向的元素
            if(rotateArray[mid] >= rotateArray[low])
            {
                low = mid;          //  此时最小的元素位于中间元素的后面
            }
            // 如果中间元素位于后面的递增子数组，那么它应该小于或者等于第二个指针指 向的元素
            else if(rotateArray[mid] <= rotateArray[high])
            {
                high = mid;         //  此时最小的元素位于中间元素的前面
            }
        }

        return rotateArray[mid];
    }

private:
    // 顺序寻找最小值
    int MinOrder(vector<int> &num, int low, int high)
    {
        int result = num[low];
        for(int i = low + 1; i < high; i++)
        {
            if(num[i] < result)
            {
                result = num[i];
            }//if
        }//for
        return result;
    }

};

int __tmain( )
{

    int a[] = { 1, 0, 1, 1, 1,};
    vector<int> vec(a, a + 5);

    Solution solu;
    cout <<solu.minNumberInRotateArray(vec) <<endl;

    return 0;
}

```





