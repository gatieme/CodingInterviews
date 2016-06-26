#链接
------- 
>牛客OJ：[按之字形顺序打印二叉树](http://www.nowcoder.com/practice/91b69814117f4e8097390d107d2efbe0?tpId=13&tqId=11212&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
> 
>九度OJ：未收录
> 
>GitHub代码： [061-按之字形顺序打印二叉树](https://github.com/gatieme/CodingInterviews/tree/master/061-按之字形顺序打印二叉树)
>
>CSDN题解：[剑指Offer--061-按之字形顺序打印二叉树](http://blog.csdn.net/gatieme/article/details/51763476)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 |
| ------------- |:-------------:| -----:| -----:|
|[061-按之字形顺序打印二叉树](http://www.nowcoder.com/practice/91b69814117f4e8097390d107d2efbe0?tpId=13&tqId=11212&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking) | 未收录 | [剑指Offer--061-按之字形顺序打印二叉树](http://blog.csdn.net/gatieme/article/details/51763476) | [061-按之字形顺序打印二叉树](https://github.com/gatieme/CodingInterviews/tree/master/061-按之字形顺序打印二叉树) |

#题意
-------

**题目描述**

请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。


关于层次遍历，这个我们在我之前的几篇博客里面都讲的很清楚了

>[二叉树的遍历详解（前序中序后序层次-递归和非递归）](http://blog.csdn.net/gatieme/article/details/51163010#t10)
>
>[剑指Offer--023-从上往下打印二叉树（层次遍历二叉树）](http://blog.csdn.net/gatieme/article/details/51204976)
>
>[剑指Offer--060-把二叉树打印成多行](http://blog.csdn.net/gatieme/article/details/51622025)

#层次遍历后结果之按字输出
-------


其实我们可以借鉴层次遍历时候的思路, 参见[剑指Offer--060-把二叉树打印成多行](http://blog.csdn.net/gatieme/article/details/51622025), 我们把层次遍历的结果保存在vector< vector<int> >中每一层保存在一个vector中, 那么我们输出的时候就可以进行调整, 按照之字形输出即可
```c
        for(int i = 0; i <ans.size( ); i++)
        {
            if(i & 1)
            {
                reverse(ans[i].begin( ), ans[i].end( ));
            }
        }
        return ans;
```

完整代码如下, 其中LevelOrder可以被替换成其他的层次遍历的方法, 这里我们就不详细讲了

```c
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain


#define undebug 0 && cout


#ifdef __tmain

struct TreeNode {
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
public:
    vector< vector<int> > ans;

    void LevelOrder(TreeNode *pRoot,int p )
    {
        if(pRoot == NULL)
        {
            return;

        }
        if(ans.size( ) == p)
        {
            ans.push_back(vector<int>( ));
        }

        ans[p].push_back(pRoot->val);

        LevelOrder(pRoot->left, p + 1);
        LevelOrder(pRoot->right, p + 1);

    }

    vector< vector<int> > Print(TreeNode* pRoot)
    {
        LevelOrder(pRoot,0);

        for(int i = 0; i <ans.size( ); i++)
        {
            if(i & 1)
            {
                reverse(ans[i].begin( ), ans[i].end( ));
            }
        }
        return ans;
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


    tree[2].val = 10;
    tree[2].left = &tree[5];
    tree[2].right = &tree[6];


    tree[3].val = 5;
    tree[3].left = NULL;
    tree[3].right = NULL;

    tree[4].val = 7;
    tree[4].left = NULL;
    tree[4].right = NULL;

    tree[5].val = 9;
    tree[5].left = NULL;
    tree[5].right = NULL;

    tree[6].val = 11;
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

#层次遍历用双端队列存储

上面那种方法是在层次遍历完成后的输出过程进行转换，这种处理对于海量数据就很鸡肋了

当然我们也可以在层次遍历的过程中就行转换，在层次遍历遍历的过程中, 将元素的输出顺序即插入顺序与其层数相关联


我们之前提到过, 层次遍历右多种方法, 我们可以在

1.    对二叉树进行层次遍历, 设置一个标识层数或者遍历顺序

2.    处理每层的元素的时候, 按照遍历顺序进行从前往后遍历或者从后往前遍历


那么为了更好的处理, 我们其实可以有很多种方法, 由于要双向遍历, 那么我们就用双端队列deque存储最为方便

*    用双端队列进行, 双向遍历,奇数层时从前向后遍历，偶数层时从后向前遍历

关于层次遍历的方法我们这里不再详述，　我们这里采用的方式是在每层的结束插入一个特殊标识(NULL), 来表示一层的结束

当然可以有其他方法, 但是基本思路相同, 而且层次遍历只是本题的一部分, 关键是如何实现之字访问

```c
class Solution
{
public:
    vector<vector<int> > Print(TreeNode* pRoot)
    {
        vector< vector<int> > ret;
        if(pRoot == NULL)
        {
            return ret;
        }
        vector<int> curr;
        deque<TreeNode *> deq;
        deq.push_back(NULL);//层分隔符
        deq.push_back(pRoot);
        bool leftToRight = true;

        while (deq.size( ) != 1)
        {
            TreeNode* node = deq.front( );
            deq.pop_front();

            if(node == NULL)    //  到达每层分隔符
            {
                if (leftToRight == true)    //  从前完后遍历
                {
                    deque<TreeNode *>::iterator iter;
                    for(iter = deq.begin( );
                        iter != deq.end( );
                        iter++)
                    {
                        curr.push_back((*iter)->val);
                    }
                }
                else                        //  从后往前遍历
                {
                    deque<TreeNode *>::reverse_iterator riter;
                    for(riter = deq.rbegin( );
                        riter < deq.rend( );
                        riter++)
                    {
                        curr.push_back((*riter)->val);
                    }
                }
                leftToRight = !leftToRight;

                ret.push_back(curr);
                curr.clear();
                deq.push_back(NULL);//添加层分隔符
                continue;//一定要continue
            }
            if (node->left != NULL)
            {
                deq.push_back(node->left);
            }
            if (node->right != NULL)
            {
                deq.push_back(node->right);
            }
        }
        return ret;
    }
};
```


#层次遍历双栈模拟顺序逆序
-------

也可以用两个栈来保存节点的每一层, 

*    一个实现先进先出，即入栈顺序为右子节点、左子节点

*    一个实现后进先出，即入栈顺序为左子节点、右子节点

```c
class Solution
{
public:

    vector< vector<int> > Print(TreeNode* pRoot)
    {
        vector< vector<int> > res;

        if(pRoot == NULL)
        {
            return res;
        }
        vector<int> curr;

        stack<TreeNode *> levels[2];
        #define LEFT_TO_RIGHT 1 //  先左后右访问, 意味着先右后左入栈
        #define RIGHT_TO_LEFT 0 //  先右后左访问, 意味着先左后右入栈

        int current = LEFT_TO_RIGHT;  
        int next = RIGHT_TO_LEFT;
        levels[current].push(pRoot);

        while(levels[LEFT_TO_RIGHT].empty( ) != true 
           || levels[RIGHT_TO_LEFT].empty( ) != true)
        {
            TreeNode *pNode = levels[current].top( );
            levels[current].pop( );

            curr.push_back(pNode->val);

            /*  当前层次current是先左后右访问
             *  则下一层次应该先右后左访问
             *  即next从左往右入栈
             */
            if(current == LEFT_TO_RIGHT)  
            {
                if(pNode->left != NULL)
                {
                    levels[next].push(pNode->left);
                }
                if(pNode->right != NULL)
                {
                    levels[next].push(pNode->right);
                }
            }
            else                //  先右后左入栈
            {

                if(pNode->right != NULL)
                {
                    levels[next].push(pNode->right);
                }
                if(pNode->left != NULL)
                {
                    levels[next].push(pNode->left);
                }
            }

            if(levels[current].empty( ) == true)
            {
                res.push_back(curr);
                curr.clear( );
                current =  1 - current;
                next = 1 - next;
            }
        }

        return res;
    }
};
```
