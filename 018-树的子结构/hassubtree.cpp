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
    bool HasSubtree(TreeNode* parent, TreeNode* child)
    {
        if(child == NULL || parent == NULL)
        {
            return false;
        }

        bool result;
        //  如果当前父树的节点与子树的根节点相同，则直接从父树的当前位置开始判定
        if(parent->val == child->val)
        {
            result = DoesParentHaveChild(parent, child);
        }
        if(result != true)
        {
            return HasSubtree(parent->left, child)      //  从左子树查找
            || HasSubtree(parent->right, child);        //  从右子树中查找
        }
        else
        {
            return true;
        }

    }

    bool DoesParentHaveChild(TreeNode *parent, TreeNode *child)
    {
        if(child == NULL)      //  子树为NULL，那么必然是子树
        {
            return true;
        }
        else if(parent == NULL)      //  子树不是NULL, 但是父亲树是NULL
        {
            return false;
        }

        //  两个节点的值不相等，那么两个树必然不是父子关系
        if(parent->val != child->val)
        {
            return false;
        }
        else      // 否则当前节点当前相等，则递归的判断左子树和右子树对应节点是否相同
        {

            return DoesParentHaveChild(parent->left, child->left)
                && DoesParentHaveChild(parent->right, child->right);
        }
    }
};

int __tmain( )
{
    debug <<"test" <<endl;
    return 0;
}
