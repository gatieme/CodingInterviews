#链接
------- 
>牛客OJ：[删除链表中重复的结点](http://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?tpId=13&tqId=11209&rp=3&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
> 
>九度OJ：未收录
> 
>GitHub代码： [057-删除链表中重复的结点](https://github.com/gatieme/CodingInterviews/tree/master/057-删除链表中重复的结点)
>
>CSDN题解：[剑指Offer--057-删除链表中重复的结点](http://blog.csdn.net/gatieme/article/details/51604199)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 | 
| ------------- |:-------------:| -----:|
|[057-删除链表中重复的结点](http://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?tpId=13&tqId=11209&rp=3&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | 未收录 | [剑指Offer--057-删除链表中重复的结点](http://blog.csdn.net/gatieme/article/details/51604199) | [057-删除链表中重复的结点](https://github.com/gatieme/CodingInterviews/tree/master/057-删除链表中重复的结点) |

#题意
-------

**题目描述**

>在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 

例如，链表1->2->3->3->4->4->5 

处理后为 1->2->5


#代码
-------

我们的思路是，

1.    我们每次都判断当前结点的值与下一个节点的值是否重复
2.    如果重复就循环寻找下一个不重复的节点，　将他们链接新新链表的尾部（其实就是删除重复的节点）

```cpp
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
        //设置一个trick, 作为头指针, 这样我们无需单独考虑第一个元素
        ListNode *first = new ListNode(-1);

        first->next = pHead;

        ListNode *p = pHead;
        ListNode *last = first;

        while (p != NULL && p->next != NULL)
        {
            debug <<p->val <<endl;

            //  如果有元素重复
            if (p->val == p->next->val)
            {
                //  就跳过所有重复的数字
                int val = p->val;
                while (p != NULL && p->val == val)
                {
                    p = p->next;
                }

                //  此时p指向了非重复的第一个元素
                //  我们设置last->next = p
                //  但是此时p-val也可能是重复的,
                //  因此我们不可以设置last = p
                //  而是重新进入循环
                last->next = p;
            }
            else
            {
                last = p;
                p = p->next;
            }
        }
        return first->next;
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


    ListNode *node = solu.deleteDuplication(list);

    while(node != NULL)
    {
        cout <<node->val <<" -=> ";
        node = node->next;
    }
    return 0;
}
```


#计数法
-------

当前我们也可以对每个元素重复的次数进行技计数，如果当前结点没有重复出现在链表中，就加入新链表

```cpp
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
```