#include <iostream>
#include <stack>


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

#endif  //  #endif  __tmain



class Solution
{
public:
    ListNode* FindFirstCommonNode(ListNode *leftHead, ListNode *rightHead)
    {
        ListNode *left = leftHead;
        ListNode *right = rightHead;

        stack<ListNode *> leftStack;
        stack<ListNode *> rightStack;

        /// 结点依次入栈
        while(left != NULL)
        {
            //debug <<left->val <<endl;
            leftStack.push(left);
            left = left->next;
        }

        while(right != NULL)
        {
            //debug <<right->val <<endl;
            rightStack.push(right);
            right = right->next;
        }

        ///  开始同步弹出元素
        while(leftStack.empty( ) != true
           && rightStack.empty( ) != true)
        {
            left = leftStack.top( );
            right = rightStack.top( );

            debug <<left->val <<", " <<right->val <<endl;

            ///  不相同的元素就是合并的前一个结点
            if(left != right)
            {
                break;
            }
            leftStack.pop( );
            rightStack.pop( );
        }

        ///  不相同元素的下一个结点就是共同结点
        if(left != right)
        {
            return left->next;
        }
        else
        {
            return NULL;
        }
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
