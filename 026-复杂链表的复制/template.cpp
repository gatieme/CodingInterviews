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
struct RandomListNode
{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x)
    :label(x), next(NULL), random(NULL)
    {
    }
};
#endif  //__tmain


class Solution
{
public:
    /// 查找到oldhead指向的原来链表中随机指针randNode在新的链表newHead中的对应结点
    RandomListNode* FindInNew(RandomListNode *oldHead, RandomListNode *newHead, RandomListNode *randNode)
    {
        RandomListNode *currNode = oldHead;
        RandomListNode *newNode = newHead;

        while(currNode != NULL && newNode != NULL)
        {
            if(randNode == currNode)
            {
                return newNode;
            }

            /// 两个链表
            currNode = currNode->next;
            newNode = newNode->next;
        }

        return NULL;
    }
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL)
        {
            return NULL;
        }

        RandomListNode *currNode = pHead;
        RandomListNode *newHead = NULL, *preNode = NULL, *newNode = NULL;

        ///  首先复制原链表指针域
        while(currNode != NULL)
        {
            newNode = new RandomListNode(currNode->label);
            currNode = currNode->next;

            if(preNode == NULL)
            {
                newHead = newNode;
            }
            else
            {
                preNode->next = newNode;
            }

            preNode = newNode;
        }

        //  接着复制随机指针域
        currNode = pHead;
        newNode = newHead;
        while(currNode != NULL && newNode != NULL)
        {
            RandomListNode *randNode = currNode->random;
            RandomListNode *newRandNode = FindInNew(pHead, newHead, randNode);
            newNode->random = newRandNode;

            currNode = currNode->next;
            newNode = newNode->next;
        }

        return newHead;
    }

};


int __tmain( )
{

    return 0;
}
