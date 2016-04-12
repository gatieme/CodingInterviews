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
