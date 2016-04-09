#include <iostream>
#include <vector>

using namespace std;

//  调试开关
#define __tmain main

#ifdef __tmain

#define dout cout

#else

#define dout 0 && cout

#endif // __tmain


#ifdef __tmain
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    : val(x), left(NULL), right(NULL)
    {
    }

 };
#endif // __tmain

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
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in)
    {
        //  前序遍历的长度跟中序遍历的长度应该相同
        if(pre.size( ) != in.size( ))
        {
            dout <<"the length of PRE and IN should be smae" <<endl;
            return NULL;
        }

        // 长度不能为0
        int size = pre.size( );
        if(size == 0)
        {
            dout <<"it's a NULL tree(length = 0)" <<endl;
            return NULL;
        }
    }

    struct TreeNode* ConstructRecursion(int *pre, int *in, int size)
    {


        int value = pre[0];      //  前序遍历的第一个结点是根节点
        TreeNode *root = new TreeNode(value);


        //  在中序遍历中查找到根的位置
        int rootIndex = 0;
        for(rootIndex = 0; rootIndex < size; rootIndex++)
        {
            if(in[rootIndex] == value)
            {
                break;
            }
        }
        if(rootIndex == size)
        {
            dout <<"can't find root (value = " <<value <<") in IN" <<endl;
            return NULL;
        }

        int leftLength = rootIndex -
    }
};

int __tmain( )
{
    dout <<"test" <<endl;
    return 0;
}
