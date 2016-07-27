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
