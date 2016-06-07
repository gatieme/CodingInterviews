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
