#1    链接
-------

>牛客OJ：[数据流之中的中位数](http://www.nowcoder.com/practice/9be0172896bd43948f8a32fb954e1be1?tpId=13&tqId=11216&rp=4)
> 
>九度OJ：未收录
>
>GitHub代码： [064-数据流之中的中位数](https://github.com/gatieme/CodingInterviews/tree/master/064-数据流之中的中位数)
>
>CSDN题解：[剑指Offer--064-数据流之中的中位数](http://blog.csdn.net/gatieme/article/details/51908274)

| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 | 
| ------------- |:-------------:| -----:| -----:|
|[064-数据流之中的中位数](http://www.nowcoder.com/practice/9be0172896bd43948f8a32fb954e1be1?tpId=13&tqId=11216&rp=4) | 未收录 | [剑指Offer--064-数据流之中的中位数](http://blog.csdn.net/gatieme/article/details/51908274) | [064-数据流之中的中位数](https://github.com/gatieme/CodingInterviews/tree/master/064-数据流之中的中位数) |

#2    题意
-------



**题目描述**



>如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

 

#3  分析
-------



| 数据结构 | 插入的时间效率 | 得到的中位数的时间效率 |
|:-------:||:-------:||:-------:|
| 没有排序的数组 | O(1) | O(n) |
| 排序的数组 | O(n) | O(1) |
| 排序的链表 | O(n) |  O(1) |
| 二叉搜索树 | 平均O(logn), 最差O(n) |  平均O(logn), 最差O(n) | 
| AVL树 | O(logn) | O(1) |
| 最大堆和最小堆 | O(logn) | O(1) |





#4  堆排序策略
-------



对于数据流，对应的就是在线算法了，一道很经典的题目就是在1亿个数中找到最大的前100个数，这是一道堆应用题，找最大的前100个数，那么我们就创建一个大小为100的最小化堆，每来一个元素就与堆顶元素比较，因为堆顶元素是目前前100大数中的最小数，前来的元素如果比该元素大，那么就把原来的堆顶替换掉。

那么对于这一道题呢？如果单纯的把所有元素放到一个数组里，每次查找中位数最快也要O(n)，综合下来是O(n^2)的复杂度。我们可以利用上面例子中的想法，用一个最大堆来维护当前前n/2小的元素，那么每次找中位数只到取出堆顶就可以了。但是，有一个问题，数据要动态增长，有可能之前被替换掉的元素随着元素的增加又跑回来了，所以我们不能单纯得向上题一样把元素丢掉，我们可以再用一个最小化堆来存前n/2大的元素。



```c
#include <iostream>
#include <vector>
#include <algorithm>
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
protected:
    vector<int>     m_min; //数组中的后一半元素组成一个最小化堆
    vector<int>     m_max; //数组中的前一半元素组成一个最大化堆

public:
    /*  将元素插入的堆中，　
     *  为了保证数据平均的分配到两个堆中, 两个堆的数据数目之差不能超过１
     *  插入的元素会两个堆元素的平衡, 因此两个堆都必须调整
     *
     *  比如将元素插在后半段(最小堆)中,
     *  则最小堆调整后的堆顶(最小值)需要弹出并压入到前半段中才能保证平衡
     *　也就是说,　在最小堆中插入元素, 最后完成调整后将导致最大堆中元素+1
     *
     *  因此我们可以假定, 0 <= m_min.size( ) - m_max.size( ) <= 1
     *  那么
     *
     *  插入前如果整个数组的元素个数为偶数, 说明两个堆中元素个数相等
     *  则最终元素应该插入m_min中,即先把元素插入到m_max中在调整到m_min中
     *
     *  插入前如果整个数组的元素个数为奇数, 说明m_max元素多了1个
     *  则最终元素应该插入m_max中,
     *  即先把元素插入到m_min中在调整到m_max中
     *  */
    void Insert(int num)
    {
        if(((m_min.size( ) + m_max.size( )) & 1) == 0)
        {
            /*  偶数数据的情况下
             *  直接将新的数据插入到数组的后半段
             *  即在最小堆中插入元素
             *
             *  此时最小堆中多出一个元素,
             *  即最小元素, 将其弹出后, 压入前半段(即最大堆中)
             *  */
            if(m_max.size( ) > 0 && num < m_max[0])
            {
                m_max.push_back(num);
                push_heap(m_max.begin( ), m_max.end( ), less<int>( ));

                num = m_max[0];
                pop_heap(m_max.begin(), m_max.end(), less<int>());
                m_max.pop_back();
            }
            m_min.push_back(num); //把前一半找到的最大值放到后一半中
            push_heap(m_min.begin( ), m_min.end( ), greater<int>( ));
            debug <<"left = " <<m_max.size( ) <<", " <<m_min.size( ) <<endl;
        }
        else
        {
            /*  否则数组中元素是奇数
             *  将
             *
             * */
            if(m_min.size( ) > 0 && num > m_min[0])    //  奇数数据的情况下，则在最大堆中插入元素
            {
                m_min.push_back(num);
                push_heap(m_min.begin(), m_min.end(), greater<int>());
                num=m_min[0];
                pop_heap(m_min.begin(), m_min.end(), greater<int>());
                m_min.pop_back();
            }
            m_max.push_back(num); //把后一半找到的最大值放到前一半中
            push_heap(m_max.begin(), m_max.end(), less<int>());
        }
    }

    /*  由于假定, 0 <= m_min.size( ) - m_max.size( ) <= 1
     *  因此
     *  当总元素个数为偶数时, 中位数即(m_max[0] + m_min[0]) / 2
     *  当总元素个数为奇数时, 中位数即m_min[0];  */
    double GetMedian()
    {
        int size = m_min.size( ) + m_max.size( );
        if(size==0) return -1;
        double median = 0;
        if((size & 1) != 0)
        {
            median = (double) m_min[0];
        }
        else
        {
            median = (double) (m_max[0] + m_min[0]) / 2;
        }
        return median;
    }
};

int __tmain( )
{
    Solution s;
    int array[] = {5, 2, 3, 4, 1, 6, 7, 0, 8};
    vector<int> vec(array, array + 9);

    for (int i = 0; i < vec.size( ); i++)
    {
        s.Insert(vec[i]);
        cout << s.GetMedian( ) << endl;
    }
    return 0;
}
```



#5  哈希set-multiset策略
-------

类似的策略, 我们可以采用multiset来实现, set和multiset会根据特定的排序准则，自动将元素进行排序。不同的是后者允许元素重复而前者不允许

```c
class Solution
{
protected :
    multiset<int>   left;       /*  左半部分  */
    multiset<int>   right;      /*  右半部分  */

public    :

    void Insert(int n)
    {
        int tmp = n;
        if(((left.size( ) + right.size( )) & 1) == 0)
        {
            if (right.empty( ) != true && n > *right.begin())
            {
                right.insert(n);
                tmp = *right.begin( );
                right.erase(right.find(tmp));
            }
            left.insert(tmp);
        }
        else
        {
            if (left.empty() != true && n < *left.rbegin())
            {
                left.insert(n);
                tmp = *left.rbegin();
                left.erase(left.find(tmp));
            }
            right.insert(tmp);
        }

    }

    double GetMedian( )
    {
#ifdef __tmain
        cout <<"left[" <<left.size( ) <<"] : ";
        copy(left.begin( ), left.end( ), ostream_iterator<int>(cout," "));
        cout <<"right[" <<right.size( ) <<"] : ";
        copy(right.begin( ), right.end( ), ostream_iterator<int>(cout," "));
        cout <<endl;
#endif

        if(((left.size( ) + right.size( )) & 1) == 0)
        {
            debug <<*left.rbegin( ) <<", " <<*right.begin( ) <<endl;
            return (double)(*left.rbegin( ) + *right.begin( )) / 2.0;
        }
        else
        {
            debug <<(double)*left.rbegin( ) <<endl;
            return (double)*left.rbegin( );
        }
    }
};
```
﻿