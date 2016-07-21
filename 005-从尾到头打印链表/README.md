#链接
------- 

>牛客OJ：[从尾到头打印链表](http://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035?tpId=13&tqId=11156&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
>
>九度OJ：http://ac.jobdu.com/problem.php?pid=1511
>
>GitHub代码： [005-从尾到头打印链表](https://github.com/gatieme/CodingInterviews/tree/master/005-%E4%BB%8E%E5%B0%BE%E5%88%B0%E5%A4%B4%E6%89%93%E5%8D%B0%E9%93%BE%E8%A1%A8)
>
>CSDN题解：[剑指Offer--005-从尾到头打印链表](http://blog.csdn.net/gatieme/article/details/51107632)



| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 |
| ------------- |:-------------:| -----:|
| [从尾到头打印链表](http://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035?tpId=13&tqId=11156&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking) | [1511-从尾到头打印链表](http://ac.jobdu.com/problem.php?pid=1511)   | [剑指Offer--005-从尾到头打印链表](http://blog.csdn.net/gatieme/article/details/51107632)   | [005-从尾到头打印链表](https://github.com/gatieme/CodingInterviews/tree/master/005-%E4%BB%8E%E5%B0%BE%E5%88%B0%E5%A4%B4%E6%89%93%E5%8D%B0%E9%93%BE%E8%A1%A8)  |

<br>
你也可以选择**[回到目录--剑指Offer--题集目录索引](http://blog.csdn.net/gatieme/article/details/51916802)**


#题意
-------
题目描述

>输入一个链表，从尾到头打印链表每个节点的值。 



输入描述:

>输入为链表的表头



输出描述:

>输出为需要打印的“新链表”的表头


##反转链表
-------


首先我们想到的就是**反转链表**了,如果把链表反转了，然后再返回头，这样再次遍历的时候就相当于从尾到头打印了。

但是修改输入数据真的可行么？

剑指Offer中为我们在面试中提出了如下小提示
>在面试时候，如果我们打算修改输入的数据，最好先问问面试官是不是允许修改

通常打印只是一个只读操作，我们肯定不希望输入时候修改链表的内容

##利用栈的后进先出特性
-------

单链表的遍历只能从前往后，但是需要从尾往头输出，这不是典型的"先进后出"么，那么我们可以用栈模拟输出

每经过一个结点的时候，把该结点放到一个栈中。当遍历完整个链表后，再从栈顶开始逐个输出结点的值，此时输出的结点的顺序已经反转过来了。

代码如下

```cpp
#include <iostream>

#include <stack>
#include <vector>

using namespace std;

//  调试开关
#define __tmain main

#ifdef __tmain

#define dout cout

#else

#define dout 0 && cout

#endif // __tmain



#ifdef __tmain

struct ListNode
{
public :
    int val;
    struct ListNode *next;

    /*ListNode(int x) :
    val(x), next(NULL)
    {
    }*/
};

#endif // __tmain


/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution
{
public:
    vector<int> printListFromTailToHead(struct ListNode* head)
    {
        ListNode *node = head;
        stack<int> st;
        int count = 0;
        while(node != NULL)
        {
            dout <<node->val <<"in stack" <<endl;
            st.push(node->val);

            count++;
            node = node->next;

        }

        //  为了效率我们静态vector开辟空间
        vector<int> res(count);
        dout <<"count = " <<count <<endl;
        for(int i = 0; i < count && st.empty( ) != true; i++)
        {
            dout <<st.top() <<"in vector" <<endl;
            // 如果静态开辟vector不能使用push_back
            // 否则会在原来数据的基础上增加
            //res.push_back(st.top( ));
            res[i] = st.top( );
            st.pop( );

        }

        return res;
    }
};





int __tmain( )
{
    ListNode list[4];
    list[0].val = 1;
    list[0].next = &list[1];
    list[1].val = 2;
    list[1].next = &list[2];
    list[2].val = 3;
    list[2].next = &list[3];
    list[3].val = 4;
    list[3].next = NULL;



    Solution solu;
    vector<int> res = solu.printListFromTailToHead(list);

    cout <<"there are " <<res.size( ) <<"datas in vector" <<endl;
    for(int i = 0; i < res.size( ); i++)
    {
        cout <<res[i] <<endl;
    }
    return 0;
}

```


#递归实现
-------
递归在本质上就是一个栈结构，于是很自然地想到用递归来实现。要实现反过来输出链表，每访问到一个结点的时候，先递归输出它后面的结点，再输出该结点自身，这样链表的输出结构就反过来了。

算法流程如下
*    只要当前节点不为NULL，也就是链表没到头，就一直递归
*    在递归结束时，将元素压入

这样当递归结束进行返回时，会将递归栈中的数据依次压入vector中，而压入的顺序就是栈中的顺序，即从尾到头



```c
class Solution
{
public:
    vector<int> printListFromTailToHead(struct ListNode* head)
    {

        vector<int> res;
        printListFromTailToHeadRecursion(head, res);
        return res;
    }


    void printListFromTailToHeadRecursion(struct ListNode* head, vector<int> &res)
    {
        if(head != NULL)
        {
            printListFromTailToHeadRecursion(head->next, res);
            res.push_back(head->val);
        }
    }
};
```

上面用辅助函数的方法，每次都需要传递一个vector，很麻烦啊，我们可以直接用一个成员变量来存储

```cpp
class Solution
{
public:
    vector<int> res;

    vector<int> printListFromTailToHead(struct ListNode* head)
    {
        if(head != NULL)
        {
            printListFromTailToHead(head->next);
            res.push_back(head->val);
        }

        return res;

    }
};
```


