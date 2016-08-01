#链接
-------
>牛客OJ：[二叉树的深度](http://www.nowcoder.com/practice/435fb86331474282a3499955f0a41e8b?tpId=13&tqId=11191&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
>
>九度OJ：http://ac.jobdu.com/problem.php?pid=1350
>
>GitHub代码： [039-二叉树的深度](https://github.com/gatieme/CodingInterviews/tree/master/039-二叉树的深度)
>
>CSDN题解：[剑指Offer--039-二叉树的深度](http://blog.csdn.net/gatieme/article/details/51339884)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 |
| ------------- |:-------------:| -----:|
|[039-二叉树的深度](http://www.nowcoder.com/practice/435fb86331474282a3499955f0a41e8b?tpId=13&tqId=11191&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | [1350-二叉树的深度](http://ac.jobdu.com/problem.php?pid=1350) | [剑指Offer--039-二叉树的深度](http://blog.csdn.net/gatieme/article/details/51339884) | [039-二叉树的深度](https://github.com/gatieme/CodingInterviews/tree/master/039-二叉树的深度) |




, <br>**您也可以选择[回到目录-剑指Offer--题集目录索引](http://blog.csdn.net/gatieme/article/details/51916802)**



#题意
-------

**题目描述**

>输入一棵二叉树，求该树的深度。
>
>从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。







#分析
-------

对二叉树进行层次遍历，维护一个层数计数器，每次进入一层就增加1，从而得到二叉树的层数。
当然如果使用递归的话，思路就更简单了，返回左右子树中深度最大的那个

层次遍历的代码，我们前面已经将了很多了，这里就不再啰嗦了，需要的统计可以参见我的另外几篇博客
[二叉树的遍历详解（前序中序后序层次-递归和非递归）](http://blog.csdn.net/gatieme/article/details/51163010)
[剑指Offer--023-从上往下打印二叉树（层次遍历二叉树）](http://blog.csdn.net/gatieme/article/details/51204976)

但是递归的思路稍有不同，因此要返回层数，那么我们就返回左右子树中深度最大的那个
```cpp
class Solution
{
public:
    int TreeDepth(TreeNode* root)
    {
        return TreeDepth(root, 0);
    }

	/// 递归方法一
    int TreeDepthRecursion(TreeNode *root)
    {
        if(root == NULL)
        {
            return 0;
        }
        else
        {
            int leftDepth = TreeDepthRecursion(root->left);
            int rightDepth = TreeDepthRecursion(root->right);

            return max(leftDepth, rightDepth) + 1;
        }
    }
	///  递归方法二
    int TreeDepthRecursion(TreeNode *root, int depth)
    {
        if(root == NULL)
        {
            return depth;
        }
        else
        {
            int leftDepth = TreeDepthRecursion(root->left, depth + 1);
            int rightDepth = TreeDepthRecursion(root->right, depth + 1);

            return max(leftDepth, rightDepth);
        }
    }
};
```

然后还有其他非递归的方法，最后完整的代码如下
```cpp
#include <iostream>
#include <deque>
#include <queue>
#include <vector>

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

#endif  // __tmain


class Solution
{
public:
    int TreeDepth(TreeNode* root)
    {
        return TreeDepthRecursion(root);
        //return TreeDepthRecursion(root, 0);
        //return LevelOrderDev(tree);
        //return LevelOrderUseEnd(tree);
        //return LevelOrderUseSize(tree);
        //return LevelOrderUsePoint(tree);
    }

    int TreeDepthRecursion(TreeNode *root)
    {
        if(root == NULL)
        {
            return 0;
        }
        else
        {
            int leftDepth = TreeDepthRecursion(root->left);
            int rightDepth = TreeDepthRecursion(root->right);

            return max(leftDepth, rightDepth) + 1;
        }
    }


    int TreeDepthRecursion(TreeNode *root, int depth)
    {
        if(root == NULL)
        {
            return depth;
        }
        else
        {
            int leftDepth = TreeDepthRecursion(root->left, depth + 1);
            int rightDepth = TreeDepthRecursion(root->right, depth + 1);

            return max(leftDepth, rightDepth);
        }
    }


    int LevelOrderDev(TreeNode *root)
    {
        /// deque双端队列，
        /// 支持迭代器，有push_back()方法，
        /// 跟vector差不多，比vector多了个pop_front,push_front方法
        int count = 0;
        deque<TreeNode *> qFirst, qSecond;
        qFirst.push_back(root);

        while(qFirst.empty( ) != true)
        {
            while (qFirst.empty( ) != true)
            {
                TreeNode *temp = qFirst.front( );
                qFirst.pop_front( );

                cout << temp->val;

                if (temp->left != NULL)
                {
                    qSecond.push_back(temp->left);
                }
                if (temp->right != NULL)
                {
                    qSecond.push_back(temp->right);
                }
            }
            cout << endl;
            count++;
            qFirst.swap(qSecond);

        }

        return count;
    }


    int LevelOrderUsePoint(TreeNode *root)
    {
        vector<TreeNode*> vec;
        vec.push_back(root);

        int cur = 0;
        int end = 1;
        int count = 0;

        while (cur < vec.size())
        {
            end = vec.size();       ///  新的一行访问开始，重新定位last于当前行最后一个节点的下一个位置

            while (cur < end)
            {
                cout << vec[cur]->val;  ///  访问节点

                if (vec[cur]->left != NULL) ///  压入左节点
                {
                    vec.push_back(vec[cur]->left);

                }
                if (vec[cur]->right != NULL)    ///  压入右节点
                {
                    vec.push_back(vec[cur]->right);
                }
                cur++;
            }
            cout << endl;
            count++;
        }

        return count;
    }

    int LevelOrderUseSize(TreeNode *root)
    {
        int count = 0;

        int parentSize = 1, childSize = 0;
        TreeNode *temp = NULL;

        queue<TreeNode *> q;
        q.push(root);
        while(q.empty( ) != true)
        {
            temp = q.front( );
            cout <<temp->val;

            q.pop( );

            if (temp->left != NULL)
            {
                q.push(temp->left);

                childSize++;
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
                childSize++;
            }

            parentSize--;
            if (parentSize == 0)
            {
                parentSize = childSize;
                childSize = 0;
                cout << endl;
                count++;
            }

        }

        return count;
    }

    int LevelOrderUseEnd(TreeNode *root)
    {
        int count = 0;

        queue<TreeNode *> q;

        q.push(root);
        q.push(NULL);

        while(q.empty( ) != true)
        {
            TreeNode* node = q.front();
            q.pop();

            if (node)
            {
                cout << node->val;

                if (node->left != NULL)
                {
                    q.push(node->left);
                }
                if (node->right != NULL)
                {
                    q.push(node->right);
                }
            }
            else if (q.empty( ) != true)
            {
                q.push(NULL);
                cout << endl;
                count++;
            }
        }

        return count;
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
    cout <<solu.TreeDepth(tree) <<endl;

    cout <<solu.LevelOrderDev(tree) <<endl;

    cout <<solu.LevelOrderUseEnd(tree) <<endl;

    cout <<solu.LevelOrderUseSize(tree) <<endl;

    cout <<solu.LevelOrderUsePoint(tree) <<endl;

    return 0;
}
```
