#include <iostream>
#include <stack>
#include <algorithm>
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


class Solution
{
public:
    void MirrorPost(TreeNode *root)
    {

        if(root == NULL)
        {
            debug <<"The tree is NULL..." <<endl;
            return;
        }
        stack<TreeNode *> nstack;

        TreeNode *cur;                      //当前结点
        TreeNode *pre = NULL;                 //前一次访问的结点
        nstack.push(root);

        while(nstack.empty( ) != true)
        {
            cur = nstack.top( );

            if((cur->left == NULL && cur->right == NULL)                     //  左右还是均为NULL, 可以被输出
            || (pre != NULL && ((pre == cur->left /*&& cur->right == NULL*/) || pre == cur->right)))     //  左右还是被输出了, 递归返回

            {
                ///cout<<cur->val;  //如果当前结点没有孩子结点或者孩子节点都已被访问过
                            //  将原来的输出改为交换左右子树即可
                if(cur->left != NULL || cur->right != NULL)
                {
                    swap(cur->left, cur->right);
                }

                nstack.pop( );
                pre = cur;
            }
            else
            {
                // 由于栈是先进后出，因此先如后孩子, 再左孩子可以保证递归返回时先遍历左孩子
                if(cur->right != NULL)
                {
                    nstack.push(cur->right);
                }

                if(cur->left != NULL)
                {
                    nstack.push(cur->left);
                }
            }
        }
    }


};


int __tmain( )
{
    debug <<"test" <<endl;
    return 0;
}
