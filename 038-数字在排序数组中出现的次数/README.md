#链接
-------
>牛客OJ：[数字在排序数组中出现的次数](http://www.nowcoder.com/practice/70610bf967994b22bb1c26f9ae901fa2?tpId=13&tqId=11190&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
>
>九度OJ：http://ac.jobdu.com/problem.php?pid=1349
>
>GitHub代码： [038-数字在排序数组中出现的次数](https://github.com/gatieme/CodingInterviews/tree/master/038-数字在排序数组中出现的次数)
>
>CSDN题解：[剑指Offer--038-数字在排序数组中出现的次数](http://blog.csdn.net/gatieme/article/details/51335323)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 |
| ------------- |:-------------:| -----:|
|[038-数字在排序数组中出现的次数](http://www.nowcoder.com/practice/70610bf967994b22bb1c26f9ae901fa2?tpId=13&tqId=11190&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | [1505-数字在排序数组中出现的次数](http://ac.jobdu.com/problem.php?pid=1349) | [剑指Offer--038-数字在排序数组中出现的次数](http://blog.csdn.net/gatieme/article/details/51335323) | [038-数字在排序数组中出现的次数](https://github.com/gatieme/CodingInterviews/tree/master/038-数字在排序数组中出现的次数) |


<br>**您也可以选择[回到目录-剑指Offer--题集目录索引](http://blog.csdn.net/gatieme/article/details/51916802)**




#题意
-------

**题目描述**

>统计一个数字在排序数组中出现的次数。


#暴力方法
-------

由于数组是有序的，因此我么通过一次遍历，对要查找的元素直接计数就可以了
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
    int GetNumberOfK(vector<int> data,int k)
    {
        if(data.size( ) == 0)
        {
            return 0;
        }

        int count = 0;
        for(unsigned int i = 0;
            i < data.size( ) && data[i] <= k;
            i++)
        {
            if(data[i] == k)
            {
                count++;
            }
        }

        return count;
    }
};

int __tmain( )
{
    Solution solu;

    int arr[] = { 1, 2, 3, 3, 3, 3, 4, 5 };
    vector<int> vec(arr, arr + 8);
    cout <<solu.GetNumberOfK(vec, 3) <<endl;

    return 0;
}
```

当然也可以使用STL中特定容易的计数功能

```cpp
class Solution
{
public:
    int GetNumberOfK(vector<int> data ,int k)
    {
        multiset<int> mData;
        for(int i = 0; i < data.size( ); i++)
        {
            mData.insert(data[i]);
        }

        return mData.count(k);
    }
};
```

#分治--二分查找
-------

##二分查找（递归和非递归）
-------

我们通过二分查找到指定的元素K后，然后再分别向前和向后查找总的个数

```cpp
/* 先用二分查找找出某个k出现的位置，然后再分别向前和向后查找总的个数*/
class Solution
{
public:
    int GetNumberOfK(vector<int> data,int key)
    {
        if(data.size( ) == 0)
        {
            return 0;
        }

        //  用二分查找查找到Key的位置
        int index = BinarySearch(data, 0, data.size( ) - 1, key);
        //int index = BinarySearch(data, key);
        if(index == -1)
        {
            return 0;
        }

        int count = 1;
        // 查找前面部分Key的个数
        for(int j = index - 1;
            j >= 0 && data[j] == key;
            j--)
        {
            debug <<"pos = " <<j <<", data = " <<data[j] <<endl;
            count++;
        }

        //  查找后面部分Key的个数
        for(int j = index + 1;
            j < data.size( ) && data[j] == key;
            j++)
        {
            count++;
        }

        return count;
    }

    int BinarySearch(vector<int> &data, int begin, int end ,int key)
    {
        if(begin > end)
        {
            return -1;
        }

        int mid = (begin + end) / 2;
        debug <<"mid = " <<mid <<", data = " <<data[mid] <<endl;
        if(data[mid] == key)
        {
            return mid;
        }
        else if(data[mid] > key)
        {
            return BinarySearch(data, begin, mid - 1, key);
        }
        else if(data[mid] < key)
        {
            return BinarySearch(data,mid + 1, end, key);
        }
        return -1;
    }


    int BinarySearch(vector<int> array, int key)
    {
        int low = 0, high = array.size( ) - 1;

        int mid;

        while (low <= high)
        {
            mid = (low + high) / 2;

            if(key == array[mid])
            {
                return mid;
            }

            if(key < array[mid])
            {
                high = mid - 1;
            }

            if(key > array[mid])
            {
                low = mid + 1;
            }
        }

        return -1;
    }
};
```

##改进的二分查找，返回第一个和最后一个的位置
-------

**递归版**

```cpp
class Solution
{
    /*二分查找 找到第一个K 和 最后一个K 二者位置相减*/
public:
    int GetNumberOfK(vector<int> data ,int k)
    {
        if(data.empty())
        {
            return 0;
        }

        int number = 0;
        int first = GetFirstIndex(data, k, 0, data.size( ) - 1);
        int last  = GetLastIndex(data, k, 0, data.size( ) - 1);

        if(first > -1 && last > -1)
        {
            number = last - first +1;
            return number;
        }
    }

    // 查找第一个的位置
    int GetFirstIndex(vector<int> &data, int low, int high, int k)
    {
        if(low > high)
        {
            return -1;
        }

        int mid = (low + high) / 2;

        if(data[mid] == k)
        {
            if((mid > 0 && data[mid-1] != k) || mid == 0)
            {
                return mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        else if(data[mid] > k)
        {
            high = mid - 1;
        }
        else if(data[mid] < k)
        {
            low = mid + 1;
        }

        return GetFirstIndex(data, k, low, high);
    }

    int GetLastIndex(vector<int> &data, int low, int high, int k)
    {
        if(low > high)
        {
            return -1;
        }

        int mid = (low + high) / 2;
        if(data[mid]==k)
        {
            if((mid>0 && data[mid+1] !=k) || mid == high)
            {
                return mid;
            }
            else
            {
                low = mid +1;
            }
        }
        else
        {
            if(mid>k)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }

        return GetLastIndex(data,k,low,high);
    }
};
```


**非递归版**
```cpp
class Solution
{
public:
    int GetNumberOfK(std::vector<char> array , int k)
    {
        if (array == null || array.size( ) == 0)
        {
            return 0;
        }

        int low = 0, high = array.size( ) - 1,
        int first = 0, last = 0;

        if (low == high)
        {
            if (array[0] != k)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }

        int number = 0;
        int first = GetFirstIndex(data, k, 0, data.size( ) - 1);
        int last  = GetLastIndex(data, k, 0, data.size( ) - 1);

        if(first > -1 && last > -1)
        {
            number = last - first +1;
            return number;
        }
        else
        {
            return 0;
        }
    }

    int GetFirstIndex(vector<int> &data, int low, int high, int k)
    {
        int mid
        while (low < high)
        {
            int mid = (low + high) / 2;
            if (array[mid] < k)
            {
                if (array[mid + 1] == k)
                {
                    first = mid;
                    break;
                }
                low = mid + 1;
            }
            else
            {
                high = mid;
                first = -1;
            }
        }

        if (array[first + 1] != k)   // can't find it.
        {
            return 0;
        }
    }

    int GetLastIndex(vector<int> &data, int low, int high, int k)
    {
        int last, mid;

        while (low < high)
        {
            mid = (low + high) / 2;
            if (array[mid] <= k)
            {
                last = mid;

                if (array[mid + 1] > k)
                {
                    break;
                }
                else if (mid + 1 >= high)
                {
                    last++;
                    break;
                }
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
    }
};
```

##STL的

```cpp
　ForwardIter lower_bound(ForwardIter first, ForwardIter last,const _Tp& val)
```

算法返回一个非递减序列[first, last)中的第一个大于等于值val的位置。

```cpp
ForwardIter upper_bound(ForwardIter first, ForwardIter last, const _Tp& val)

```
算法返回一个非递减序列[first, last)中第一个大于val的位置。


```cpp
class Solution
{
public:
    int GetNumberOfK(vector<int> data ,int k)
    {
        int upper = upper_bound(data.begin(),data.end(),k)；
        int low = lower_bound(data.begin(),data.end(),k);
        return upper - low;
    }
};

```
