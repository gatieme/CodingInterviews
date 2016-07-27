#链接
------- 
>牛客OJ：[二叉搜索树与双向链表](http://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&tqId=11179&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
> 
>九度OJ：http://ac.jobdu.com/problem.php?pid=1503
> 
>GitHub代码： [027-二叉搜索树与双向链表](https://github.com/gatieme/CodingInterviews/tree/master/027-二叉搜索树与双向链表)
>
>CSDN题解：[剑指Offer--027-二叉搜索树与双向链表](http://blog.csdn.net/gatieme/article/details/51234524)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 | 
| ------------- |:-------------:| -----:| 
|[二叉搜索树与双向链表](http://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&tqId=11179&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | [1503-二叉搜索树与双向链表](http://ac.jobdu.com/problem.php?pid=1503) | [剑指Offer--027-二叉搜索树与双向链表](http://blog.csdn.net/gatieme/article/details/51234524) | [027-二叉搜索树与双向链表](https://github.com/gatieme/CodingInterviews/tree/master/027-二叉搜索树与双向链表) |


<br>**您也可以选择[回到目录-剑指Offer--题集目录索引](http://blog.csdn.net/gatieme/article/details/51916802)**




#题意
-------

**题目描述**


输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

#分析
-------
*    二叉排序树的每个节点均由两个指针指向其两个孩子，双向链表中每个节点又都有两个指针指向其前驱和后继



*    二叉排序树的左节点的值 < 根结点的值 < 右子节点的值，其中序遍历就是一个排序好的信息串



因此我们可以通过如下两种方法来实现
*    中序遍历来实现二叉搜索树向双向链表的转换，访问过程需修改为链接操作
*    把左子树和右子树都转换成排序的双向链表之后再和根节点链接起来，整棵二叉搜索树就转换成了排序的双向链表


#中序递归
-------

采用中序遍历，而中序遍历中当前结点的前一个节点

*    要么是当前结点的左子树的的最右孩子

*    要么是当前结点其前一个节点的右孩子

对于第二种，我们好判断，但是对于第一种方式，无法快速的找到其左子树的最右孩子，因此我们链接的时候需要保存其前驱节点，我们称之为lastNode节点

##用递归函数的参数保存lastNode节点
-------

在我们的递归函数中，我们用lastNode保存前一个访问的节点，我们采用中序访问的方式，将访问当前结点currNode的操作转换为将当前节点currNode与前一个节点lastNode链接成链表的方式。

由于我们每次需要更新lastNode的值，因为我们传递的参数是指向lastNode的指针pLastNode


```cpp
#include <iostream>

using namespace std;

//
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
//	TreeNode(int x)
//	:val(x), left(NULL), right(NULL)
//	{
//	}
};

#endif  //  __tmain

class Solution
{
public:
    /**
     * [Convert description]
     * @AuthorHTL
     * @DateTime  2016-04-23T21:02:08+0800
     * @param     pRootOfTree              [二叉排序树的根]
     * @return                             [转换成的链表的头结点]
     */
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL)
        {
            return NULL;
        }
        TreeNode *pLastNode = NULL;
        ConvertRecursion(pRootOfTree, &pLastNode);

        // 当递归结束后,*pLastNode指向了双向链表的尾结点
        TreeNode *node = pLastNode;
        while(pLastNode != NULL
           && pLastNode->left != NULL)
        {
           pLastNode = pLastNode->left;
        }

        return pLastNode;
    }

    /**
     * [ConvertRecursion 递归的将root为根的二叉排序树专户才能成双向链表]
     * @AuthorHTL
     * @DateTime  2016-04-23T22:33:00+0800
     * @param     root                     [当前递归的二叉排序树的根节点]
     * @param     pLastNode                [中序遍历中指向前一个节点的指针]
     */
    void ConvertRecursion(TreeNode *root, TreeNode **pLastNode)
    {
        if(root == NULL)
        {
            return;
        }
        TreeNode *currNode = root;

        //////////////////////////
        /// 首先中序 递归左子树
        //////////////////////////
        if(currNode->left != NULL)
        {
            ConvertRecursion(root->left, pLastNode);
        }


        //////////////////////////
        /// 接着中序开始访问根节点
        /// 在这里访问的过程演变为将左子树的根与根节点链接成一个链表
        //////////////////////////

        ///  开始链接左子树和当前根节点
        //  *pLastNode -=> currNode
        currNode->left = *pLastNode; //
        if(*pLastNode != NULL)
        {
            (*pLastNode)->right = currNode;
        }
        else
        {
            debug <<"lastNode is NULL" <<endl;
        }

        debug <<((*pLastNode == NULL) ? -1 : (*pLastNode)->val) <<", " <<currNode->val <<endl;
        system("PAUSE");
        //  更新上一个访问的指针域
        //  由于要更新前一个指针的指针域
        //  因此需要使用其指针来修改其指向
        *pLastNode = currNode;

        //  中序遍历
        if(currNode->right != NULL)
        {
            ConvertRecursion(currNode->right, pLastNode);
        }
    }
};



int __tmain( )
{
    //    4
    //  3   5
    //2
    TreeNode tree[4];
    tree[0].val = 4;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];
    tree[1].val = 3;
    tree[1].left = &tree[3];
    tree[1].right = NULL;
    tree[2].val = 5;
    tree[2].left = NULL;
    tree[2].right = NULL;
    tree[3].val = 2;
    tree[3].left = NULL;
    tree[3].right = NULL;


    Solution solu;
    TreeNode *head = solu.Convert(tree);
    while(head != NULL)
    {
        cout <<head->val <<" ";
        head = head->right;
    }
    return 0;
}
```

##递归的过程中，用static的error的问题
-------

>还记得[剑指Offer--025-二叉树中和为某一值的路径](http://blog.csdn.net/gatieme/article/details/51214182#t3)
中递归方法另外一种写法的时候，递归的参数path我们用了一个static的局部变量来存储，但是在这里我们的尝试没有成功，因为这里当一次转换完成，lastNode并没有被清掉，因此进行下一次转换之前我们的结果会跟上一次的结果串在一起

```cpp
#include <iostream>

using namespace std;

//
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
    /*

     TreeNode(int x)
	:val(x), left(NULL), right(NULL)
	{
	}*/
};

#endif  //  __tmain

class Solution
{
public:
    /**
     * [Convert description]
     * @AuthorHTL
     * @DateTime  2016-04-23T21:02:08+0800
     * @param     pRootOfTree              [二叉排序树的根]
     * @return                             [转换成的链表的头结点]
     */
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL)
        {
            return NULL;
        }
        TreeNode *pLastNode = ConvertRecursion(pRootOfTree);

        // 当递归结束后,*pLastNode指向了双向链表的尾结点
        TreeNode *node = pLastNode;
//        debug <<pLastNode->val <<endl;
        while(pLastNode != NULL
           && pLastNode->left != NULL)
        {
//            debug <<pLastNode->val <<" ";
            pLastNode = pLastNode->left;
        }

        return pLastNode;
    }

    /**
     * [ConvertRecursion 递归的将root为根的二叉排序树专户才能成双向链表]
     * @AuthorHTL
     * @DateTime  2016-04-23T22:33:00+0800
     * @param     root                     [当前递归的二叉排序树的根节点]
     * @param     pLastNode                [中序遍历中指向前一个节点的指针]
     */
    TreeNode* ConvertRecursion(TreeNode *root)
    {
        if(root == NULL)
        {
            return NULL;
        }
        TreeNode *currNode = root;
        static TreeNode *lastNode = NULL;
        //////////////////////////
        /// 首先中序 递归左子树
        //////////////////////////
        if(currNode->left != NULL)
        {
            lastNode = ConvertRecursion(root->left);
        }


        //////////////////////////
        /// 接着中序开始访问根节点
        /// 在这里访问的过程演变为将左子树的根与根节点链接成一个链表
        //////////////////////////

        ///  开始链接左子树和当前根节点
        //  *pLastNode -=> currNode
        currNode->left = lastNode; //
        if(lastNode != NULL)
        {
            lastNode->right = currNode;
        }
        else
        {
            debug <<"lastNode is NULL" <<endl;
        }
        debug <<((lastNode == NULL) ? -1 : lastNode->val) <<", " <<currNode->val <<endl;

        //  更新上一个访问的指针域
        //  由于要更新前一个指针的指针域
        //  因此需要使用其指针来修改其指向
        if(currNode != NULL)
        {
            lastNode = currNode;
        }
        //  中序遍历
        if(currNode->right != NULL)
        {
            lastNode = ConvertRecursion(currNode->right);
        }

        return lastNode;
    }
};



int __tmain( )
{
    //    4
    //  3
    //2
    TreeNode tree[3];
    tree[0].val = 4;
    tree[0].left = &tree[1];
    tree[0].right = NULL;
    tree[1].val = 3;
    tree[1].left = &tree[2];
    tree[1].right = NULL;
    tree[2].val = 2;
    tree[2].left = NULL;
    tree[2].right = NULL;


    Solution solu;
    TreeNode *head = solu.Convert(tree);
    while(head != NULL)
    {
        cout <<head->val <<" ";
        head = head->right;
    }



    TreeNode tree2[4];
    tree2[0].val = 4;
    tree2[0].left = &tree2[1];
    tree2[0].right = &tree2[2];
    tree2[1].val = 3;
    tree2[1].left = &tree2[3];
    tree2[1].right = NULL;
    tree2[2].val = 5;
    tree2[2].left = NULL;
    tree2[2].right = NULL;
    tree2[3].val = 2;
    tree2[3].left = NULL;
    tree2[3].right = NULL;

    Solution solu2;
    head = solu2.Convert(tree2);
    while(head != NULL)
    {
        cout <<head->val <<" ";
        head = head->right;
    }
    return 0;
}

```

>当然关于这个问题，我们也有其他的解决方法，比如将lastnode保存成一个成员对象
>
>但是我们通过参数保存的方法，这种方式更具有一般性，对于那些面向过程性的语言，也能更好的移植



##非递归中序遍历实现
-------

用栈来模拟递归栈我们实现中序遍历的非递归版本，

将输出的过程更改为双向链表的链接，主要是将前驱节点preNode和当前访问节点currNode链接起来，这个时候需要注意的是第一个节点的处理（head的前驱节点为NULL）

```cpp
class Solution
{
public:

    TreeNode* Convert(TreeNode* root)
    {
        if(root == NULL)
        {
            debug <<"The tree is NULL..." <<endl;
        }

        stack<TreeNode *> nstack;
        TreeNode *currNode = root;
        TreeNode *preNode = NULL;
        TreeNode *head = NULL;

        //  开始遍历整个二叉树
        while(currNode != NULL || nstack.empty() != true)
        {
            // 不输出当前根节点，但是递归直至当前根节点node的最左端
            while(currNode != NULL)
            {
                nstack.push(currNode);
                currNode = currNode->left;
            }

            //  此时栈顶的元素是当前最左元素
            //  它应该被输出
            if(nstack.empty( ) != true)
            {
                currNode = nstack.top( );
                debug <<currNode->val;
                nstack.pop( );
                
                //  第一个节点
                if(preNode == NULL)
                {
                    head = currNode;
                    preNode = currNode;
                }
                else
                {
                    preNode->right = currNode;
                    currNode->left = preNode;
                    preNode = currNode;
                }
                currNode = currNode->right;

            }
        }
        return head;
    }
};
```

#递归将左右子树变换为链表后，将他们与根链接成链表
-------

这个算法的流程就是

1  递归root左子树，并且与root与左子树链接起来

*    递归将root的左子树变换为双向链表，并且返回左子树根在链表中的位置节点

*    通过左子树的根的最后的最右子节点，即左子树链表的最后一个节点是root的前驱

2  递归root右子树，并且与root与右子树链接起来

*    递归将root的右子树变换为双向链表，并且返回左子树根在链表中的位置节点

*    通过右子树的根的最后的最左子节点，即右子树链表的第一个节点是root的后继

```cpp
#include <iostream>

using namespace std;

//
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
//	TreeNode(int x)
//	:val(x), left(NULL), right(NULL)
//	{
//	}
};

#endif  //  __tmain

class Solution
{
public:
    /**
     * [Convert description]
     * @AuthorHTL
     * @DateTime  2016-04-23T21:02:08+0800
     * @param     pRootOfTree              [二叉排序树的根]
     * @return                             [转换成的链表的头结点]
     */
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL)
        {
            return NULL;
        }
        TreeNode *pLastNode = ConvertRecursion(pRootOfTree);

        // 当递归结束后,*pLastNode指向了双向链表的尾结点
        TreeNode *node = pLastNode;
        while(pLastNode != NULL
           && pLastNode->left != NULL)
        {
           pLastNode = pLastNode->left;
        }

        return pLastNode;
    }

    /**
     * [ConvertRecursion 递归的将root为根的二叉排序树专户才能成双向链表]
     * @AuthorHTL
     * @DateTime  2016-04-23T22:33:00+0800
     * @param     root                     [当前递归的二叉排序树的根节点]
     */
    TreeNode* ConvertRecursion(TreeNode *root)
    {
        if(root == NULL)
        {
            debug <<"NULL" <<endl;
            return NULL;
        }

        //////////////////////////
        /// 首先 递归左子树
        //////////////////////////
        TreeNode *lastNode = NULL;
        if(root->left != NULL)
        {
            ///  递归将左子树转换为双向链表, 并且返回左子树的根节点
            lastNode = ConvertRecursion(root->left);

            //  递归左子树完成后
            //  lastNode节点指向了左子树的根节点
            //  但是root的前驱应该是原来左子树的最右子节点, 即转换成链表的最后一个节点,
            while(lastNode != NULL && lastNode->right != NULL)
            {
                lastNode = lastNode->right;
            }

            root->left = lastNode; //
            lastNode->right = root;     ///  无需判断lastNode是否为NULL, 因为我们的函数为root = NULL的是不进行递归的
            debug <<lastNode->val <<", " <<root->val <<endl;

        }


        //////////////////////////
        /// 接着 递归右子树
        //////////////////////////
        TreeNode *nextNode = NULL;
        if(root->right != NULL)
        {
            //  递归将左子树转换为双向链表, 并且返回左子树的根节点
            nextNode = ConvertRecursion(root->right);

            //  递归左子树完成后
            //  lastNode节点应该是其左子树的最右节点
            //  即转换成链表的最后一个节点
            while(nextNode->left != NULL)
            {
                nextNode = nextNode->left;
            }
            nextNode->left = root;
            root->right = nextNode;
            debug <<root->val <<", " <<nextNode->val <<endl;
        }

        return root;
    }
};



int __tmain( )
{
    //    4
    //  3   5
    //2
    TreeNode tree[4];
    tree[0].val = 4;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];
    tree[1].val = 3;
    tree[1].left = &tree[3];
    tree[1].right = NULL;
    tree[2].val = 5;
    tree[2].left = NULL;
    tree[2].right = NULL;
    tree[3].val = 2;
    tree[3].left = NULL;
    tree[3].right = NULL;


    Solution solu;
    TreeNode *head = solu.Convert(tree);
    while(head != NULL)
    {
        cout <<head->val <<" ";
        head = head->right;
    }
    return 0;
}
```
