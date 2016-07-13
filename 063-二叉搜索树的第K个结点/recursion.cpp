#include <iostream>

using namespace std;

//http://blog.csdn.net/zuoyixiao/article/details/39525625
//http://blog.csdn.net/asd7486/article/details/51800096
//http://blog.jobbole.com/84712/
//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain


#ifdef  __tmain

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x = 0)
    :val(x), left(NULL), right(NULL) {
    }
};
#endif

class Solution
{
    unsigned int count = 0;
public:
    TreeNode* KthNode(TreeNode* root, unsigned int K)
    {
        if(root == NULL)
        {
            return NULL;
        }
        TreeNode *ret = NULL;


        if((ret = KthNode(root->left, K)) != NULL)
        {
            return ret;
        }
        ++count;
        debug <<"count = " <<count <<", value = " <<root->val <<endl;
        if(count == K)
        {
            return root;
        }
        
        if((ret = KthNode(root->right, K)) != NULL)
        {
            return ret;
        }
        return NULL;
    }
};


int __tmain( )
{
    TreeNode tree[7];

    tree[0].val = 5;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];

    tree[1].val = 3;
    tree[1].left = &tree[3];
    tree[1].right = &tree[4];

    tree[2].val = 7;
    tree[2].left = &tree[5];
    tree[2].right = &tree[6];

    tree[3].val = 2;
    tree[3].left = NULL;
    tree[3].right = NULL;

    tree[4].val = 4;
    tree[4].left = NULL;
    tree[4].right = NULL;

    tree[5].val = 6;
    tree[5].left = NULL;
    tree[5].right = NULL;

    tree[6].val = 8;
    tree[6].left = NULL;
    tree[6].right = NULL;

    Solution solu;
    TreeNode *res = NULL;
    if((res = solu.KthNode(tree, 3)) != NULL)
    {
        cout <<res->val <<endl;
    }
    else
    {
        cout <<"null node" <<endl;
    }
    return 0;
}
