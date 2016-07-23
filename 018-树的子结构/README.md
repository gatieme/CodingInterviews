#链接
------- 

>牛客OJ：[树的子结构](http://www.nowcoder.com/practice/6e196c44c7004d15b1610b9afca8bd88?tpId=13&tqId=11170&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
> 
>九度OJ：http://ac.jobdu.com/problem.php?pid=1520
> 
>GitHub代码： [018-树的子结构](https://github.com/gatieme/CodingInterviews/tree/master/018-树的子结构)
>
>CSDN题解：[剑指Offer--018-树的子结构](http://blog.csdn.net/gatieme/article/details/51151916)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 | 
| ------------- |:-------------:| -----:| 
|[树的子结构](http://www.nowcoder.com/practice/6e196c44c7004d15b1610b9afca8bd88?tpId=13&tqId=11170&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking) | [1520-树的子结构](http://ac.jobdu.com/problem.php?pid=1520) | [剑指Offer--018-树的子结构](http://blog.csdn.net/gatieme/article/details/51151916) | [018-树的子结构](https://github.com/gatieme/CodingInterviews/tree/master/018-树的子结构)|


<br>**您也可以选择[回到目录-剑指Offer--题集目录索引](http://blog.csdn.net/gatieme/article/details/51916802)**




#题意

-------

**题目描述**


>输入两颗二叉树A，B，判断B是不是A的子结构。

#分析
-------

要查找树A中是否存在和树B结构一样的子树，可以分成两步：
1.第一步在树A中找到和B的根节点的值一样的结点R；
这实际上就是树的遍历。可以用递归实现

递归调用HasSubTree遍历二叉树A。如果发现某一结点的值和树B的头结点的值相同，则转向第2步判断两个结点为根的数是否存在父子关系

2.第二步再判断树A中以R为根结点的子树是不是包含和树B一样的结构。
这个过程其实就是要要判断两棵树对应的节点数据是否相同。这个是一个递归的过程。

首先我们先实现第2步的操作，这个操作其实就是递归判断两个树对应节是否相同，
递归的终结是如果之前的节点均相同，最后子树为空时，而父树如果也是NULL，则说明两颗树完全一样，如果父树不是NULL，则子树是父树的一部分
```cpp
    bool DoesParentHaveChild(TreeNode *parent, TreeNode *child)
    {
        if(child == NULL)      //  子树为NULL，那么必然是子树
        {
            return true;
        }
        else if(parent == NULL)      //  子树不是NULL, 但是父亲树是NULL
        {
            return false;
        }

        //  两个节点的值不相等，那么两个树必然不是父子关系
        if(parent->val != child->val)
        {
            return false;
        }
        else      // 否则当前节点当前相等，则递归的判断左子树和右子树对应节点是否相同
        {

            return DoesParentHaveChild(parent->left, child->left)
                && DoesParentHaveChild(parent->right, child->right);
        }
    }
```


然后是我们的第一步，查找父树中是否有某个节点是子树的根节点相同
```cpp

    bool HasSubtree(TreeNode* parent, TreeNode* child)
    {
        if(child == NULL)
        {
            return false;
        }
        else if(parent == NULL)
        {
            return false;
        }



        bool result;

        //  如果当前父树的节点与子树的根节点相同，则直接从父树的当前位置开始判定
        if(parent->val == child->val)
        {
            result = DoesParentHaveChild(parent, child);
        }

        if(result != true)
        {
            return HasSubtree(parent->left, child)
            || HasSubtree(parent->right, child);
        }
        else
        {
            return true;
        }

    }

```





#代码

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
	int val;
	struct TreeNode *left;
	struct TreeNode *right;

	TreeNode(int x) :
			val(x), left(NULL), right(NULL)
    {

	}
};
#endif // __tmain

class Solution {
public:
    bool HasSubtree(TreeNode* parent, TreeNode* child)
    {
        if(child == NULL || parent == NULL)
        {
            return false;
        }

        bool result;
        //  如果当前父树的节点与子树的根节点相同，则直接从父树的当前位置开始判定
        if(parent->val == child->val)
        {
            result = DoesParentHaveChild(parent, child);
        }
        if(result != true)
        {
            return HasSubtree(parent->left, child)      //  从左子树查找
            || HasSubtree(parent->right, child);        //  从右子树中查找
        }
        else
        {
            return true;
        }

    }

    bool DoesParentHaveChild(TreeNode *parent, TreeNode *child)
    {
        if(child == NULL)      //  子树为NULL，那么必然是子树
        {
            return true;
        }
        else if(parent == NULL)      //  子树不是NULL, 但是父亲树是NULL
        {
            return false;
        }

        //  两个节点的值不相等，那么两个树必然不是父子关系
        if(parent->val != child->val)
        {
            return false;
        }
        else      // 否则当前节点当前相等，则递归的判断左子树和右子树对应节点是否相同
        {

            return DoesParentHaveChild(parent->left, child->left)
                && DoesParentHaveChild(parent->right, child->right);
        }
    }
};

int __tmain( )
{
    debug <<"test" <<endl;
    return 0;
}




```
