#1    链接
-------

>牛客OJ：[滑动窗口的最大值](http://www.nowcoder.com/practice/1624bc35a45c42c0bc17d17fa0cba788?tpId=13&tqId=11217&rp=4)
>
>九度OJ：未收录
>
>GitHub代码： [065-滑动窗口的最大值](https://github.com/gatieme/CodingInterviews/tree/master/065-滑动窗口的最大值)
>
>CSDN题解：[剑指Offer--065-滑动窗口的最大值](http://blog.csdn.net/gatieme/article/details/51915826)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 |
| ------- |:-------:|:-------:| -------:|
|[038-数字在排序数组中出现的次数](http://www.nowcoder.com/practice/1624bc35a45c42c0bc17d17fa0cba788?tpId=13&tqId=11217&rp=4) | 未收录 |  [剑指Offer--065-滑动窗口的最大值](http://blog.csdn.net/gatieme/article/details/51915826) | [065-滑动窗口的最大值](https://github.com/gatieme/CodingInterviews/tree/master/065-滑动窗口的最大值) |


#2    题意
-------

**题目描述**

题目描述

>给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值


例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3

那么一共存在6个滑动窗口, 他们的最大值分别为{4,4,6,6,6,5}；

针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个
{[2,3,4],2,6,2,5,1}，最大值4
{2,[3,4,2],6,2,5,1}，最大值4
{2,3,[4,2,6],2,5,1}，最大值6
{2,3,4,[2,6,2],5,1}，最大值6
{2,3,4,2,[6,2,5],1}，最大值6
{2,3,4,2,6,[2,5,1]}，最大值5


#3    暴力解法
-------

如果采用蛮力法，这个问题似乎不难解决：可以扫描每一个滑动窗口的所有数字并找出其中的最大值。如果滑动窗口的大小为k，需要O(k)时间才能找出滑动窗口里的最大值。对于长度为n的输入数组，这个算法总的时间复杂度是O(nk)


```c
#include <iostream>
#include <vector>
#include <deque>
#include <iterator>

#include <climits>

using namespace std;


//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

/*  单调队列，O(n)
 *  引用马客（Mark）的解题思路，马客没加注释，我用自己的理解加下注释，希望对你们有用，
 *  如有错误，见谅，我会及时修改
 *  deque s中存储的是num的下标  */

class Solution
{
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        if(num.size() == 0 || size == 0)
        {
            return res;
        }

        for(int start = 0;
            start <= (int)(num.size( ) - size);
            start++)
        {
            int end = start + size;
            int max = INT_MIN;
            for(int index = start; index < end; index++)
            {
                if(num[index] > max)
                {
                    max = num[index];
                }
            }

            debug <<"[" <<start <<", " <<end <<"], max = " <<max <<endl;
            res.push_back(max);
        }

        return res;
    }

};



int __tmain( )
{
    Solution solu;

    int array[] = { 2, 3, 4, 2, 6, 2, 5, 1 };
    vector<int> vec(array, array + 8);

    vector<int> res = solu.maxInWindows(vec, 3);
    copy(res.begin( ), res.end( ), ostream_iterator<int>(cout," "));

    return 0;
}

```


#4    队列中取最大值操作问题
-------

实际上一个滑动窗口可以看成是一个队列。当窗口滑动时，处于窗口的第一个数字被删除，同时在窗口的末尾添加一个新的数字。这符合队列的先进先出特性。如果能从队列中找出它的最大数，这个问题也就解决了。 

>在面试题21中。我们实现了一个可以用O(1)时间得到最小值的栈。同样，也可以用O(1)时间得到栈的最大值。同时在面试题7中，我们讨论了如何用两个栈实现一个队列。综合这两个问题的解决方法，我们发现如果把队列用两个栈实现，由于可以用O(1)时间得到栈中的最大值，那么也就可以用O(1)时间得到队列的最大值，因此总的时间复杂度也就降到了O(n)

因此我们现在的问题归结为, 实现一个**尽可能快的找出队列最大值**

起初没仔细看，还以为与此前的自定义栈-pop-push-min-时间复杂度都为O(1) 是一样的，后来才发现不是一回事，有差别的。对于栈来说，我们可以的入栈和出栈不会影响辅助数组内的情况，假设当前N个元素，（为了说明简单，下标从1开始），辅助空间的F[1]记录的是A[1,1]内的最值位置，F[2]记录的是A[1,2]内的最值位置，···，F[N]记录的是A[1,N]内的最值位置。在插入F[k+1]=A[F[k]]与A[k+1]两者最值的位置，插入复杂度为O(1)，在删除第k+1个节点时，删除A[k+1]和F[k+1]，这并不影响F[1]-F[k]，因此删除的复杂度为O(1)，取最值，假设当前N个元素，即返回A[F[N]]。
对于队列来说，如果套用栈的辅助数组方法，假设当前有N个元素，下标从1开始，那么F[1]记录的是A[1,N]中的最值，F[2]记录的是A[2,N]中的最值，···，F[N]记录的是A[N,N]中的最值。当A[k+1]入队时，需要更新F[1]到F[k]，F[K+1]=K+1，因此插入的复杂度为O(N)，当F[k]出队时，删除F[k]即可（每次出队的都是第一个元素，实际上此时F[1]-F[k-1]已经出队完毕了），因此删除的复杂度为O(1)。取最值的复杂度是O(1)。

队列与栈的区别很清楚了。我们在编程之美上找到了两个答案
*    一个是构建最大堆
*    另一个是用两个栈来实现。
 
##4.1    最大堆的方法
-------

    队列本身要么顺序结构要么链接结构，还那么存。另外对于队列每个元素构建一个节点（包含在队列中的位置），这些节点构成一个最大堆，因此插入和删除操作都要维护这个最大堆，时间复杂度都是O(LogN)，取最大值的复杂度为 O(1)。

暴力的思路简单，但是时间复杂度过高，因此需要改进。可以使用一个最大堆来保存size个数字，每次插入数字时只需要O(lgsize)的时间，从堆中取最大值只需要O(1)的时间。

随着窗口由左向右滑动，因此堆中有些数字会失效（因为它们不再包含在窗口中）。

```c
class Solution
{
    typedef pair<int,int> Pair;
public :
    vector<int> maxInWindows(const vector<int> &num, unsigned int size)
    {
        vector<int> result;
        priority_queue<Pair> Q;
        if (num.size() < size || size < 1)
        {
            return result;
        }

        for (int i = 0; i < size-1; i++)
        {
            Q.push(Pair(num[i],i));
        }

        for (int i = size-1; i < num.size(); i++)
        {
            Q.push(Pair(num[i],i));
            Pair p = Q.top();
            while(p.second < i-(size-1)) {
                Q.pop();
                p = Q.top();
            }
            result.push_back(p.first);
        }
//        result.push_back(Q.top().first);
        return result;
    }
};


```

##4.2    两个栈的方法
-------
  
A栈，B栈，这两个栈都是前面提到的pop-push-min复杂度都为O(1)的空间换时间的实现。
取最值：返回A栈的最值和B栈的最值相比后的最值。复杂度O(1)。

入队操作：直接入到B栈中。复杂度O(1)。
出队操作：如果A栈不为空，直接A栈出栈，复杂度为O(1)，如果A栈为空，那么将B栈内容逐个出栈并且逐个入栈到A中，然后A栈出栈，复杂度O(N)，实际上是B栈的长度。

对于这种方法，如果对列的操作时，一连串的入栈，然后是一连串的出栈，那么就是首先不停向B入栈，然后第一个出栈，B栈元素全压入A栈，A出栈一个，这一步是N的复杂度，但是此后是不停的从A出栈，这都是O (1)的复杂度。还不错呢。而且借助了栈的代码，方便实现。对于这样的情景，就是只有第一个出栈的时候，要O(N)，复杂度不是很均匀。对于每个元素来说，要么入B栈，入A栈，从A栈弹出，即总体是3N，平均下来基本上是O(3)，要不最大堆的O(LogN)是快了不少呢。


```c
#include <iostream>
#include <vector>
#include <iterator>

#include <climits>

using namespace std;


//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain


#define MAX 100

class Stack
{
private:
    int stackItem[MAX];
    int link2NextMaxValueIndex[MAX];
    int stackTop;
    int maxValueIndex;
public:
    Stack() : stackTop(-1), maxValueIndex(-1) {}
    int size() { return stackTop + 1; }
    int empty() { return stackTop < 0 ? 1 : 0; }

    void push(int val)
    {
        ++stackTop;
        if(stackTop == MAX)
        {
            cout << "The stack has been full!" << endl;
            return;
        }
        else
        {
            stackItem[stackTop] = val;
            if(max() < val)
            {
                link2NextMaxValueIndex[stackTop] = maxValueIndex;
                maxValueIndex = stackTop;
            }
            else
                link2NextMaxValueIndex[stackTop] = -1;
        }
    }

    int pop()
    {
        int ret;
        if(stackTop == -1)
        {
            cout << "The stack is empty!" << endl;
            return -1;
        }
        else
        {
            ret = stackItem[stackTop];
            if(stackTop == maxValueIndex)
            {
                maxValueIndex = link2NextMaxValueIndex[stackTop];
            }
            --stackTop;

            return ret;
        }
    }

    int max()
    {
        if(maxValueIndex >= 0)
            return stackItem[maxValueIndex];
        else
            return -100;
    }

};
class Queue
{
private:
    Stack stackIn;
    Stack stackOut;
public:
    int size( )
    {
        return stackIn.size( ) + stackOut.size( );
    }
    int max( )
    {
        return std::max(stackIn.max( ), stackOut.max( ));
    }

    void enQueue(int val)
    {
        stackIn.push(val);
    }

    int deQueue()
    {
        if(stackOut.empty() and !stackIn.empty())
        {
            while(!stackIn.empty())
                stackOut.push(stackIn.pop());
        }
        return stackOut.pop();
    }
};

class Solution
{
public      :
   vector<int> maxInWindows(const vector<int>& num, unsigned int size)
   {
        unsigned int    length = num.size( );
        vector<int>     res;

        if(length == 0 || size == 0 || length < size)
        {
            return res;
        }

        Queue           que;
        for(int i = 0; i < num.size( ); i++)
        {
            if(que.size( ) < size)
            {
                que.enQueue(num[i]);
            }
            else
            {
                res.push_back(que.max( ));

                que.enQueue(num[i]);
                que.deQueue( );
            }
        }
        if(que.size( ) == size)
        {
            res.push_back(que.max( ));
        }

        return res;
    }


};

int __tmain()
{
    Solution solu;

    int array[] = { 2, 3, 4, 2, 6, 2, 5, 1 };
    vector<int> vec(array, array + 8);

    vector<int> res = solu.maxInWindows(vec, 3);
    copy(res.begin( ), res.end( ), ostream_iterator<int>(cout," "));

    return 0;
}


```

#5    单调队列
-------


还是把滑动窗口当成是队列来处理，其实是最大值队列的改进策略, 思路基本类似, 但是队列中存储的是最大值的下标, 为了得到滑动窗口的最大值，队列序可以从两端删除元素，因此使用双端队


<font color=0x00ffff>                                                                        
原则：                                        
                   
 对新来的元素k，将其与双端队列中的元素相比较                                  

*    前面比k小的，直接移出队列（因为不再可能成为后面滑动窗口的最大值了!）,    
 
*    前面比k大的X，比较两者下标，判断X是否已不在窗口之内，不在了，直接移出队列
 
队列的第一个元素是滑动窗口中的最大值  
</font>


```c
class Solution
{
public :
    /*  方式二：利用队列来解决,时间复杂度为O(n)
        利用双端队列来实现单调队列(索引对应的值是单调的)  */
   vector<int> maxInWindows(const vector<int>& num, unsigned int size)
   {
        unsigned int length = num.size( );
        vector<int> result;

        if(length == 0 || size == 0 || length < size)
        {
            return result;
        }

        deque<int> indexQueue;

        /*  第一个窗口的处理比较简单, 直接找到最大的那个即可  */
        for(unsigned int i = 0;
            i < size;
            i++)
        {
            /*  删除队尾元素
             *  对于当前元素num[i]
             *  前面比k小的，直接移出队列
             *  因为不再可能成为后面滑动窗口的最大值了  */
            while(indexQueue.empty( ) != true
               && num[i] >= num[indexQueue.back( )])
            {
                indexQueue.pop_back( );
            }
            /*  将当前元素的下表压入队列中  */
            indexQueue.push_back(i);
        }

        /* 处理后续的滑动窗口*/
        for(unsigned int i = size;
            i < length;
            i++)
        {
            /*  队列中的第一个元素是当前滑动窗口最大值的下标  */
            result.push_back(num[indexQueue.front()]);

            /*  删除队尾元素
             *  对于当前元素num[i]
             *  前面比k小的，直接移出队列
             *  因为不再可能成为后面滑动窗口的最大值了  */
            while(indexQueue.empty( ) != true
               && num[i]>=num[indexQueue.back()])
            {
                indexQueue.pop_back();
            }

            /*  删除队首元素
             *  前面比k大的X，
             *  比较两者下标，判断X是否已不在窗口之内，
             *  不在了，直接移出队列  */
            if(indexQueue.empty( ) != true
            && indexQueue.front( ) < (int)(i - size + 1))
            {
                indexQueue.pop_front( );
            }
            indexQueue.push_back(i);
        }
        result.push_back(num[indexQueue.front()]);
        return result;
    }
};

```

下面代码是网上看到的, 其实一样的思路, 只是写法更简练

```c
/*  单调队列，O(n)
 *  deque s中存储的是num的下标
 *
 *  题目：滑动窗口的最大值
 *
 *  思路：滑动窗口应当是队列，但为了得到滑动窗口的最大值，队列序可以从两端删除元素，因此使用双端队列。
 *
 *  原则：
 *  对新来的元素k，将其与双端队列中的元素相比较
 *  1.  前面比k小的，直接移出队列（因为不再可能成为后面滑动窗口的最大值了!）,
 *  2.  前面比k大的X，比较两者下标，判断X是否已不在窗口之内，不在了，直接移出队列
 *  队列的第一个元素是滑动窗口中的最大值
 *  */

class Solution
{
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int>     res;
        deque<int>      index;
        for(unsigned int i = 0; i < num.size( ); i++)
        {
            cout <<"size["<<index.size( ) <<"] : ";
            copy(index.begin( ), index.end( ), ostream_iterator<int>(cout," "));
            cout <<endl;

            /*  从后面依次弹出队列中比当前num值小的元素，
             *  同时也能保证队列首元素为当前窗口最大值下标  */
            while(index.size( ) != 0 && num[index.back( )] <= num[i])
            {
                index.pop_back( );
            }
            /*  当前窗口移出队首元素所在的位置
                即队首元素坐标对应的num不在窗口中，需要弹出  */
            while(index.size() && i - index.front( ) + 1 > size)
            {
                index.pop_front( );
            }

            /*  把每次滑动的num下标加入队列  */
            index.push_back(i);

            /*  当滑动窗口首地址i大于等于size时才开始写入窗口最大值  */
            if(size != 0 && i + 1 >= size)
            {
                res.push_back(num[index.front( )]);
            }
        }
        return res;
    }
};
```