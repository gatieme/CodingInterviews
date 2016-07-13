#include <iostream>
#include <stack>

using namespace std;

//http://blog.csdn.net/zuoyixiao/article/details/39525625
//http://blog.csdn.net/asd7486/article/details/51800096
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
    /*  中序与前序的区别在于
     *  前序在递归至最左的时候就会输出递归的节点, 因此先输出根，然后是左
     *  但是中序在递归至最左时，弹栈时才输出, 因此先输出最左，再输出根
     */
    TreeNode* KthNode(TreeNode *root, unsigned int K)
    {
        if(root == NULL)
        {
            debug <<"The tree is NULL..." <<endl;
            return NULL;
        }

        stack<TreeNode *> nstack;
        TreeNode *node = root;

        //  开始遍历整个二叉树
        while(node != NULL || nstack.empty() != true)
        {
            // 不输出当前根节点，但是递归直至当前根节点node的最左端
            while(node != NULL)
            {
                nstack.push(node);
                node = node->left;
            }

            //  此时栈顶的元素是当前最左元素
            //  它应该被输出
            if(nstack.empty( ) != true)
            {
                node = nstack.top( );
                debug <<node->val <<endl;
                count++;
                if(count == K)
                {
                    return node;
                }
                nstack.pop( );
                node = node->right;
            }
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
