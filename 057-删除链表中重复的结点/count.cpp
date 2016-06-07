#include <iostream>

using namespace std;


//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain


#ifdef  __tmain

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x = 0)
    :
        val(x), next(NULL) {
    }
};
#endif //   __tmain


class Solution
{
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode h(-1);
        ListNode *newNode = &h;
        ListNode *preNode = NULL;
        ListNode *oldNode = pHead;
        int cnt;

        while(oldNode != NULL)
        {
            preNode = oldNode;
            oldNode = oldNode->next;
            cnt = 0;

            // 对preNode出现的次数进行计数
            while(oldNode && oldNode->val == preNode->val)
            {
                oldNode = oldNode->next;
                ++cnt;
            }

            //  如果preNode出现了0次
            if(cnt == 0)
            {
                //  把preNode链接到了newNode的末尾
                newNode->next = preNode;
                newNode = preNode;
            }
        }
        newNode->next = NULL;
        return h.next;
    }

};


int __tmain( )
{
    Solution solu;

    ListNode list[7];

    list[0].val = 1;
    list[0].next = &list[1];

    list[1].val = 2;
    list[1].next = &list[2];

    list[2].val = 3;
    list[2].next = &list[3];

    list[3].val = 3;
    list[3].next = &list[4];

    list[4].val = 4;
    list[4].next = &list[5];

    list[5].val = 4;
    list[5].next = &list[6];

    list[6].val = 5;
    list[6].next = NULL;


    ListNode* node = solu.deleteDuplication(list);

    while(node != NULL)
    {
        cout <<node->val <<" -=> ";
        node = node->next;
    }
    return 0;
}
