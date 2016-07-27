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
