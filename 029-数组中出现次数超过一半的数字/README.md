#链接
-------
>牛客OJ：[数组中出现次数超过一半的数字](http://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&tqId=11181&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
>
>九度OJ：http://ac.jobdu.com/problem.php?pid=1370
>
>GitHub代码： [029-数组中出现次数超过一半的数字](https://github.com/gatieme/CodingInterviews/tree/master/029-数组中出现次数超过一半的数字)
>
>CSDN题解：[剑指Offer--029-数组中出现次数超过一半的数字](http://blog.csdn.net/gatieme/article/details/51251311)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 |
| ------ |:------:| --------:|:----------:|
|[数组中出现次数超过一半的数字](http://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&tqId=11181&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking) | [1370-数组中出现次数超过一半的数字](http://ac.jobdu.com/problem.php?pid=1370) | [剑指Offer--029-数组中出现次数超过一半的数字](http://blog.csdn.net/gatieme/article/details/51251311) | [029-数组中出现次数超过一半的数字](https://github.com/gatieme/CodingInterviews/tree/master/029-数组中出现次数超过一半的数字) |

<br>**您也可以选择[回到目录-剑指Offer--题集目录索引](http://blog.csdn.net/gatieme/article/details/51916802)**





#题意
-------

**题目描述**

>输入一个字符串,按字典序打印出该字符串中字符的所有排列
>
>例如输入字符串abc,
>
>则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
>
>结果请按字母顺序输出。
>
>**注意**
>输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母


**样例输入**

>1 2 3 2 2 2 5 4 2

**样例输出**

>2


#排序以后统计个数
-------

如果是排序好的数组，那么我们就很容易统计每个数组出现的次数，而题目中并没有说数组是排序好的，因此我们需要先排序（最好的情况下$O(nlogn)$），后统计（一次遍历即可$O(n)$）,因此这种方法的时间复杂度为$O(nlogn)$

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

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
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if(numbers.size( ) == 0)
        {
            return 0;
        }
        else if(numbers.size( ) == 1)
        {
            return numbers[0];
        }

        sort(numbers.begin( ), numbers.end( ));

        int res = 0;
        int count = 1;
        for(int i = 0; i < numbers.size( ) - 1; i++)
        {
            if(numbers[i] == numbers[i + 1])
            {
                count++;        //  numbers[i]又在下一个位置i + 1出现了
            }
            else                //  i是numbers[i]是最后出现的位置了
            {
                debug <<numbers[i] <<", count = " <<count <<endl;
                count = 1;

            }
            ///  最后一个数的个数需要特殊处理下
#ifdef __tmain
            if(i == numbers.size( ) - 2)
            {
                debug <<numbers[i + 1] <<", count = " <<count <<endl;
            }
#endif // __tmain

            /// 个数超过数组的一半时候说明已经找到了，就终止
            if(count > numbers.size( ) / 2)
            {
                res = numbers[i];
                break;
            }
        }

        return res;
    }
};


int __tmain( )
{
    int arr1[] = { 5, 5, 2, 2, 3, 3, 5, 5, 5};

    vector<int> vec1(arr1, arr1 + 9);

    Solution solu;
    cout <<solu.MoreThanHalfNum_Solution(vec1) <<endl;


    int arr2[] = { 1, 2 };

    vector<int> vec2(arr2, arr2 + 2);
    cout <<solu.MoreThanHalfNum_Solution(vec2) <<endl;
    return 0;
}
```

#基于Partition函数的$O(n)$的查找第K大的数
-------

上面基于排序的算法比较保守，因为它没有充分利用**出现次数超过一半**这个条件。

数组中有一个数字出现的次数超过了数组长度的一半，那么**如果我们把这个数组排序，那么排序之后位于数组中间的那个数字一定就是那个出现次数超过数组长度一半的数字**

也就是说这个数字其实就是统计学上的中位数，即长度为N的数组中的$N/2$大的元素，因此我们的题目最后成为返回数组中第K（$K=Len/2$）大的数。

因此我们的问题成为**查找一个数组中的K大的元素**

>参考
>
>[【编程之美】读书笔记：寻找最大的K个数](http://blog.csdn.net/xiaoding133/article/details/8037086)
>
>[寻找第K大的数 ](http://blog.chinaunix.net/uid-20196318-id-189514.html)
>
>[O(N)的时间寻找最大的K个数](
http://www.cnblogs.com/luxiaoxun/archive/2012/08/06/2624799.html)


这个由很多种方法的，这里我们介绍其中一种分治划分的方法，是基于快速排序算法的

我们写过**快速排序算法**，其中的Partition()方法是一个最重要的方法，该方法返回一个index，能够保证index位置的数是已排序完成的，在index左边的数都比index所在的数小，在index右边的数都比index所在的数大。那么本题就可以利用这样的思路来解。

1.    通过Partition()返回index，如果index==mid，那么就表明找到了数组的中位数；如果index<mid，表明中位数在[index+1,end]之间；如果index>mid，表明中位数在[start,index-1]之间。知道最后求得index==mid循环结束。

2.    根据求得的index，遍历一遍数组，每当出现一个等于index所指向的数时time++，最后判断time是否大于数组长度的一半，如果大于则表明index所指向的数就是所求的数，如果不是，则表明不存在一个数出现的次数超过数组长度的一半。


```cpp
class Solution
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if(numbers.size( ) == 0)
        {
            return 0;
        }
        else if(numbers.size( ) == 1)
        {
            return numbers[0];
        }

        int num = FindKth(numbers, 0, numbers.size( ) - 1, numbers.size( ) / 2);

        if(CheckMoerThanHalf(numbers, num) == true)
        {
            return num;
        }
        else
        {
            return 0;
        }
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

        debug <<"pivotNum = " <<pivotNum <<endl;
        while(i < j)
        {
            while(i < j && numbers[j] >= pivotNum)
            {
                debug <<"[" <<i <<", " <<j <<"] " <<numbers[j] <<" >= " <<pivotNum <<endl;
                j--;
            }
            debug <<"now we find i = " <<i <<", posJ = " <<j <<", num = " <<numbers[j] <<" < " <<pivotNum <<endl;;
            numbers[i] = numbers[j];        // 将找到的那个比枢轴小的数，放在枢轴左侧I的位置
            //swap(numbers[i], numbers[j]); // 也可以使用交换, 但是没有必要, 因为枢轴的位置并没有最后确定

            while(i < j && numbers[i] <= pivotNum)
            {
                debug <<"[" <<i <<", " <<j <<"] " <<numbers[i] <<" <= " <<pivotNum <<endl;
                i++;
            }

            debug <<"now we find j = " <<i <<", posI = " <<j <<", num = " <<numbers[i] <<" > " <<pivotNum <<endl;;
            numbers[j] = numbers[i];        // 将找到的那个比枢轴大的数，放在枢轴右侧J的位置
            //swap(numbers[i], numbers[j]); // 也可以使用交换, 但是没有必要, 因为枢轴的位置并没有最后确定
        }

        numbers[i] = pivotNum;              //  最后的位置 i == j 就是枢轴的位置

#ifdef __tmain

        debug <<pivotNum <<" 's post is" <<i <<endl;
        for(int pos = left; pos <= right; pos++)
        {
            debug <<numbers[pos] <<" ";
        }
        debug <<endl;
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
            debug <<"left == right" <<numbers[left] <<endl;
            return numbers[left];
        }

        pivotIndex = Partition(numbers, left, right);


        if(pivotIndex < k)          //  当前查找到的比第K个数小
        {
            // 第K大的的在pivot之前, 在[pivotIndex + 1, right]之间查找
            debug <<"K is in [" <<pivotIndex + 1 <<", " <<right <<"]" <<endl;
            return FindKth(numbers, pivotIndex + 1, right, k);
        }
        else if(pivotIndex > k)     //  当前查找到的比第K个数大
        {
            // 第K小的在pivot之前, 在[left, pivotIndex - 1]之间查找
            debug <<"K is in [" <<left <<", " <<pivotIndex - 1 <<"]" <<endl;
            return FindKth(numbers, left, pivotIndex - 1, k);
        }
        else      //  这里返回的是其位置
        {
            /// return pivotIndex; ///  error
            debug <<"pivotIndex == k, " <<numbers[pivotIndex] <<endl;
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
        debug <<"num = " <<num <<", count = " <<count <<endl;

        if(count > numbers.size( ) / 2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
```
#阵地攻守（特点--它出现的次数比其他所有的数组出现的次数之和还要多）
-------

还是充分利用**出现次数超过一半**这个条件

>数组中有一个数字出现的次数超过数组长度的一半，也就是说它出现的次数比其他所有数字出现的次数之和还要多
>
>我们考虑**阵地攻守（镇守阵地），遇见一个友军就抱成团，遇见一个敌军就同归于尽，那么最后战场上剩余的肯定就是人数（出现次数）最多的那个队伍（数字）**

采用**阵地攻守**的思想

*    第一个数字作为第一个士兵，守阵地；count = 1；

*    遇到相同元素，count++; 遇到不相同元素，即为敌人，同归于尽,count--；

*    当遇到count为0的情况，又以新的i值作为守阵地的士兵，继续下去，到最后还留在阵地上的士兵，有可能是主元素。

*    再加一次循环，记录这个士兵的个数看是否大于数组一般即可。

由于我们要找的数字出现的次数比他所有数字出现的次数之和还要多，那么要找的数字肯定是最后一次把次数设为1时对应的数字，因为少的元素都已经阵亡了，战场上仅剩下的一定是人数数目要多的那个队伍

```cpp
class Solution
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if(numbers.size( ) == 0)
        {
            return 0;
        }
        else if(numbers.size( ) == 1)
        {
            return numbers[0];
        }

        int num = numbers[0], count = 1;
        ///  阵地攻守
        for(int i = 1; i < numbers.size( ); i++)
        {
            if(numbers[i] == num)    /// 友军, 计数器增加
            {
                count++;
            }
            else                    /// 敌军, 一个士兵同归于尽
            {
                count--;
            }
            debug <<"numbers[i] = " <<numbers[i] <<", count = " <<count <<endl;
            /// 所有士兵已经阵亡
            if(count == 0)
            {
                num = numbers[i];    ///  重新设置镇守阵地的士兵
                count = 1;
            }
        }

        debug <<"find num = " <<num <<endl;
        ///  再加一次循环，记录这个士兵的个数看是否大于数组一般即可
        count = 0;
        for(int i = 0; i < numbers.size( ); i++)
        {
            if(numbers[i] == num)
            {
                count++;
            }
        }

        if(count > numbers.size( ) / 2)
        {
            debug <<"num = " <<num <<", count = " <<count <<endl;
            return num;
        }
        else
        {
            return 0;
        }
    }
};
```

这个思想有一个简单的实现变种，就是现的次数超过数组长度的一半，表明这个数字出现的次数比其他数字出现的次数的总和还多。

所以我们可以考虑每次删除两个不同的数，那么在剩下的数中，出现的次数仍然超过总数的一半。通过不断重复这个过程，不断排除掉其它的数，最终找到那个出现次数超过一半的数字。这个方法，
>例：数组 a[5]={0,1,2,1,1};
                 我们要查找的数字为1，操作步骤为：遍历整个数组，然后每次删除不同的两个数字，过程如下：
               0 1 2 1 1 =>2 1 1=>1

具体实现：我们在考虑删除两个不同的数字的时候，实际上可以同过计数来实现，而不是物理上真正的删除。 在遍历数组的时候保存两个值：一个是数组中的一个数字，一个是次数。当我们遍历到下一个数字的时候，如果下一个数字和我们之前保存的数字相同，则次数加1。如果下一个数字和我们之前保存的数字不同，则次数减1。如果次数为零，我们需要保存下一个数字，并把次数设为1。由于我们要找的数字出现的次数比其他所有数字出现的次数之和还要多，那么要找的数字肯定是最后一次把次数设为1时对应的数字。



#使用STL的count函数统计某个值出现的次数
-------

STL的count函数原型如下

```cpp
template<class InputIterator, class T> inline
   size_t count(
      InputIterator First,
      InputIterator Last,
      const T& Value
)
```
algorithm头文件定义了一个count的函数，其功能类似于find。
这个函数使用一对迭代器和一个值做参数，返回这个值出现次数的统计结果。
count只能统计某个特定元素出现的次数，不够灵活，因此STL提供了count_if，前两个参数是iterator(迭代器)，表示查找半闭合区间的前后两个位置，第三个参数为一个用户定义的predicate function object，而predicate意思就是说是一个返回值是bool型的仿函数(function object，也称functor)。
```cpp
template<class _InIt, class _Pr> inline
typename iterator_traits<_InIt>::difference_type
count_if(_InIt _First, _InIt _Last, _Pr _Pred);
```
核心代码：
```cpp
class Solution
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
//        return numbers.empty( ) ? 0 : *find_if(numbers.begin( ), numbers.end( ),[numbers](int x)
//            {
//                return (count(numbers.begin( ),numbers.end( ), x) * 2) > numbers.size();
//            });

        if(numbers.size( ) == 0)
        {
            return 0;
        }
        for(int i = 0 ; i < numbers.size( ); i++)
        {
            debug <<"num = " <<numbers[i] <<", count = " <<count(numbers.begin( ), numbers.end( ), numbers[i]) <<endl;
            if(count(numbers.begin( ), numbers.end( ), numbers[i]) * 2 > numbers.size( ))
            {
                return numbers[i];
            }
        }
        return 0;


    }
};
```

#使用map来建立数字到出现次数的映射
-------

我们可以使用一个map来建立数字-=>出现次数的一个映射，这样最后遍历找到出现次数大于数组长度一半的那个元素即可
```cpp
class Solution
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        map<int,int> hmap;  //  建立数字到出现次数的映射

        int nsize = numbers.size();

        for(int i = 0 ; i < nsize; i ++)
        {
            if(hmap.find(numbers[i]) != hmap.end( ))
            {
                hmap[numbers[i]] += 1;
            }
            else
            {
                hmap[numbers[i]] = 1;
            }
        }



        //  查找到出现次数最多的那个元素
        for(map<int,int>::iterator it = hmap.begin( );
            it != hmap.end( );
            ++it)
        {
            debug <<it->first <<", " <<it->second <<endl;
            if(it->second * 2 > nsize)
            {
                return it->first;
            }
        }
        return 0;
    }
};
```
#变种以及扩展
-------

昨天看到了扩展问题，

*    **如果有且只有一个的出现最多的那个数字出现的次数是数组长度的一半呢？又或者是一半减1？**


我们还是继续从我们之前的那道超过一半的数来入手，我们的"阵地攻守"的解法是每遇到2个不同的数，就删除，剩下的就是那个出现次数超过一半的数字。

这个方法对于超过一半的情况可以成立，对于扩展问题就不再行得通了。

但是他们的本质是相同的，

*    对于一个长度为2n的数组，如果有个数出现次数超过n,那么至少有1组，连续2个数是重复的相应的，于是"阵地攻守"中每次不同的元素就删除（同归于尽）就可以找到那个元素

*    如果出现的次数为n, 那么至少有一组连续3个数是重复。每3个不重复的数删除一次

*    如果是n-1, 就是一组至少有连续4个数重复。每4个不重复的数删除一次

>参考
>
>[编程之美系列之二——寻找出现频率超过一半的数](http://www.cnblogs.com/jy02414216/archive/2011/03/04/1970497.html)
>
>[微软面试100题(74):数组中出现次数超过长度的一半/一半减一的元素 ](http://blog.chinaunix.net/uid-26456800-id-3383003.html)

