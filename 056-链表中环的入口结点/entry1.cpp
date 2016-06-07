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
