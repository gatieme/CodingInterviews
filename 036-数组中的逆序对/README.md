#链接
-------


>牛客OJ：[数组中的逆序对](http://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5?tpId=13&tqId=11188&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
>
>九度OJ：http://ac.jobdu.com/problem.php?pid=1348
>
>GitHub代码： [036-数组中的逆序对](https://github.com/gatieme/CodingInterviews/tree/master/036-数组中的逆序对)
>
>CSDN题解：[剑指Offer--036-数组中的逆序对](http://blog.csdn.net/gatieme/article/details/51326994)




| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 |
| ------ |:------:| --------:|:----------:|
|[036-数组中的逆序对](http://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5?tpId=13&tqId=11188&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | [1348-数组中的逆序对](http://ac.jobdu.com/problem.php?pid=1348) | [剑指Offer--036-数组中的逆序对](http://blog.csdn.net/gatieme/article/details/51326994) | [036-数组中的逆序对](https://github.com/gatieme/CodingInterviews/tree/master/036-数组中的逆序对) |



<br>**您也可以选择[回到目录-剑指Offer--题集目录索引](http://blog.csdn.net/gatieme/article/details/51916802)**





#题意
-------

**题目描述**

在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组，求出这个数组中的逆序对的总数

**样例输入**

>7 5 6 4

**样例输出**

>5




#暴力解法
-------

两个 for 循环枚举所有的数对，如果是逆序对，则 count++，最终返回 count 即可。时间复杂度$O(n^2)$

代码如下

```cpp
#include <iostream>
#include <vector>

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
    int InversePairs(vector<int> elem)
    {
        if(elem.size( ) == 0)
        {
            return 0;
        }

        int count = 0;
        for(unsigned int i = 0; i < elem.size( ); i++)  /// 循环每一个位置的数据
        {
            for(unsigned int j = i + 1; j < elem.size( ); j++)  /// 依次判断后面的数据与当前位置数据是否是逆序
            {
                if(elem[i] > elem[j])
                {
                    count++;
                }
            }
        }

        return count;
    }
};

int __tmain( )
{
    Solution solu;

    int arr[] = { 7, 5, 6, 4 };
    vector<int> vec(arr, arr + 4);

    cout <<solu.InversePairs(vec) <<endl;
    return 0;
}
```

#排序--计算交换次数
-------

>考虑一下，逆序是说a[i]>a[j]，i<j。那么在排序的过程中，会把a[i]和a[j]交换过来，这个交换的过程，每交换一次，就是一个逆序对的“正序”过程。

##冒泡排序
-------

```cpp
class Solution
{
public:
    int InversePairs(vector<int> elem)
    {
        if(elem.size( ) == 0)
        {
            return 0;
        }

        return BubbleSort(elem);
    }

    int BubbleSort(vector<int> elem)
    {
        bool flag = true;
        int count = 0;
        unsigned int length = elem.size( );

        for(unsigned int i = 0;
            i < length - 1 && flag == true;
            i++)  // 共计进行length-1趟循环
        {
            flag = false;           // 初始默认数据是无序的
            for(unsigned int j = 0;
                j < length - i - 1;
                j++)   // 每趟循环比较length-1-j次
            {
                if(elem[j] > elem[j + 1])    // 如果当前的元素与后一个元素不满足排序规则
                {
                    swap(elem[j], elem[j+1]);
                    flag = true;  // 仍然需要交换说明, 仍然无序
                    count++;
                }
            }
        }

        return count;
    }
};
```

##归并排序
-------

```cpp
class Solution
{
public:
    int InversePairs(vector<int> elem)
    {
        if(elem.size( ) == 0)
        {
            return 0;
        }

        vector<int> temp(elem.size( ));
        int count = InversePairsCore(elem, 0, elem.size( ) - 1, temp);

        return count;
    }

    int MergeElem(vector<int> &elem, int start, int mid, int end, vector<int> &temp)//数组的归并操作
    {
        // int leftLen=mid-start+1; //elem[start...mid]左半段长度
        // int rightLlen=end-mid;   //elem[mid+1...end]右半段长度

        int i = mid;
        int j = end;
        int k = 0;      //临时数组末尾坐标
        int count = 0;
        //设定两个指针ij分别指向两段有序数组的头元素，将小的那一个放入到临时数组中去。
        while(i >= start && j > mid)
        {
            if(elem[i] > elem[j])
            {
                temp[k++] = elem[i--];//从临时数组的最后一个位置开始排序
                count += j - mid;//因为elem[mid+1...j...end]是有序的，如果elem[i]>elem[j]，那么也大于elem[j]之前的元素，从a[mid+1...j]一共有j-(mid+1)+1=j-mid

            }
            else
            {
                temp[k++] = elem[j--];
            }
        }
        debug <<"count = " <<count <<endl;
        while(i >= start)//表示前半段数组中还有元素未放入临时数组
        {
            temp[k++] = elem[i--];
        }

        while(j>mid)
        {
            temp[k++] = elem[j--];
        }

        //将临时数组中的元素写回到原数组当中去。
        for(i = 0; i < k; i++)
        {
            elem[end-i] = temp[i];
        }

        copy(elem.begin(), elem.end(), ostream_iterator<int>(cout," "));
        return count;

    }

    int InversePairsCore(vector<int> &elem,int start,int end, vector<int> &temp)
    {
        int inversions = 0;
        if(start<end)
        {
            int mid = (start + end) / 2;
            inversions+=InversePairsCore(elem, start, mid, temp);//找左半段的逆序对数目
            inversions+=InversePairsCore(elem, mid + 1, end, temp);//找右半段的逆序对数目
            inversions+=MergeElem(elem,start, mid, end, temp);//在找完左右半段逆序对以后两段数组有序，然后找两段之间的逆序对。最小的逆序段只有一个元素。
        }
        return inversions;
    }
};
```
