#链接
------- 
>牛客OJ：[对称的二叉树](http://www.nowcoder.com/practice/ff05d44dfdb04e1d83bdbdab320efbcb?tpId=13&tqId=11211&rp=3&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
>
>九度OJ：未收录
>
>GitHub代码： [059-对称的二叉树](https://github.com/gatieme/CodingInterviews/tree/master/059-对称的二叉树)
>
>CSDN题解：[剑指Offer--059-对称的二叉树](http://blog.csdn.net/gatieme/article/details/51620587)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 |
| ------------- |:-------------:| -----:| -----:|
|[059-对称的二叉树](http://www.nowcoder.com/practice/ff05d44dfdb04e1d83bdbdab320efbcb?tpId=13&tqId=11211&rp=3&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | 未收录 | [剑指Offer--059-对称的二叉树](http://blog.csdn.net/gatieme/article/details/51620587) | [059-对称的二叉树](https://github.com/gatieme/CodingInterviews/tree/master/059-对称的二叉树) |

#题意
-------

**题目描述**

>请实现一个函数，用来判断一颗二叉树是不是对称的。
>
>注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的


#分析
-------

左右子树同时遍历，若出现不一致，则说明不对称

二叉树是否对称的本质，其实是判定两棵树是否镜像

即响应对的位置的节点是否对应相等


##递归实现
-------

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

struct TreeNode
{
    int                 val;
    struct TreeNode     *left;
    struct TreeNode     *right;

    TreeNode(int x = 0)
    :val(x), left(NULL), right(NULL)
    {
    }
};

#endif


class Solution
{
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot == NULL)
        {
            return true;   
        }
        return isSymmetricalRecursion(pRoot->left, pRoot->right);
    }

    bool isSymmetricalRecursion(TreeNode *pLeft, TreeNode *pRight)
    {
        if(pLeft == NULL && pRight == NULL)
        {
            return true;
        }
        
        if(pLeft == NULL || pRight == NULL)
        {
            return false;
        }
        
        if(pLeft->val != pRight->val)
        {
            return false;
        }

        //  左子树的左与右子树的右对称
        //  左子树的右与右子树的左对称
        return isSymmetricalRecursion(pLeft->left, pRight->right) 
            && isSymmetricalRecursion(pLeft->right, pRight->left);
    }
};

int __tmain( )
{


    TreeNode tree[7];

    tree[0].val = 8;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];

    
    tree[1].val = 6;
    tree[1].left = &tree[3];
    tree[1].right = &tree[4];

    
    tree[2].val = 6;
    tree[2].left = &tree[5];
    tree[2].right = &tree[6];

    
    tree[3].val = 5;
    tree[3].left = NULL;
    tree[3].right = NULL;
    
    tree[4].val = 7;
    tree[4].left = NULL;
    tree[4].right = NULL;
    
    tree[5].val = 7;
    tree[5].left = NULL;
    tree[5].right = NULL;
    
    tree[6].val = 5;
    tree[6].left = NULL;
    tree[6].right = NULL;


    Solution solu;
    cout <<solu.isSymmetrical(tree) <<endl;
    return 0;
}
```


##非递归
-------


我的方法其实还是很常规，用栈来代替。

因为是对称比较，所以要两个栈。
这个思路其实可以稍微简化一下，改用一个双端队列deque实现。比起用两个栈来，显得稍微新颖一些



```cpp
class Solution
{
public:
    bool isSymmetrical(TreeNode *root)
    {
        if(root == NULL)
        {
            return true;
        }

        if(root->left == NULL 
        && root->right == NULL)
        {
            return true;
        }
        if((root->left == NULL && root->right != NULL)
        || (root->left != NULL && root->right == NULL))
        {
            return false;
        }

        deque< TreeNode * > dq;
        dq.push_front(root->left);
        dq.push_back(root->right);

        while(dq.empty( ) != true)
        {
            TreeNode* lroot = dq.front();
            TreeNode* rroot = dq.back();
            dq.pop_front();
            dq.pop_back();
        
            if(lroot -> val != rroot -> val)
            {
                return false;
            }

            if((lroot->right == NULL && rroot->left != NULL)
            || (lroot->right != NULL && rroot->left == NULL))
            {
                return false;
            }

            if(lroot->right != NULL)
            {
                dq.push_front(lroot->right);
                dq.push_back(rroot->left);
            }

            if((lroot->left == NULL && rroot->right != NULL)
            || (lroot->left != NULL && rroot->right == NULL))
            {
                return false;
            }

            if(lroot->left != NULL)
            {
                dq.push_front(lroot->left);
                dq.push_back(rroot->right);
            }
        }
        return true;
    }
};
```