#include <iostream>

#include <stack>
#include <vector>

using namespace std;

//  µ÷ÊÔ¿ª¹Ø
#define __tmain main

#ifdef __tmain

#define dout cout

#else

#define dout 0 && cout

#endif // __tmain



#ifdef __tmain

struct ListNode
{
public :
    int val;
    struct ListNode *next;

    /*ListNode(int x) :
    val(x), next(NULL)
    {
    }*/
};

#endif // __tmain


/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution
{
public:
    vector<int> printListFromTailToHead(struct ListNode* head)
    {

        vector<int> res;
        printListFromTailToHeadRecursion(head, res);
        return res;
    }


    void printListFromTailToHeadRecursion(struct ListNode* head, vector<int> &res)
    {
        if(head != NULL)
        {
            printListFromTailToHeadRecursion(head->next, res);
            res.push_back(head->val);
        }
    }
};





int __tmain( )
{
    ListNode list[4];
    list[0].val = 1;
    list[0].next = &list[1];
    list[1].val = 2;
    list[1].next = &list[2];
    list[2].val = 3;
    list[2].next = &list[3];
    list[3].val = 4;
    list[3].next = NULL;



    Solution solu;
    vector<int> res = solu.printListFromTailToHead(list);

    cout <<"there are " <<res.size( ) <<"datas in vector" <<endl;
    for(int i = 0; i < res.size( ); i++)
    {
        cout <<res[i] <<endl;
    }
    return 0;
}
