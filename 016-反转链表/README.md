#链接
------- 

>牛客OJ：[反转链表](http://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=13&tqId=11168&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
> 
>九度OJ：http://ac.jobdu.com/problem.php?pid=1518
> 
>GitHub代码： [016-反转链表](https://github.com/gatieme/CodingInterviews/tree/master/016-反转链表)
>
>CSDN题解：[剑指Offer--016-反转链表](http://blog.csdn.net/gatieme/article/details/511351197)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 | 
| ------------- |:-------------:| -----:| 
|[反转链表](http://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=13&tqId=11168&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | [1518-反转链表](http://ac.jobdu.com/problem.php?pid=1518) | [剑指Offer--016-反转链表](http://blog.csdn.net/gatieme/article/details/51135119) | [016-反转链表](https://github.com/gatieme/CodingInterviews/tree/master/016-反转链表)|



#题意
-------


**题目描述**


>输入一个链表，反转链表后，输出链表的所有元素。

#三指针滑动pPrev -> pNode -> pNext;
-------
通常我们想到的就是单个指针同时滑动
比如当前节点pNode所处的位置如下
>pPrev -> pNode -> pNext;
我们先保存原来的下一个指针位置，要不然翻转后其next会指向pPrev，从而丢失指向pNext的指针
接着反转指针，
然后下面指针同步后移，以便处理后面的指针
```cpp
pNext = pNode->next;        //  保存其下一个节点
pNode->next = pPrev;        //  指针指向反转
// 下面开始指针的后移
pPrev = pNode;              //  保存前一个指针
pNode = pNext;              //  递增指针, 指向下一个结点
```
因此代码如下

```cpp
#include <iostream>

using namespace std;

//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain




#ifdef __tmain

struct ListNode
{
public :
	int val;
	struct ListNode *next;

};

#endif // __tmain


class Solution
{
public:
    ListNode* ReverseList(ListNode* pHead)
    {
        ListNode *pReversedHead = NULL;
        ListNode *pNode = pHead;
        ListNode *pPrev = NULL;
        ListNode *pNext = NULL;

        // pPrev -> pNode -> pNext;
        while(pNode != NULL)
        {
            pNext = pNode->next;        //  保存其下一个节点

            pNode->next = pPrev;        //  指针指向反转

            pPrev = pNode;              //  保存前一个指针
            pNode = pNext;              //  递增指针, 指向下一个结点
        }

        return pPrev;           //  最后pPrev指针指向的那个节点就是原来的未指针，新的头指针
    }
};


int __tmain( )
{
    ListNode list[5];
    list[0].val = 1;
    list[0].next = &list[1];
    list[1].val = 2;
    list[1].next = &list[2];
    list[2].val = 3;
    list[2].next = &list[3];
    list[3].val = 4;
    list[3].next = &list[4];
    list[4].val = 5;
    list[4].next = NULL;


    ListNode *node = list;
    while(node != NULL)
    {
        cout <<node->val;
        node = node->next;
    }
    cout <<endl;



    Solution solu;
    node = solu.ReverseList(list);
    while(node != NULL)
    {
        cout <<node->val;
        node = node->next;
    }
    cout <<endl;

    return 0;
    return 0;
}

```

#遍历原链表，将每个元素插入到一个新的链表中的头部


设想这样一个链表，如果每次插入元素的时候都是在头结点的前一个位置插入，那么链表元素的顺序正好跟插入的顺序相反

这个思路也很好，因为他的过程其实就是构建一个每次插入只是在头结点前面的链表的过程，

也是要注意每次保存next的位置防止丢失

```cpp
#include <iostream>

using namespace std;

//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain




#ifdef __tmain

struct ListNode
{
public :
	int val;
	struct ListNode *next;

};

#endif // __tmain


class Solution
{
public:
    ListNode* ReverseList(ListNode* pHead)
    {
        if(pHead == NULL)
        {
            return NULL;
        }

        ListNode *pNode = pHead;
        ListNode *nNode = NULL;
        ListNode *pNext = NULL;

        //  由于链表不带头节点，因此第一个元素的插入需要特殊处理
///////////////
        nNode = pNode;
///////////////

        pNode = pNode->next;           //  保存next指向，防止丢失

///////////////
        nNode->next = NULL;
///////////////
        debug <<nNode->val <<" in list head now..." <<endl;

        //  首先构建原链表的头结点为新链表的尾节点(也就是第一个被插入节点)
        while(pNode != NULL)
        {
            pNext = pNode->next;        //  保存next指向，防止丢失

            //  将pNode节点插入到nNode链表的头部
            //  相当于在nNode结点的前面插入一个节点pNode
///////////////
            pNode->next = nNode;
            nNode = pNode;
///////////////

            debug <<nNode->val <<" in list head now..." <<endl;


            pNode = pNext;          //  移动指针
        }

        return nNode;


    }
};


int __tmain( )
{
    ListNode list[5];
    list[0].val = 1;
    list[0].next = &list[1];
    list[1].val = 2;
    list[1].next = &list[2];
    list[2].val = 3;
    list[2].next = &list[3];
    list[3].val = 4;
    list[3].next = &list[4];
    list[4].val = 5;
    list[4].next = NULL;


    ListNode *node = list;
    while(node != NULL)
    {
        cout <<node->val;
        node = node->next;
    }
    cout <<endl;



    Solution solu;
    node = solu.ReverseList(list);
    while(node != NULL)
    {
        cout <<node->val;
        node = node->next;
    }
    cout <<endl;

    return 0;
    return 0;
}

```
