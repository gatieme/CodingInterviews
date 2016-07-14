
#1    链接
-------

>牛客OJ：[二叉搜索树的第K个结点](http://www.nowcoder.com/practice/ef068f602dde4d28aab2b210e859150a?tpId=13&tqId=11215&rp=4)
> 
>九度OJ：未收录
> 
>GitHub代码： [063-二叉搜索树的第K个结点](https://github.com/gatieme/CodingInterviews/tree/master/063-二叉搜索树的第K个结点)
>
>CSDN题解：[剑指Offer--063-二叉搜索树的第K个结点](http://blog.csdn.net/gatieme/article/details/51902530)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 | 
| ------------- |:-------------:| -----:| -----:|
|[063-二叉搜索树的第K个结点](http://www.nowcoder.com/practice/ef068f602dde4d28aab2b210e859150a?tpId=13&tqId=11215&rp=4) | 未收录 | [剑指Offer--063-二叉搜索树的第K个结点](http://blog.csdn.net/gatieme/article/details/51902530) | [063-二叉搜索树的第K个结点](https://github.com/gatieme/CodingInterviews/tree/master/063-二叉搜索树的第K个结点) |

#2    题意
-------

**题目描述**
>给定一颗二叉搜索树，请找出其中的第k大的结点。

例如， 
     5 
    /  \ 
   3    7 
   /\     /\
 2  4  6 8   中
按结点数值大小顺序第三个结点的值为4


#3  分析
-------

二叉搜索树的中序遍历正好是一个递增的序列, 因此中序遍历的第K个结点就是二叉搜索树的第K个节点


#4  中序递归版本
-------

```c
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

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x = 0)
    :val(x), left(NULL), right(NULL) {
    }
};
#endif

class Solution
{
    unsigned int count = 0;
public:
    TreeNode* KthNode(TreeNode* root, unsigned int K)
    {
        if(root == NULL)
        {
            return NULL;
        }
        TreeNode *ret = NULL;


        if((ret = KthNode(root->left, K)) != NULL)
        {
            return ret;
        }
        ++count;
        debug <<"count = " <<count <<", value = " <<root->val <<endl;
        if(count == K)
        {
            return root;
        }
        
        if((ret = KthNode(root->right, K)) != NULL)
        {
            return ret;
        }
        return NULL;
    }
};


int __tmain( )
{
    TreeNode tree[7];

    tree[0].val = 5;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];

    tree[1].val = 3;
    tree[1].left = &tree[3];
    tree[1].right = &tree[4];

    tree[2].val = 7;
    tree[2].left = &tree[5];
    tree[2].right = &tree[6];

    tree[3].val = 2;
    tree[3].left = NULL;
    tree[3].right = NULL;

    tree[4].val = 4;
    tree[4].left = NULL;
    tree[4].right = NULL;

    tree[5].val = 6;
    tree[5].left = NULL;
    tree[5].right = NULL;

    tree[6].val = 8;
    tree[6].left = NULL;
    tree[6].right = NULL;

    Solution solu;
    TreeNode *res = NULL;
    if((res = solu.KthNode(tree, 3)) != NULL)
    {
        cout <<res->val <<endl;
    }
    else
    {
        cout <<"null node" <<endl;
    }
    return 0;
}
```


#5  中序非递归版本
-------

>中序遍历的非递归的算法
>
>可以参见[二叉树的遍历详解（前序中序后序层次-递归和非递归）](http://blog.csdn.net/gatieme/article/details/51163010)


根据中序遍历的顺序，对于任一结点，优先访问其左孩子，而左孩子结点又可以看做一根结点，然后继续访问其左孩子结点，直到遇到左孩子结点为空的结点才进行访问，然后按相同的规则访问其右子树。

*   从根节点开始，开始遍历

*   递归输出直至最左，然后输出（中序先输出左孩子，而中序遍历第一个输出的是其最左叶子节点）

*   当到达最左节点的时候，访问右节点

因此其处理过程如下：

1.  对于任一结点P，

2.  若其左孩子不为空，则将P入栈并将P的左孩子置为当前的P，然后对当前结点P再进行相同的处理；

3.  若其左孩子为空，则取栈顶元素并进行出栈操作，访问该栈顶结点，然后将当前的P置为栈顶结点的右孩子；

4.  直到P为NULL并且栈为空则遍历结束

```c
class Solution
{
    unsigned int count = 0;
public:
    /*  中序与前序的区别在于
     *  前序在递归至最左的时候就会输出递归的节点, 因此先输出根，然后是左
     *  但是中序在递归至最左时，弹栈时才输出, 因此先输出最左，再输出根
     */
    TreeNode* KthNode(TreeNode *root, unsigned int K)
    {
        if(root == NULL)
        {
            debug <<"The tree is NULL..." <<endl;
            return NULL;
        }

        stack<TreeNode *> nstack;
        TreeNode *node = root;

        //  开始遍历整个二叉树
        while(node != NULL || nstack.empty() != true)
        {
            // 不输出当前根节点，但是递归直至当前根节点node的最左端
            while(node != NULL)
            {
                nstack.push(node);
                node = node->left;
            }

            //  此时栈顶的元素是当前最左元素
            //  它应该被输出
            if(nstack.empty( ) != true)
            {
                node = nstack.top( );
                debug <<node->val <<endl;
                count++;
                if(count == K)
                {
                    return node;
                }
                nstack.pop( );
                node = node->right;
            }
        }
        return NULL;
    }
};
```
