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
//    RandomListNode(int x)
//    :label(x), next(NULL), random(NULL)
//    {
//    }
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
            if((newNode = new RandomListNode(currNode->label)) == NULL)
            {
                perror("new error : ");
                exit(-1);
            }


            /// 将新的节点newNode连接在currNode的后面
            newNode->next = currNode->next;
            currNode->next = newNode;

            ///  指向指向下一个节点
            currNode = newNode->next;
        }

        ///  接着复制随机指针域
        ///  原来节点的下一个位置就是其对应的新节点
        currNode = pHead;
        newNode = pHead->next;
        while(currNode != NULL)
        {
            RandomListNode *randNode = currNode->random;                        ///  随机指针域randNode
            RandomListNode *newNode = currNode->next;
            if(randNode != NULL)
            {

                newNode->random = randNode->next;

            }
            else
            {
                newNode->random = NULL;
            }
            ///  链表同步移动
            currNode = newNode->next;
        }

        /// 将链接在一起的新旧两个链表拆分开
        /// 脱链，更新各链表的next指针
        currNode = pHead;
        newNode = newHead = pHead->next;
        while(currNode != NULL)
        {
            /// curr  new new->next
            currNode->next = newNode->next;
            debug <<currNode->label <<", " <<newNode->label <<endl;
            if(newNode->next != NULL)
            {
                newNode->next = newNode->next->next;
            }
            else
            {
                newNode->next = NULL;
            }

            currNode = currNode->next;
            newNode = newNode->next;
        }

        return newHead;
    }

};






int __tmain( )
{

    RandomListNode list[4];
    list[0].label = 1;
    list[0].next = &list[1];
    list[1].label = 1;
    list[1].next = &list[2];
    list[2].label = 2;
    list[2].next = &list[3];
    list[3].label = 2;
    list[3].next = NULL;


    Solution solu;
    RandomListNode *head = solu.Clone(list);
    while(head != NULL)
    {
        cout <<head->label;
        head = head->next;
    }
    return 0;
}
