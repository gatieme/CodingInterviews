#include <iostream>

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
#endif


class Solution
{
public:
    ListNode* FindFirstCommonNode( ListNode *left, ListNode *right)
    {
    }
};

int __tmain( )
{
    return 0;
}
