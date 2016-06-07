#链接
------- 
>牛客OJ：[链表中环的入口结点](http://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4?tpId=13&tqId=11208&rp=3&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
> 
>九度OJ：未收录
> 
>GitHub代码： [056-链表中环的入口结点](https://github.com/gatieme/CodingInterviews/tree/master/056-链表中环的入口结点)
>
>CSDN题解：[剑指Offer--056-链表中环的入口结点](http://blog.csdn.net/gatieme/article/details/51602910)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 | 
| ------------- |:-------------:| -----:| -----:|
|[056-链表中环的入口结点](http://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4?tpId=13&tqId=11208&rp=3&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | 未收录 | [剑指Offer--056-链表中环的入口结点](http://blog.csdn.net/gatieme/article/details/51602910) | [056-链表中环的入口结点](https://github.com/gatieme/CodingInterviews/tree/master/056-链表中环的入口结点) |



>参考
>
>[判断链表中是否有环 —– 有关单链表中环的问题](http://blog.csdn.net/doufei_ccst/article/details/10578315)



#题目描述
-------

>一个链表中包含环，请找出该链表的环的入口结点。



#双指针法
-------


受到第15题的启发[剑指Offer--015-链表中倒数第k个结点](http://blog.csdn.net/gatieme/article/details/51133817), 我们考虑这样一个事实

假设链表长度为N, 那么第N链接到了第k个节点形成了环，即我们需要查找到倒数第N-K+1个节点, 那么环中就有N-K+1个节点，这时候我们定义两个指针$P_1$和$P_2$指向链表的头部, 指针$P_1$先在链表中向前移动n-k+1步,到达第n-k+2个节点, 然后两个指针同步向前移动, 当$P_2$走了K-1步到达环的入口的时候, 指针$P_1$正好走了N+1步, 到达了环的入口, 即两个指针会相遇在环的入口处


那么我们剩下的问题就是如何得到环中节点的数目?

我们可以使用一快一慢两个指针（比如慢指针一次走一步，　慢指针一次走两步），如果走的过程中发现快指针追上了慢指针, 说明遇见了环，而且相遇的位置一定在环内, 考虑一下环内, 从任何一个节点出现再回到这个节点的距离就是环的长度, 于是我们可以进一步移动慢指针，快指针原地不动, 当慢指针再次回到相遇位置时, 正好在环内走了一圈, 从而我们通过计数就可以获取到环的长度


*    第一步，找环中相汇点。分别用p1，p2指向链表头部，p1每次走一步，p2每次走二步，直到p1==p2找到在环中的相汇点。

*    第二步，找环的长度。从环中的相汇点开始, p2不动, p1前移，　当再次相遇时，p1刚好绕环一周, 其移动即为环的长度K

*    第三步, 求换的起点, 转换为求环的倒数第N-K个节点，则两指针left和right均指向起始, right先走K步, 然后两个指针开始同步移动, 当两个指针再次相遇时, right刚好绕环一周回到起点, left则刚好走到了起点位置



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
    int val;
    struct ListNode *next;
};


#endif // __tmain

#define SLOW_STEP   1
#define FAST_STEP   2

class Solution
{
public:

    /*
        如果链表中有环, 则返回环中的任意一个节点
        否则返回NULL
     */
    ListNode* HasCycle(ListNode *pHead)
    {
        if(pHead == NULL)
        {
            return NULL;
        }

        ListNode *pSlow = pHead->next;
        ListNode *pFast = pSlow->next;
        while(pSlow != NULL && pFast != NULL)
        {
            if(pFast == pSlow)
            {
                return pSlow;
            }
            pSlow = NextNode(pSlow, 1);
            pFast = NextNode(pFast, 2);
        }

        return NULL;
    }

    //  获取到node节点后stpe的节点
    ListNode* NextNode(ListNode *node, int step)
    {
        for(int i = 0; i < step && node != NULL; i++)
        {
            node = node->next;
        }

        return node;
    }

    //  获取到链表中环的长度
    //  node是一个链表环内节点的指针
    int GetCycleLength(ListNode *node)
    {
        int length = 0;
        if(node == NULL)
        {
            return length;
        }

        //  考虑一下环内, 从任何一个节点出现再回到这个节点的距离就是环的长度
        ListNode *currNode = node;
        ListNode *stepNode = node->next;
        for(length = 1; ; length++)
        {
            if(stepNode == currNode)
            {
                return length;
            }
            stepNode = stepNode->next;
        }
        return 0;
    }


    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        //  先找到链表环中的某一个节点
        ListNode* meetingNode = HasCycle(pHead);
        if(meetingNode == NULL)
        {
            return NULL;
        }
        debug <<"a node in cycle " <<meetingNode->val <<endl;
        //  获取到链表中环路的长度
        int cycleLength = GetCycleLength(meetingNode);
        debug <<"cycle length = " <<cycleLength <<endl;

        //  找到链表的中环的入口
        ListNode *leftNode = pHead;
        ListNode *rightNode = pHead;

        //  右指针先往前走n步
        rightNode = NextNode(rightNode, cycleLength);
        while(leftNode != rightNode)
        {
            leftNode = leftNode->next;
            rightNode = rightNode->next;
        }

        return leftNode;

    }
};

int __tmain( )
{
    Solution solu;

    ListNode list[6];

    list[0].val = 1;
    list[0].next = &list[1];

    list[1].val = 2;
    list[1].next = &list[2];

    list[2].val = 3;
    list[2].next = &list[3];

    list[3].val = 4;
    list[3].next = &list[4];

    list[4].val = 5;
    list[4].next = &list[5];

    list[5].val = 6;
    list[5].next = &list[2];

    cout <<solu.EntryNodeOfLoop(list)->val <<endl;

    return 0;
}
```

#断链法
-------

时间复杂度为O（n），两个指针，一个在前面，另一个紧邻着这个指针，在后面。
两个指针同时向前移动，每移动一次，前面的指针的next指向NULL。
也就是说：访问过的节点都断开，最后到达的那个节点一定是尾节点的下一个，
也就是循环的第一个。
这时候已经是第二次访问循环的第一节点了，第一次访问的时候我们已经让它指向了NULL，
所以到这结束。

但是这种方法修改了链表的指向



```cpp
class Solution
{
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if (pHead == NULL
         || pHead->next == NULL)
        {
            return NULL;
        }

        ListNode* previous = pHead;
        ListNode* current = pHead->next;
        while (current != NULL)
        {
            previous->next = NULL;
            previous = current;
            current = current->next;
        }

        return previous;
    }
};
```



