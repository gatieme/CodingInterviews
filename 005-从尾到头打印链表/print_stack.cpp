#include <iostream>

#include <stack>
#include <vector>

using namespace std;

//  调试开关
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
        ListNode *node = head;
        stack<int> st;
        int count = 0;
        while(node != NULL)
        {
            dout <<node->val <<"in stack" <<endl;
            st.push(node->val);

            count++;
            node = node->next;

        }

        //  为了效率我们静态vector开辟空间
        vector<int> res(count);
        dout <<"count = " <<count <<endl;
        for(int i = 0; i < count && st.empty( ) != true; i++)
        {
            dout <<st.top() <<"in vector" <<endl;
            // 如果静态开辟vector不能使用push_back
            // 否则会在原来数据的基础上增加
            //res.push_back(st.top( ));
            res[i] = st.top( );
            st.pop( );

        }

        return res;
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
