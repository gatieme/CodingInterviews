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
    void MirrorPre(TreeNode *pRoot)
    {
        if(pRoot == NULL)
        {
            return;
        }
        stack<TreeNode *> nstack;
        nstack.push(pRoot);

        TreeNode *node = NULL;
        while(nStack.empty() != true)
        {
            node = nstack.top( );
            nstack.pop( );

            //  先交换, 然后递归左，接着递归右
            //  相当与一次前序遍历
            if(tree->left != NULL || tree->rigth != NULL)
            {
                swap(node->left, node->right);
            }

            if(tree->left != NULL)
            {
                nstack.push(node->left);
            }
            if(tree->rigth != NULL)
            {
                nstack.push(node->right);
            }
        }
    }

    void MirrorIn(TreeNode *pRoot)
    {
        if(pRoot == NULL)
        {
            return;
        }
        stack<TreeNode *> nstack;
        nstack.push(pRoot);

        TreeNode *node = NULL;
        while(nStack.empty() != true)
        {
            node = nstack.top( );
            nstack.pop( );

            //  先交换, 然后递归左，接着递归右
            //  相当与一次前序遍历
            if(tree->left != NULL || tree->rigth != NULL)
            {
                swap(node->left, node->right);
            }

            if(tree->left != NULL)
            {
                nstack.push(node->left);
            }
            if(tree->rigth != NULL)
            {
                nstack.push(node->right);
            }
        }
    }
};


int __tmain( )
{
    debug <<"test" <<endl;
    return 0;
}
