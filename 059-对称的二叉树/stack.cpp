#include <iostream>
#include <deque>


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


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool isSymmetrical(TreeNode *root)
    {
        if(root == NULL)
        {
            return true;
        }

        if(root->left == NULL 
        && root->right == NULL)
        {
            return true;
        }
        if((root->left == NULL && root->right != NULL)
        || (root->left != NULL && root->right == NULL))
        {
            return false;
        }

        deque< TreeNode * > dq;
        dq.push_front(root->left);
        dq.push_back(root->right);

        while(dq.empty( ) != true)
        {
            TreeNode* lroot = dq.front();
            TreeNode* rroot = dq.back();
            dq.pop_front();
            dq.pop_back();
        
            if(lroot -> val != rroot -> val)
            {
                return false;
            }

            if((lroot->right == NULL && rroot->left != NULL)
            || (lroot->right != NULL && rroot->left == NULL))
            {
                return false;
            }

            if(lroot->right != NULL)
            {
                dq.push_front(lroot->right);
                dq.push_back(rroot->left);
            }

            if((lroot->left == NULL && rroot->right != NULL)
            || (lroot->left != NULL && rroot->right == NULL))
            {
                return false;
            }

            if(lroot->left != NULL)
            {
                dq.push_front(lroot->left);
                dq.push_back(rroot->right);
            }
        }
        return true;
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
