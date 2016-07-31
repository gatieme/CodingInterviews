#链接
-------
>牛客OJ：[两个链表的第一个公共结点](http://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46?tpId=13&tqId=11189&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
>
>九度OJ：http://ac.jobdu.com/problem.php?pid=1505
>
>GitHub代码： [037-两个链表的第一个公共结点](https://github.com/gatieme/CodingInterviews/tree/master/037-两个链表的第一个公共结点)
>
>CSDN题解：[剑指Offer--037-两个链表的第一个公共结点](http://blog.csdn.net/gatieme/article/details/51330871)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 |
| ------------- |:-------------:| -----:|
|[037-两个链表的第一个公共结点](http://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46?tpId=13&tqId=11189&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | [1505-两个链表的第一个公共结点](http://ac.jobdu.com/problem.php?pid=1505) | [剑指Offer--037-两个链表的第一个公共结点](http://blog.csdn.net/gatieme/article/details/51330871) | [037-两个链表的第一个公共结点](https://github.com/gatieme/CodingInterviews/tree/master/037-两个链表的第一个公共结点) |




<br>**您也可以选择[回到目录-剑指Offer--题集目录索引](http://blog.csdn.net/gatieme/article/details/51916802)**




#题意
-------

**题目描述**

>输入两个链表，找出它们的第一个公共结点。

#暴力方法
-------
最简单直接的方法就是，对于第一个链表的每个节点，我们依次判断其是不是第二条链表的公共结点
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
    ListNode* FindFirstCommonNode(ListNode *leftHead, ListNode *rightHead)
    {
        ListNode *left = NULL;
        ListNode *right = NULL;

        //  循环第一个链表的每个结点
        for(left = leftHead;
            left != NULL;
            left = left->next)
        {
            debug <<endl <<left->val <<" : ";

            //  依次判断其在不在第二条链表中
            for(right = rightHead;
                right != NULL;
                right = right->next)
            {
                debug <<right->val <<", ";
                if(left == right)
                {
                    break;
                }
            }
            if(left == right)
            {
                break;
            }
        }

        return left;
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
```

#右对齐两个链表
-------
如果两个链表有公共节点，则它们的形状必然是一个Y字形。



##长链表先走，实现右对齐


-------



先假设这两个链表的长度相等，则我们可以同步遍历这两个链表，找到公共节点。现在**有两个链表，我们可以先分别求齐长度得其差n，然后遍历长的那个链表n个节点，然后同步遍历这两个链表即可。**

```cpp
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
```



##将两个链表拼接起来实现右对齐

-------

前面那个思路中，长的链表先走一个长度差，从而保证两个链表是右对齐的，但是这种方式，我们需要多次扫面链表，因为链表必须通过扫描才能获取其长度



但是有没有不需要多次扫描就可将两个链表对齐的方法呢。



我们可以将两个链表拼接在一起来实现其

>left : left->right

>

>right : right->left



这样一来我们的链表就成了长度为$M+N$的两个链表，而公共部分都在最后，而且是对齐的



```cpp

class Solution
{
public:
    ListNode* FindFirstCommonNode(ListNode *leftHead, ListNode *rightHead)
    {
        ListNode *left= leftHead;
        ListNode *right = rightHead;

        debug <<(left == NULL ? -1 : left->val) <<", ";
        debug <<(right == NULL ? -1 : right->val) <<endl;


        while(left != right)
        {

            left = (left == NULL ? rightHead : left->next);
            right = (right == NULL ? leftHead : right->next);
            debug <<(left == NULL ? -1 : left->val) <<", ";
            debug <<(right == NULL ? -1 : right->val) <<endl;

        }
        return left;
    }
};
```



##栈的后进先出实现右对齐

-------

由于栈是后进先出的，因此我们将两个链表分别入栈，那么栈顶的元素一定是最后一个元素。从而两个链表是右对齐的，两个栈同步弹出，当两个栈顶的节点不相同时候，即是开始合并的前一个节点



```cpp
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
```



#利用高效的数据结构实现查找结点

-------



>当然还有其他思路，我们可以使用一个查找效率高的数据结构，比如hash或者map

>

>先将第一个链表插入，然后因此判断第二个链表的节点在不在map中，即可查找到第一个共同结点



利用unordered_map,这个模板类是基于hash表实现的，速度与map、hashmap相比较快

```cpp
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
```
