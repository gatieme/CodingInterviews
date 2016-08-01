#链接
------- 
>牛客OJ：[平衡二叉树](http://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222?tpId=13&tqId=11192&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
> 
>九度OJ：未收录
> 
>GitHub代码： [039-平衡二叉树](https://github.com/gatieme/CodingInterviews/tree/master/039-平衡二叉树%5B附加%5D)
>
>CSDN题解：[剑指Offer--039-平衡二叉树](http://blog.csdn.net/gatieme/article/details/51346422)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 | 
| ------ |:------:| --------:|:----------:|
|[039-平衡二叉树](http://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222?tpId=13&tqId=11192&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | 未收录 | [剑指Offer--039-平衡二叉树](http://blog.csdn.net/gatieme/article/details/51346422) | [039-平衡二叉树](https://github.com/gatieme/CodingInterviews/tree/master/039-平衡二叉树%5B附加%5D) |



<br>**您也可以选择[回到目录-剑指Offer--题集目录索引](http://blog.csdn.net/gatieme/article/details/51916802)**




#题意
-------

**题目描述**

>输入一棵二叉树，判断该二叉树是否是平衡二叉树。


#递归法
-------

根据平衡二叉树的定义

平衡二叉树要求对于每一个节点来说，它的左右子树的高度之差不能超过1

因此我们递归的判断每一个根节点，判断左右子树的高度差

##递归得到二叉树的深度
-------

首先得到二叉树的深度
```cpp
int TreeDepth(TreeNode *root)
{
    if(root == NULL)
    {
    return 0;
    }

    int leftDepth = TreeDepth(root->left);
    int rightDepth = TreeDepth(root->right);

    //  返回左右子树中深度最深的
    return max(leftDepth, rightDepth) + 1;
}
```

下面我们递归的判断每个节点的左右子树是否满足平衡条件
```cpp
bool IsBalanced_Solution(TreeNode* root)
{
    if(root == NULL)
    {
        return true;
    }

    int leftDepth = TreeDepth(root->left);
    int rightDepth = TreeDepth(root->right);

    if(fabs(leftDepth - rightDepth) <= 1)
    {
        return IsBalanced_Solution(root->left) && IsBalanced_Solution(root->right);
    }
    else
    {
        return false;
    }
}
```

##完整代码
-------


完整代码如下

```cpp
#include <iostream>
#include <cmath>

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
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#endif //   __tmain

class Solution
{
public:
    bool IsBalanced_Solution(TreeNode* root)
    {
        if(root == NULL)
        {
            return true;
        }

        int leftDepth = TreeDepth(root->left);
        int rightDepth = TreeDepth(root->right);

        if(fabs(leftDepth - rightDepth) <= 1)
        {
            return IsBalanced_Solution(root->left) && IsBalanced_Solution(root->right);
        }
        else
        {
            return false;
        }
    }

    int TreeDepth(TreeNode *root)
    {
        if(root == NULL)
        {
            return 0;
        }

        int leftDepth = TreeDepth(root->left);
        int rightDepth = TreeDepth(root->right);

        //  返回左右子树中深度最深的
        return max(leftDepth, rightDepth) + 1;
    }
};


int __tmain( )
{
//     0
//   1   2
// 3   
    TreeNode tree[4];
    
    tree[0].val = 0;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];

    tree[1].val = 1;
    tree[1].left = &tree[3];
    tree[1].right = NULL;

    tree[2].val = 2;
    tree[2].left = NULL;
    tree[2].right = NULL;


    tree[3].val = 3;
    tree[3].left = NULL;
    tree[3].right = NULL;
    
    Solution solu;
    cout <<solu.IsBalanced_Solution(tree) <<endl;
    
    return 0;
}
```

但是这个递归法有很大缺陷，在求该结点的的左右子树深度时遍历一遍树，再次判断子树的平衡性时又遍历一遍树结构，造成遍历多次。

有没有方法一边遍历树一边判断每个结点是否具有平衡性。


#递归改进（边遍历边判断）
-------

我们在递归的过程中用depth来保存层数，然后递归的过程中同步遍历


```cpp
class Solution
{
public:    
    ///  递归的过程中同步判断平衡性
    bool IsVALWithDepth(TreeNode *root, int *depth)
    {
        if(root == NULL)
        {
            *depth = 0;
            return true;
        }

        int leftDepth, rightDepth;

        bool left = IsVALWithDepth(root->left, &leftDepth);
        bool right = IsVALWithDepth(root->right, &rightDepth);

        if(left == true && right == true)
        {
            if(fabs(leftDepth - rightDepth) <= 1)
            {
                *depth = max(leftDepth, rightDepth) + 1;

                debug <<"depth = " <<*depth <<endl;

                return true;
            }
        }

        return false;
    }

};
```
