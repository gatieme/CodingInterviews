#链接
------- 
>牛客OJ：[二叉树中和为某一值的路径](http://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?tpId=13&tqId=11177&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
> 
>九度OJ：http://ac.jobdu.com/problem.php?pid=1368
> 
>GitHub代码： [025-二叉树中和为某一值的路径](https://github.com/gatieme/CodingInterviews/tree/master/025-二叉树中和为某一值的路径)
>
>CSDN题解：[剑指Offer--025-二叉树中和为某一值的路径](http://blog.csdn.net/gatieme/article/details/51214182)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 | 
| ------------- |:-------------:| -----:| 
|[二叉树中和为某一值的路径](http://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?tpId=13&tqId=11177&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | [1368-二叉树中和为某一值的路径](http://ac.jobdu.com/problem.php?pid=1368) | [剑指Offer--025-二叉树中和为某一值的路径](http://blog.csdn.net/gatieme/article/details/51214182) | [025-二叉树中和为某一值的路径](https://github.com/gatieme/CodingInterviews/tree/master/025-二叉树中和为某一值的路径) |

#题意
-------

**题目描述**

>输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径

#分析
-------

思路还是比较好想的，用个递归来实现，先序遍历，
*    每次访问一个节点，那么就将当前权值求和
*    如果当前权值和与期待的和一致，那么说明我们找到了一个路径，保存或者输出
*    否则的话就递归其左右孩子节点
这里需要注意一个问题，就是递归退出的时候，权值和的信息是保存在递归栈中的会恢复，但是我们保存的路径是无法恢复的，那么我们就需要在递归返回时将数据弹出
```cpp
#include <iostream>
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
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x)
	:val(x), left(NULL), right(NULL)
    {
	}
};

#endif // __tmain

class Solution
{
public:
    vector< vector<int> > m_res;

    vector< vector<int> > FindPath(TreeNode* root, int expectNumber)
    {
        if(root == NULL)
        {
            return m_res;
        }
        vector<int> path;
        FindPath(root, expectNumber, path, 0);

        return m_res;
    }

    void FindPath(TreeNode* root, int expectNumber, vector<int> path, int currentSum)
    {
        currentSum += root->val;
        path.push_back(root->val);

        ///
        if(currentSum == expectNumber
        && ((root->left == NULL && root->right == NULL)))
        {
            debug <<"find a path" <<endl;
            for(int i = 0; i < path.size( ); i++)
            {
                debug <<path[i] <<" ";
            }
            debug <<endl;

            m_res.push_back(path);
        }

        if(root->left != NULL)
        {
            FindPath(root->left, expectNumber, path, currentSum);
        }
        if(root->right != NULL)
        {
            FindPath(root->right, expectNumber, path, currentSum);
        }

        ///
        path.pop_back( );
    }

};


int __tmain( )
{
    debug <<"test" <<endl;
    return 0;
}
```
