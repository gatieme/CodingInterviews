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
    int                 val;
    struct TreeNode     *left;
    struct TreeNode     *right;

    TreeNode(int x = 0)
    :val(x), left(NULL), right(NULL)
    {
    }
};

#endif


class Solution
{
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot == NULL)
        {
            return true;   
        }
        return isSymmetricalRecursion(pRoot->left, pRoot->right);
    }

    bool isSymmetricalRecursion(TreeNode *pLeft, TreeNode *pRight)
    {
        if(pLeft == NULL && pRight == NULL)
        {
            return true;
        }
        
        if(pLeft == NULL || pRight == NULL)
        {
            return false;
        }
        
        if(pLeft->val != pRight->val)
        {
            return false;
        }

        //  左子树的左与右子树的右对称
        //  左子树的右与右子树的左对称
        return isSymmetricalRecursion(pLeft->left, pRight->right) 
            && isSymmetricalRecursion(pLeft->right, pRight->left);
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
    cout <<solu.isSymmetrical(tree) <<endl;
    return 0;
}
