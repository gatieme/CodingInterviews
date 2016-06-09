#链接
------- 
>牛客OJ：[把二叉树打印成多行](http://www.nowcoder.com/practice/445c44d982d04483b04a54f298796288?tpId=13&tqId=11213&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
> 
>九度OJ：未收录
> 
>GitHub代码： [060-把二叉树打印成多行](https://github.com/gatieme/CodingInterviews/tree/master/060-把二叉树打印成多行)
>
>CSDN题解：[剑指Offer--060-把二叉树打印成多行](http://blog.csdn.net/gatieme/article/details/51622025)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 |
| ------------- |:-------------:| -----:| -----:|
|[060-把二叉树打印成多行](http://www.nowcoder.com/practice/445c44d982d04483b04a54f298796288?tpId=13&tqId=11213&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking) | 未收录 | [剑指Offer--060-把二叉树打印成多行](http://blog.csdn.net/gatieme/article/details/51622025) | [060-把二叉树打印成多行](https://github.com/gatieme/CodingInterviews/tree/master/060-把二叉树打印成多行) |

#题意
-------

**题目描述**

>请实现一个函数，用来判断一颗二叉树是不是对称的。
>
>注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的


#分析
-------

其实就是层次遍历，这个我们在我之前的一篇博客里面将的很清楚了

>[二叉树的遍历详解（前序中序后序层次-递归和非递归）](http://blog.csdn.net/gatieme/article/details/51163010#t10)
>
>[剑指Offer--023-从上往下打印二叉树（层次遍历二叉树）](http://blog.csdn.net/gatieme/article/details/51204976)

其中调试的时候使用了

>[剑指Offer--006-重构二叉树](http://blog.csdn.net/gatieme/article/details/51108612)来辅助我们通过前序和中序遍历的序列来生成二叉树

直接贴代码，只需要直接将我们层次遍历输出过程，变成将输入压入vector中即可


#代码
-------

```cpp
#include <iostream>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain


#define undebug 0 && cout


#ifdef __tmain
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;

	TreeNode(int x = 0)
	:val(x), left(NULL), right(NULL)
    {
	}
};
#endif // __tmain



class Solution
{
    vector< vector<int> >   res;
    vector<int>             curr;
public:
    vector< vector<int> > Print(TreeNode *root)
    {
        LevelOrder(root);

        LevelOrderDev(root);

        LevelOrderUsePoint(root);

        LevelOrderUseSize(root);

        LevelOrderUseEnd(root);
        return this->res;
    }

    int PrintLevel(TreeNode *root, int level)
    {
        if(root == NULL || level < 0)
        {
            return 0;
        }
        else if(level == 0)
        {
            debug <<root->val;
            curr.push_back(root->val);        /// add for currult in vector

            return 1;
        }
        else
        {
            return PrintLevel(root->left, level - 1) + PrintLevel(root->right, level - 1);
        }
    }

    void LevelOrder(TreeNode *root)
    {
        curr.clear( );           /// add for currult in vector
        res.clear( );
        if(root == NULL)
        {
            return;
        }
        for(int level = 0; ; level++)
        {
            if(PrintLevel(root, level) == 0)
            {
                break;
            }
            res.push_back(curr);
            curr.clear( );
            debug <<endl;
        }
    }

    //////////////////////////
    //////////////////////////
    void LevelOrderDev(TreeNode *root)
    {
        curr.clear( );           /// add for currult in vector
        res.clear( );

        if(root == NULL)
        {
            return ;
        }
        deque<TreeNode *> qFirst, qSecond;
        qFirst.push_back(root);

        while(qFirst.empty( ) != true)
        {
            while (qFirst.empty( ) != true)
            {
                TreeNode *temp = qFirst.front( );
                qFirst.pop_front( );

                debug << temp->val;
                curr.push_back(temp->val);        /// add for currult in vector


                if (temp->left != NULL)
                {
                    qSecond.push_back(temp->left);
                }
                if (temp->right != NULL)
                {
                    qSecond.push_back(temp->right);
                }
            }
            debug << endl;
            res.push_back(curr);
            curr.clear( );

            qFirst.swap(qSecond);

        }
    }


    //////////////////////////
    //////////////////////////
    void LevelOrderUsePoint(TreeNode *root)
    {
        curr.clear( );           /// add for currult in vector
        res.clear( );
        if(root == NULL)
        {
            return ;
        }
        
        vector<TreeNode*> vec;
        vec.push_back(root);

        int cur = 0;
        int end = 1;

        while (cur < vec.size())
        {
            end = vec.size();

            while (cur < end)
            {
                debug << vec[cur]->val;
                curr.push_back(vec[cur]->val);        /// add for currult in vector

                if (vec[cur]->left != NULL)
                {
                    vec.push_back(vec[cur]->left);

                }
                if (vec[cur]->right != NULL)
                {
                    vec.push_back(vec[cur]->right);
                }
                cur++;
            }
            res.push_back(curr);
            curr.clear( );
            debug << endl;
        }
    }



    void LevelOrderUseSize(TreeNode *root)
    {
        curr.clear( );           /// add for currult in vector
        res.clear( );
        if(root == NULL)
        {
            return ;
        }

        int parentSize = 1, childSize = 0;
        TreeNode *temp = NULL;

        queue<TreeNode *> q;
        q.push(root);
        while(q.empty( ) != true)
        {
            temp = q.front( );
            debug <<temp->val;
            curr.push_back(temp->val);        /// add for currult in vector

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
                res.push_back(curr);
                curr.clear( );
                debug << endl;
            }

        }
    }


    void LevelOrderUseEnd(TreeNode *root)
    {
        curr.clear( );           /// add for currult in vector
        res.clear( );
        if(root == NULL)
        {
            return ;
        }

        queue<TreeNode *> q;

        q.push(root);
        q.push(NULL);

        while(q.empty( ) != true)
        {
            TreeNode* node = q.front();
            q.pop();

            if (node)
            {
                debug <<node->val;
                curr.push_back(node->val);        /// add for currult in vector

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

                res.push_back(curr);
                curr.clear( );
                debug << endl;
            }
        }
        if(curr.size() != 0)
        {
            res.push_back(curr);
            curr.clear( );
            cout <<endl;
        }
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
    vector< vector<int> > res = solu.Print(tree);
    for(int i = 0; i < res.size( ); i++)
    {
        for(int j = 0; j < res[i].size( ); j++)
        {
            cout <<res[i][j];
        }
        cout <<endl;
    }

    return 0;
}
```