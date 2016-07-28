#链接
-------
>牛客OJ：[最小的K个数](http://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?tpId=13&tqId=11182&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
>
>九度OJ：http://ac.jobdu.com/problem.php?pid=1371
>
>GitHub代码： [030-最小的K个数](https://github.com/gatieme/CodingInterviews/tree/master/030-最小的K个数)
>
>CSDN题解：[剑指Offer--030-最小的K个数](http://blog.csdn.net/gatieme/article/details/51277505)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 |
| ------ |:------:| --------:|:----------:|
|[最小的K个数](http://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?tpId=13&tqId=11182&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | [1371-最小的K个数](http://ac.jobdu.com/problem.php?pid=1371) | [剑指Offer--030-最小的K个数](http://blog.csdn.net/gatieme/article/details/51277505) | [030-最小的K个数](https://github.com/gatieme/CodingInterviews/tree/master/030-最小的K个数) |


<br>**您也可以选择[回到目录-剑指Offer--题集目录索引](http://blog.csdn.net/gatieme/article/details/51916802)**



#题意
-------

**题目描述**

>输入n个整数，找出其中最小的K个数。


例如输入4,5,1,6,2,7,3,8这8个数字，
则最小的4个数字是1,2,3,4,。

#分析
-------

##方法一--排序
-------

*    要求一个序列中最小的K个数，按照惯有的思维方式，很简单，先对这个序列从小到大排序，然后输出前面的最小的K个数即可；

*    至于选取什么样的排序方法，第一时间应该想到的是快速排序，我们知道，快速排序平均时间复杂度为O(nlogn)，然后再遍历序列中前K个元素输出，即可，总的时间复杂度为O(nlogn + k) = O(nlogn)；——方法一

##方法二--选择或者交换排序
-------

*    再进一步想想，题目并没有要求要查找的k个数，甚至是后面的n-k个数是有序的，既然这样，咱们又何必对所有的n个数都进行排序呢？
    这个时候，想到了选择或交换排序，即遍历n个数，先把最先遍历到的K个数存入大小为k的数组之中，对这k个数，利用选择或交换排序，找到k个数中的最大数Kmax(Kmax为这K个元素的数组中最大的元素)，用时间为O(k)（你应该知道，插入或选择排序查找操作需要O(k)的时间），后再继续遍历后n-k个数，x与Kmax比较：如果x< Kmax，则x代替Kmax，并再次重新找出K个元素的数组中的最大元素Kmax'；如果x>Kmax，则不更新数组。这样每次更新和不更新数组所用的时间为O(k)或O(0)，整趟下来，总的时间复杂度平均下来为：n*O(k) = O(n*k)；——方法二

##方法三--最小堆
-------

当然，更好的办法是维护k个元素的最大堆，原理与上述第2个方案一致，即用容量为K的最大堆存储最先遍历的K个数，并假设它们即是最小的K个数，建堆需要O(k)后，有k1）。继续遍历数列，每次遍历一个元素x，与堆顶元素比较，x），否则不更新堆。这样下来，总费时O(k+(n-k)*logk) = O(nlogk)。此方法得益于在堆中，查找等各项操作时间复杂度均为logk（不然，就如上述思路2所述：直接用数组也可以找出前k个小的元素，用时O(n*k)）；

##方法四--快速排序的分治划分（中位数作为枢轴）
-------
按编程之美第141页上解法二的所述，类似快速排序的划分方法，N个数存储在数组S中，再从数组中随机选取一个数X（随机选取枢纽元，可做到线性期望时间O(N)的复杂度），把数组划分为Sa和Sb两部分，Sa<= X <=Sb，如果要查找的K个小的元素小于Sa中的元素个数，则返回Sa中较小的K个元素，否则返回Sa中K个小的元素 + Sb中小的K-|Sa|个元素。像上述过程一样，这个运用类似快速排序的partition的快速选择Select算法寻找最小的K个元素，在最坏的情况下亦能做到O(N)的复杂度。

不过值得一提的是，这个快速选择Select算法是选择数组中“中位数的中位数”作为枢纽元，而非随机选择枢纽元；

##方法五--快速排序的分治划分（随机枢轴）
-------

Randomized-Select，每次都是随机选择数列中的一个元素作为主元，在O(n)的时间内找到第K小的元素，然后遍历输出前面的K个小的元素。如果能的话，那么总的时间复杂度为线性期望时间：O(n+k) = O(n)（当n比较小时）；

##方法六--线性排序
-------

线性时间的排序，即计数排序，时间复杂度虽能达到O(n)，但是，限制条件太多了，不常用；

##方法七--最小堆与优先队列
-------

”可以用最小堆初始化数组，然后取这个优先队列前k个值。复杂度为O(n)+k*O(logn)“。意思是针对整个数组序列建立最小堆，建堆所用时间为O(n)，然后取堆中的前k个数，即总的时间复杂度为：O(n+k*logn)。

##方法八--提取最小堆的元素
-------
与上述思路7类似，不同的是在对元素数组原地建立最小堆O(n)后，然后提取K次，但是每次提取时，换到顶部的元素只需要下移顶多K次就足够了，下移次数逐次减少（而上述思路7每次提取都需要logn，所有提取K次，思路7需要K*logn，而本思路8只需要K^2）；

#代码
-------

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
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
    vector<int> m_res;
public:

    vector<int> GetLeastNumbers_Solution(vector<int> numbers, int k)
    {
        m_res.clear( );

        if(numbers.size( ) == 0 || numbers.size() < k)
        {
            return m_res;
        }
//        m_res.clear( );
//        LeastKNumbers_BySort(numbers, k);
//
//        m_res.clear( );
//        LeastKNumbers_BySelectSort(numbers, k);
//
//        m_res.clear( );
//        LeastKNumbers_ByBubbleSort(numbers, k);


        LeastKNumbers_ByCountSort(numbers, k);


        return m_res;
    }

    ///  排序后输出前K个数字
    vector<int> LeastKNumbers_BySort(vector<int> numbers, int k)
    {
        debug <<endl <<"line " <<__LINE__ <<"in function : "<<__func__ <<endl <<endl;

        //vector<int> res;

        sort(numbers.begin( ), numbers.end( ));
        for(int i = 0; i < k; i++)
        {
            debug <<numbers[i] <<" ";
            m_res.push_back(numbers[i]);
        }
        debug <<endl;

        return m_res;
    }

    ///  采用选择排序法, K趟找出前K个数字
    ///  由于选择排序每趟结束后前i个数字都有序，因此K趟即可找出前K小的数字
    vector<int> LeastKNumbers_BySelectSort(vector<int> numbers, int k)
    {
        debug <<endl <<"line " <<__LINE__ <<" in function : "<<__func__ <<endl <<endl;

        int i, j, index;
        int length = numbers.size( ) -1;
        for(i = 0; i < k/*length*/; i++)             // 循环每趟排序
        {
            index = i;
            for(j = i + 1; j < length; j++)
            {
                if(numbers[j] < numbers[index])
                {
                    index  = j;                 // 找到当前极值元素的下标
                }
            }
            if(index != i)
            {
                swap(numbers[i], numbers[index]);     // 将极值保存到应该填入的位置
            }
            m_res.push_back(numbers[i]);

#ifdef __tmain

            debug <<"pos = " <<index <<", num = " <<numbers[i] <<endl;
            debug <<"when " <<i <<" select sort, the least " <<i <<" numbers is sorted" <<endl;

            for(int pos = 0; pos <= i; pos++)
            {
                debug <<numbers[pos] <<" ";
            }
            debug <<endl;

#endif  //  __tmain

        }

        return m_res;
    }

    ///  采用冒泡排序法, K趟找出前K个数字
    vector<int> LeastKNumbers_ByBubbleSort(vector<int> numbers, int k)
    {
        debug <<endl <<"line " <<__LINE__ <<" in function : "<<__func__ <<endl <<endl;

        int j/*控制每趟循环*/, i/*控制相邻数据的比较循环*/;
        // 排序过程
        int length = numbers.size( );
        for(i = 0; i < k/*length - 1*/; i++)        // 共计进行length-1趟循环
        {
            for(j = length - i - 1; j > 0; j--)   // 每趟循环比较length-1-j次
            {
                if(numbers[j - 1] > numbers[j])    // 如果当前的元素与后一个元素不满足排序规则
                {
                    swap(numbers[j - 1], numbers[j]);
                }

            }
            m_res.push_back(numbers[i]);

#ifdef __tmain
            debug <<"pos = " <<i <<", num = " <<numbers[i] <<endl;
            debug <<"when " <<i <<" bubble sort, the least " <<i <<" numbers is sorted" <<endl;

            for(int pos = 0; pos <= i; pos++)
            {
                debug <<numbers[pos] <<" ";
            }
            debug <<endl;

#endif  //  __tmain
        }

        return m_res;
    }


    ///  采用计数排序
    vector<int> LeastKNumbers_ByCountSort(vector<int> numbers, int k)
    {
        int i, count;
        int num[1000];
        memset(num, '\0', 1000);

        for(i = 0; i < numbers.size( ); i++)
        {
            num[numbers[i]]++;
            debug <<numbers[i] <<endl;
        }
        for(i = 0, count = 0; i < 1000 && count < k; i++)
        {
            if(num[i] != 0)
            {
                count++;
                debug <<i <<" ";
                m_res.push_back(i);
            }
        }
        debug <<endl;

        return m_res;
    }

    vector<int> GetLeastNumbers_ByFindKth(vector<int> numbers, int k)
    {
        int kth;
        vector<int> res;

        for(int i = 0; i < k; i++)
        {
            kth = FindKth(numbers, 0, numbers.size( ) - 1, i);

            debug <<i <<" th is " <<kth <<endl;
            res.push_back(kth);
        }

        return res;
    }


    /**
     * [Partition 快速排序的划分函数, 返回枢轴(left下标元素)在排序的数组中应该所处的位置,
      即下标为left的元素是第几大的元素
     * @Author    gatieme
     * @DateTime  2016-04-26T11:11:34+0800
     * @param     numbers                  [待划分的数组]
     * @param     left                     [待划分数据的起始位置]
     * @param     right                    [待划分数据的结束位置]
     * @return                             [返回枢轴在排序后数组中应该在的位置]
     */
    int Partition(vector<int> &numbers, int left, int right)
    {
        int i = left, j = right;

        ///  我们选择第一个元素作为基准
        ///  这个也可以随机选择
        int pivotIndex = left, pivotNum = numbers[pivotIndex];

        ddebug <<"pivotNum = " <<pivotNum <<endl;
        while(i < j)
        {
            while(i < j && numbers[j] >= pivotNum)
            {
                ddebug <<"[" <<i <<", " <<j <<"] " <<numbers[j] <<" >= " <<pivotNum <<endl;
                j--;
            }
            ddebug <<"now we find i = " <<i <<", posJ = " <<j <<", num = " <<numbers[j] <<" < " <<pivotNum <<endl;;
            numbers[i] = numbers[j];        // 将找到的那个比枢轴小的数，放在枢轴左侧I的位置
            //swap(numbers[i], numbers[j]); // 也可以使用交换, 但是没有必要, 因为枢轴的位置并没有最后确定

            while(i < j && numbers[i] <= pivotNum)
            {
                ddebug <<"[" <<i <<", " <<j <<"] " <<numbers[i] <<" <= " <<pivotNum <<endl;
                i++;
            }

            ddebug <<"now we find j = " <<i <<", posI = " <<j <<", num = " <<numbers[i] <<" > " <<pivotNum <<endl;;
            numbers[j] = numbers[i];        // 将找到的那个比枢轴大的数，放在枢轴右侧J的位置
            //swap(numbers[i], numbers[j]); // 也可以使用交换, 但是没有必要, 因为枢轴的位置并没有最后确定
        }

        numbers[i] = pivotNum;              //  最后的位置 i == j 就是枢轴的位置

#ifdef __tmain

        ddebug <<pivotNum <<" 's post is" <<i <<endl;
        for(int pos = left; pos <= right; pos++)
        {
            ddebug <<numbers[pos] <<" ";
        }
        ddebug <<endl;
        //system("PAUSE");

#endif // __tmain

        return i;
    }

    /**
     * [FindKth 查找数组中第K大的元素]
     * @Author    gatieme
     * @DateTime  2016-04-26T11:18:00+0800
     * @param     numbers                  [待查找元素所在的数组]
     * @param     left                     [数据起始元素的位置]
     * @param     right                    [数据终止元素的位置]
     * @param     k                        [第K大的元素]
     * @return                             [数组中第K大的元素的值]
     */
    int FindKth(vector<int> &numbers, int left, int right, int k)
    {
        int res;
        int pivotIndex = left + 1;

        if(left == right)
        {
            ddebug <<"left == right" <<numbers[left] <<endl;
            return numbers[left];
        }

        pivotIndex = Partition(numbers, left, right);


        if(pivotIndex < k)          //  当前查找到的比第K个数小
        {
            // 第K大的的在pivot之前, 在[pivotIndex + 1, right]之间查找
            ddebug <<"K is in [" <<pivotIndex + 1 <<", " <<right <<"]" <<endl;
            return FindKth(numbers, pivotIndex + 1, right, k);
        }
        else if(pivotIndex > k)     //  当前查找到的比第K个数大
        {
            // 第K小的在pivot之前, 在[left, pivotIndex - 1]之间查找
            ddebug <<"K is in [" <<left <<", " <<pivotIndex - 1 <<"]" <<endl;
            return FindKth(numbers, left, pivotIndex - 1, k);
        }
        else      //  这里返回的是其位置
        {
            /// return pivotIndex; ///  error
            ddebug <<"pivotIndex == k, " <<numbers[pivotIndex] <<endl;
            return numbers[pivotIndex];
        }
    }


    /**
     * [CheckMoerThanHalf 检查num元素在数组numbers中出现的次数是否超过一半]
     * @AuthorHTL
     * @DateTime  2016-04-26T11:20:35+0800
     * @param     numbers                  [待处理的数组]
     * @param     num                      [待查询的元素]
     * @return                             [如果元素num在数组numbers中出现的次数超过数组长度的一半则返回true, 否则返回false]
     */
    bool CheckMoerThanHalf(vector<int> numbers, int num)
    {
        int count = 0;
        for(int i = 0; i < numbers.size( ); i++)
        {
            if(numbers[i] == num)
            {
                count++;
            }
        }
        ddebug <<"num = " <<num <<", count = " <<count <<endl;

        if(count > numbers.size( ) / 2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    class greater_class
    {
    public:

        bool operator()(int a, int b)
        {
            return a > b;
        }
    };


    vector<int> GetLeastNumbers_Solution(vector<int> numbers, int k)
    {
        return LeastKNumbers_ByMinHeap(numbers, k);
    }

    vector<int> LeastKNumbers_ByMinHeap(vector<int> numbers, int k)
    {
        vector<int> res;



        if(numbers.size( ) == 0 || numbers.size( ) < k)
        {
            return res;
        }
        make_heap(numbers.begin( ), numbers.end( ), greater_class());

        for(int i = 0; i < k; i++)
        {
            //  最小的元素在栈顶
            debug <<numbers[0] <<" ";
            res.push_back(numbers[0]);

            ///  一下两种操作均可以
            // [1]  --  清除它, 然后重新排序堆
            //numbers.erase(numbers.begin( ));
            //sort_heap(numbers.begin( ), numbers.end( ));

            // [2]  --  当然从堆出弹出这个栈顶元素
            pop_heap(numbers.begin( ), numbers.end( ), greater_class( ));   // 弹出一个元素后，剩下的又重建了 heap，仍保持heap的性质
            numbers.pop_back();         // vector 删除末尾元素
        }

        return res;
    }

};


int __tmain( )
{

    int arr[ ] = { 4, 5, 1, 6, 2, 7, 3, 8 };
    std::vector<int> vec(arr, arr + 8);

    Solution solu;
    solu.GetLeastNumbers_Solution(vec, 4);
    return 0;
}

```



#参考
[程序员编程艺术：第三章、寻找最小的k个数](http://blog.csdn.net/v_JULY_v/article/details/6370650)

[程序员编程艺术：第三章续、Top K算法问题的实现](http://blog.csdn.net/v_JULY_v/article/details/6403777)

[关于查找数组中最小的k个元素的解答、updated](http://blog.csdn.net/v_JULY_v/article/details/6234929)

[程序员编程艺术：三之三续、求数组中给定下标区间内的第K小（大）元素](http://blog.csdn.net/v_JULY_v/article/details/6452100)

[寻找最小的K个数](http://blog.chinaunix.net/uid-26548237-id-3513260.html)
