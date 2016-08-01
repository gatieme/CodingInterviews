#include <iostream>
#include <cmath>


using namespace std;



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

#endif //   __tmain


class Solution
{
public:
    bool IsBalanced_Solution(TreeNode* root)
    {
        int depth;
        return IsVALWithDepth(root, &depth);
    }

    bool IsVAL(TreeNode *root)
    {
        if(root == NULL)
        {
            return true;
        }

        int leftDepth = TreeDepth(root->left);
        int rightDepth = TreeDepth(root->right);

        if(fabs(leftDepth - rightDepth) <= 1)
        {
            return IsBalanced_Solution(root->left) && IsBalanced_Solution(root->right);
        }
        else
        {
            return false;
        }
    }

    int TreeDepth(TreeNode *root)
    {
        if(root == NULL)
        {
            return 0;
        }

        int leftDepth = TreeDepth(root->left);
        int rightDepth = TreeDepth(root->right);

        return max(leftDepth, rightDepth) + 1;
    }

    ///  递归的过程中同步判断平衡性
    bool IsVALWithDepth(TreeNode *root, int *depth)
    {
        if(root == NULL)
        {
            *depth = 0;
            return true;
        }

        int leftDepth, rightDepth;

        bool left = IsVALWithDepth(root->left, &leftDepth);
        bool right = IsVALWithDepth(root->right, &rightDepth);

        if(left == true && right == true)
        {
            if(fabs(leftDepth - rightDepth) <= 1)
            {
                *depth = max(leftDepth, rightDepth) + 1;

                debug <<"depth = " <<*depth <<endl;

                return true;
            }
        }

        return false;

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
    cout <<solu.IsBalanced_Solution(tree) <<endl;

    return 0;
}
