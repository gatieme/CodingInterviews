#include <iostream>
#include <map>


using namespace std;


//  µ÷ÊÔ¿ª¹Ø
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


#endif      //  #endif  __tmain


class Solution
{
public:
    ListNode* FindFirstCommonNode(ListNode *leftHead, ListNode *rightHead)
    {
        unordered_map<ListNode*, bool> umap;

        ListNode* left = leftHead;
        while (left != NULL)
        {
            umap.insert(make_pair(left, 1 ));
            left = left->next;
        }

        ListNode* right = rightHead;
        while (right)
        {
            if (umap.count(right)>0)
            {
                return right;
            }
            right = right->next;
        }
        return NULL;
    }
};

int __tmain( )
{
    ListNode common[2];
    common[0].val = 6;
    common[0].next = &common[1];
    common[1].val = 7;
    common[1].next = NULL;

    ListNode leftHead[3];
    leftHead[0].val = 1;
    leftHead[0].next = &leftHead[1];
    leftHead[1].val = 2;
    leftHead[1].next = &leftHead[2];
    leftHead[2].val = 3;
    leftHead[2].next = &common[0];

    ListNode right[2];
    right[0].val = 4;
    right[0].next = &right[1];
    right[1].val = 5;
    right[1].next = &common[0];

    Solution solu;
    ListNode *node = solu.FindFirstCommonNode(leftHead, right);
    while(node != NULL)
    {
        debug <<node->val <<" ";
        node = node->next;
    }
    debug <<endl;

    return 0;
}
