#链接
------- 

>牛客OJ：[合并两个排序的链表](http://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=13&tqId=11169&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
> 
>九度OJ：http://ac.jobdu.com/problem.php?pid=1519
> 
>GitHub代码： [017-合并两个排序的链表](https://github.com/gatieme/CodingInterviews/tree/master/017-合并两个排序的链表)
>
>CSDN题解：[剑指Offer--017-合并两个排序的链表](http://blog.csdn.net/gatieme/article/details/51138298)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 | 
| ------------- |:-------------:| -----:| 
|[合并两个排序的链表](http://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=13&tqId=11169&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | [1519-合并两个排序的链表](http://ac.jobdu.com/problem.php?pid=1518) | [剑指Offer--017-合并两个排序的链表](http://blog.csdn.net/gatieme/article/details/51138298) | [017-合并两个排序的链表](https://github.com/gatieme/CodingInterviews/tree/master/017-合并两个排序的链表)|


>其实这道题跟LeetCode上一道题是一样的

>[LeetCodet题解--21. Merge Two Sorted Lists（合并两个排序好的链表）](http://blog.csdn.net/gatieme/article/details/51094742)
>
>当然他还有很多变种，比如说两个链表扩展成为K个的时候
>
>[LeetCodet题解--23. Merge k Sorted Lists（合并K个已排序的链表）](http://blog.csdn.net/gatieme/article/details/51097730)


<br>**您也可以选择[回到目录-剑指Offer--题集目录索引](http://blog.csdn.net/gatieme/article/details/51916802)**



#题意
-------

**题目描述**

输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

**样例输入**

>1 3 5 7 9
>2 4

**样例输出**

>1 2 3 4 5 7 9


#常规写法
-------

思路很简单，用两个指针同步遍历两个链表，每次找到小的那个插入到新的链表中

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
//	ListNode(int x)
//	:val(x), next(NULL)
//    {
//	}
};

#endif // __tmain

class Solution
{
public:
    ListNode* Merge(ListNode *pLeft, ListNode *pRight)
    {

        if(pLeft == NULL)
        {
            debug <<"left list is NULL" <<endl;
            return pRight;
        }
        else if(pRight == NULL)
        {
            debug <<"right list is NULL" <<endl;
            return pLeft;
        }

        ListNode *left = pLeft;
        ListNode *right = pRight;

        //  先生成头结点
        ListNode *head = NULL;
        if(left->val < right->val)
        {
            head = left;
            left = left->next;
            debug <<head->val <<"in list" <<endl;
        }
        else
        {
            head = right;
            right = right->next;
            debug <<head->val <<"in list" <<endl;
        }

        //  遍历两个链表
        ListNode *curr = head;

        while(left != NULL && right != NULL)
        {
            //  每次找到一个小的加入新的链表
            debug <<"left = " <<left->val <<", right = " <<right->val <<endl;

            if(left->val < right->val)
            {
                debug <<left->val <<"in list" <<endl;

                curr->next = left;
                curr = curr->next;

                left = left->next;
            }
            else
            {
                debug <<right->val <<"in list" <<endl;

                curr->next = right;
                curr = curr->next;

                right = right->next;
            }
        }

        //  处理较长链表的剩余部分
        if(left != NULL)
        {
            curr->next = left;
        }
        else
        {
            curr->next = right;
        }


        return head;

    }
};

int __tmain( )
{
    ListNode left, right[3];

    left.val = 5;
    left.next = NULL;

    right[0].val = 1;
    right[0].next = &right[1];
    right[1].val = 2;
    right[1].next = &right[2];
    right[2].val = 4;
    right[2].next = NULL;


    Solution solu;
    ListNode *head = solu.Merge(&left, right);
    while(head != NULL)
    {
        cout <<head->val;
        head = head->next;
    }


    return 0;
}

```


#递归实现
-------

其实思路一样，只是由于每次添加节点，都是机械性地重复工作，因此可以用递归来实现

```cpp

class Solution
{
public:
    ListNode* Merge(ListNode *pLeft, ListNode *pRight)
    {

        if(pLeft == NULL)
        {
            debug <<"left list is NULL" <<endl;
            return pRight;
        }
        else if(pRight == NULL)
        {
            debug <<"right list is NULL" <<endl;
            return pLeft;
        }

        ListNode *head = NULL;

        if(pLeft->val < pRight->val)
        {
            head = pLeft;
            head->next = Merge(pLeft->next, pRight);
        }
        else
        {
            head = pRight;
            head->next = Merge(pLeft, pRight->next);
        }

        return head;
    }
};


```

其实这道题跟LeetCode上一道题是一样的

[LeetCodet题解--21. Merge Two Sorted Lists（合并两个排序好的链表）](http://blog.csdn.net/gatieme/article/details/51094742)

当然他还有很多变种，比如说两个链表扩展成为K个的时候
 
[LeetCodet题解--23. Merge k Sorted Lists（合并K个已排序的链表）](http://blog.csdn.net/gatieme/article/details/51097730)
