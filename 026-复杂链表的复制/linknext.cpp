#include <iostream>

using namespace std;

//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

struct RandomListNode
{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x)
    :label(x), next(NULL), random(NULL)
    {
    }
};


class Solution
{
public:

    ///  复制操作
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL)
        {
            return NULL;
        }

        RandomListNode *currNode = pHead;
        RandomListNode *newHead = NULL, *preNode = NULL, *newNode = NULL;

        ///  首先复制原链表的普通指针域, 一次遍历即可完成
        ///  将新的节点链接杂原来节点的末尾
        while(currNode != NULL)
        {
            newNode = new RandomListNode(currNode->label);

            /// 将新的节点newNode连接在currNode的后面
            newNode->next = currNode->next;
            currNode->next = newNode;

            ///  指向指向下一个节点
            currNode = newNode->next;
        }

        ///  接着复制随机指针域
        ///  原来节点的下一个位置就是其对应的新节点
        currNode = pHead;
        newNode = NULL;
        while(currNode != NULL)
        {
            RandomListNode *randNode = currNode->random;                        ///  随机指针域randNode
            RandomListNode *newNode = currNode->next;
            newNode->random = randNode->next;

            ///  链表同步移动
            currNode = newNode->next;
        }

        /// 将链接在一起的新旧两个链表拆分开
        currNode = pHead;
        newNode = pHead->next;
        while(currNode != NULL)
        {
            /// currNode  newNode newNode->next
            newNode = currNode->next;
            currNode->next = newNode->next;
        }
        return newHead;
    }

};






int __tmain( )
{
    debug <<"test" <<endl;
    return 0;
}
