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

#endif      //      #endif  __tmain

class Solution
{
public:
    ListNode* FindFirstCommonNode(ListNode *leftHead, ListNode *rightHead)
    {
        ListNode *left = leftHead;
        ListNode *right = rightHead;
        int leftLength = 0;
        int rightLength = 0;

        ///  首先计算两个链表的长度
        leftLength = GetListLength(left);
        rightLength = GetListLength(right);

        ///  对齐两个链表
        int length = 0;

        if(leftLength < rightLength)
        {
            // 右链表长
            length = rightLength - leftLength;
            while(right != NULL && length > 0)
            {
                right = right->next;
                length--;
            }
        }
        else
        {
            // 左链表长
            length = leftLength - rightLength;
            while(left != NULL && length > 0)
            {
                left = left->next;
                length--;
            }
        }

        //  两个指针同步移动即可找到共同的结点
        while(left != NULL && right != NULL)
        {
            if(left == right)
            {
                break;
            }
            left = left->next;
            right = right->next;
        }

        return ((left == right) ? left : NULL);
    }

    int GetListLength(ListNode *head)
    {
        ListNode *node = head;
        int length = 0;
        while(node != NULL)
        {
            length++;
            node = node->next;
        }

        return length;
    }
};

int __tmain( )
{
    ListNode common[2];
    common[0].val = 6;
    common[0].next = &common[1];
    common[1].val = 7;
    common[1].next = NULL;

    ListNode left[3];
    left[0].val = 1;
    left[0].next = &left[1];
    left[1].val = 2;
    left[1].next = &left[2];
    left[2].val = 3;
    left[2].next = &common[0];

    ListNode right[2];
    right[0].val = 4;
    right[0].next = &right[1];
    right[1].val = 5;
    right[1].next = &common[0];

    Solution solu;
    ListNode *node = solu.FindFirstCommonNode(left, right);
    while(node != NULL)
    {
        debug <<node->val <<" ";
        node = node->next;
    }
    debug <<endl;

    return 0;
}
