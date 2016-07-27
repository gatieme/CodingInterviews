#链接
------- 


>牛客OJ：[二叉树中和为某一值的路径](http://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?tpId=13&tqId=11177&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
> 
>九度OJ：http://ac.jobdu.com/problem.php?pid=1368
> 
>GitHub代码： [025-二叉树中和为某一值的路径](https://github.com/gatieme/CodingInterviews/tree/master/025-二叉树中和为某一值的路径)
>
>CSDN题解：[剑指Offer--025-二叉树中和为某一值的路径](http://blog.csdn.net/gatieme/article/details/51214182)


| 牛客OJ | 九度OJ  | CSDN题解 | GitHub代码 | 
| ------ |:-------:| --------:|:----------:|
|[二叉树中和为某一值的路径](http://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?tpId=13&tqId=11177&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | [1368-二叉树中和为某一值的路径](http://ac.jobdu.com/problem.php?pid=1368) | [剑指Offer--025-二叉树中和为某一值的路径](http://blog.csdn.net/gatieme/article/details/51214182) | [025-二叉树中和为某一值的路径](https://github.com/gatieme/CodingInterviews/tree/master/025-二叉树中和为某一值的路径) |



<br>**您也可以选择[回到目录-剑指Offer--题集目录索引](http://blog.csdn.net/gatieme/article/details/51916802)**



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

        //  此处不需要恢复currentSum和path的值:                                  
        //  因为currentSum作为参数在函数递归调用返回时会自动恢复                 
        //  而如果作为静态局部变量存储则需要进行恢复                             
        //currentSum -= root->val;                                               
       //path.pop_back( );      
    }

};
```

或者
```c
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
        FindPathRecursion(root, expectNumber);

        return m_res;
    }

    void FindPathRecursion(TreeNode* root, int expectNumber)
    {
        static int currentSum = 0;
        static vector<int> path;

        currentSum += root->val;
        path.push_back(root->val);
        debug <<"currentSum = " <<currentSum - root->val <<", now get " <<root->val <<", currentSum = "<<currentSum <<endl;
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
            FindPathRecursion(root->left, expectNumber);
        }
        if(root->right != NULL)
        {
            FindPathRecursion(root->right, expectNumber);
        }

        debug <<"currentSum = " <<currentSum <<", now pop " <<*(path.end( ) - 1)  <<", currentSum = "<<currentSum - root->val<<endl;
        //  作为静态变量存储需要恢复现场
        currentSum -= root->val;
        path.pop_back( );
    }

};
```

#另外一种写法
-------
*    前面我们是求和，当然也可以用递减的方式
*    结果我们保存在数据成员里面，我们肯定也可以用传参的方式实现
*    单次的路径path原来是通过参数保存在栈中的，也可以用static来保存

>在递归的过程中，用static的变量保存path参数的信息，用于这个变量在函数的静态生存周期内部，因此这种方法有个致命的缺点
>
>*  所有的对象共享这个函数，当多个对象同时操作的时候，path变量只有一个副本，因此线程不安全。
>
>*  如果在函数结束的时候，path变量没有被清空，那么即使不是多线程共享访问，两个对象顺序的访问这个对象，依然会造成根共享访问同样的问题
>
>我们会在解决第27题的过程中，就会体会到这个问题
>
>[剑指Offer--027-二叉搜索树与双向链表](http://blog.csdn.net/gatieme/article/details/51234524)


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
//  TreeNode(int x)
//  :val(x), left(NULL), right(NULL)
//    {
//  }
};

#endif // __tmain

class Solution
{
public:

    vector< vector<int> > FindPath(TreeNode* root, int expectNumber)
    {
        vector< vector<int> > res;

        if(root == NULL)
        {
            return res;
        }
        FindPath(root, expectNumber, res);

        return res;
    }
protected :
    void FindPath(TreeNode* root, int leftSum, vector< vector<int> > &res)
    {
        if(root == NULL)
        {
            return;
        }

        /// 用一个静态的变量来存储路径
        static vector<int> path;

        leftSum -= root->val;
        path.push_back(root->val);

        ///
        if(leftSum == 0
        && ((root->left == NULL && root->right == NULL)))
        {
            debug <<"find a path" <<endl;
            for(int i = 0; i < path.size( ); i++)
            {
                debug <<path[i] <<" ";
            }
            debug <<endl;

            res.push_back(path);
            cout <<"size = " <<res.size( ) <<endl;
        }
        else
        {

            if(root->left != NULL)
            {
                FindPath(root->left, leftSum, res);
            }

            if(root->right != NULL)
            {
                FindPath(root->right, leftSum, res);
            }
        }
        leftSum += root->val;
        path.pop_back( );
    }

};


int __tmain( )
{
    //  0  1  2  3 4
    //  {10,5,12,4,7},22
    TreeNode tree[5];
    tree[0].val = 10;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];

    tree[1].val = 5;
    tree[1].left = &tree[3];
    tree[1].right = &tree[4];

    tree[2].val = 12;
    tree[2].left = NULL;
    tree[2].right = NULL;

    tree[3].val = 4;
    tree[3].left = NULL;
    tree[3].right = NULL;

    tree[4].val = 7;
    tree[4].left = NULL;
    tree[4].right = NULL;

    Solution solu;
    vector< vector<int> > res = solu.FindPath(&tree[0], 15);
    cout <<"size = " <<res.size( ) <<endl;
    for(int i = 0; i < res.size( ); i++)
    {
        for(int j = 0; j < res[i].size( ); j++)
        {
            cout <<res[i][j] <<" ";
        }
        cout <<endl;
    }

    return 0;
}
```
