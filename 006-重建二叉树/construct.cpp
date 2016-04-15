#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain




//#define __ISFIRST_FOR_POSTPRDER



#ifdef __tmain
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
#ifdef __ISFIRST_FOR_POSTPRDER
    int    isFirst;          //  非递归中序遍历中保存其是否首次被访问
#endif // __ISFIRST_FOR_POSTPRDER


    TreeNode(int x)
    : val(x), left(NULL), right(NULL)
    {
    }

    //
    static void PreOrder(TreeNode *root)
    {
        if(root == NULL)
        {
            return;
        }
        cout <<root->val;
        PreOrder(root->left);
        PreOrder(root->right);
    }

    static void InOrder(TreeNode *root)
    {
        if(root == NULL)
        {
            return;
        }
        InOrder(root->left);
        cout <<root->val;
        InOrder(root->right);
    }

    static void PostOrder(TreeNode *root)
    {
        if(root == NULL)
        {
            return;
        }
        PostOrder(root->left);
        PostOrder(root->right);
        cout <<root->val;
    }

    //    非递归实现
    //
    //    根据前序遍历访问的顺序，优先访问根结点，然后再分别访问左孩子和右孩子。
    //
    //    即对于任一结点，其可看做是根结点，因此可以直接访问，访问完之后，若其左孩子不为空，按相同规则访问它的左子树；
    //    当访问其左子树时，再访问它的右子树。因此其处理过程如下：
    //
    //     对于任一结点P：
    //
    //     1)访问结点P，并将结点P入栈;
    //
    //     2)判断结点P的左孩子是否为空，若为空，则取栈顶结点并进行出栈操作，并将栈顶结点的右孩子置为当前的结点P，循环至1);若不为空，则将P的左孩子置为当前的结点P;
    //
    //     3)直到P为NULL并且栈为空，则遍历结束。
    static void PreOrderDev(TreeNode *root)
    {
        if(root == NULL)
        {
            debug <<"The tree is NULL..." <<endl;
        }

        stack<TreeNode *> nstack;


        TreeNode *node = root;
        //  开始遍历整个二叉树
        while(node != NULL || nstack.empty( ) != true)
        {
            //  输出当前子树的根节点，然后递归直至最左
            while(node != NULL)
            {
                cout <<node->val;
                nstack.push(node);
                node = node->left;
            }

            //  此时循环结束时，当前栈顶节点已经是最左节点
            //  此时递归开始返回，开始出栈，并输出节点的右节点
            if(nstack.empty() != true)
            {
                node = nstack.top( );
                nstack.pop( );
                node = node->right;
            }
        }
    }

    static void InOrderDev(TreeNode *root)
    {
        if(root == NULL)
        {
            debug <<"The tree is NULL..." <<endl;
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
                cout <<node->val;
                nstack.pop( );
                node = node->right;
            }
        }
    }


#ifdef __ISFIRST_FOR_POSTPRDER
    //  对于任一结点P，将其入栈，
    //  然后沿其左子树一直往下搜索，直到搜索到没有左孩子的结点，
    //  此时该结点出现在栈顶，但是此时不能将其出栈并访问，因此其右孩子还为被访问。
    //
    //  所以接下来按照相同的规则对其右子树进行相同的处理，当访问完其右孩子时，该结点又出现在栈顶，
    //  此时可以将其出栈并访问。这样就保证了正确的访问顺序。
    //  可以看出，在这个过程中，每个结点都两次出现在栈顶，只有在第二次出现在栈顶时，才能访问它。因此需要多设置一个变量标识该结点是否是第一次出现在栈顶。
    static void PostOrderDev(TreeNode *root)
    {
        if(root == NULL)
        {
            debug <<"The tree is NULL..." <<endl;
        }

        stack<TreeNode *> nstack;
        TreeNode *node = root;

        while(node != NULL || nstack.empty( ) != true)
        {
            //  遍历直至最左节点
            while(node != NULL)
            {
                node->isFirst = 1;       // 当前节点首次被访问
                nstack.push(node);
                node = node->left;

            }

            if(nstack.empty() != true)
            {
                node = nstack.top( );
                nstack.pop( );

                if(node->isFirst == 1)   // 第一次出现在栈顶
                {
                    node->isFirst++;
                    nstack.push(node);

                    node = node->right;
                }
                else if(node->isFirst == 2)
                {
                    cout <<node->val;
                    node = NULL;
                }
            }
        }
    }
#else           //
    static void PostOrderDev(TreeNode *root)
    {
        if(root == NULL)
        {
            debug <<"The tree is NULL..." <<endl;
        }
        stack<TreeNode *> nstack;

        TreeNode *cur;                      //当前结点
        TreeNode *pre = NULL;                 //前一次访问的结点
        nstack.push(root);

        while(nstack.empty( ) != true)
        {
            cur = nstack.top( );

            if((cur->left == NULL && cur->right == NULL)                     //  左右还是均为NULL, 可以被输出
            || (pre != NULL && ((pre == cur->left && cur->right == NULL) || pre == cur->right)))     //  左右还是被输出了, 递归返回
            //  其实当前节点要是想被输出, 要么
            //  1--其左右孩子均为NULL
            //  2--其左孩子刚被输出，而其右孩子为NULL
            //  3--其右孩子刚被输出
            //
            //  但是这里有一个优化, 入栈时候, 先是根入栈， 然后是右孩子, 然后是左孩子,
            //  因此当跟元素位于栈顶的时候, 其左右孩子必然已经弹出，即被输出,
            //  也就是说, 当前
            {
                cout<<cur->val;  //如果当前结点没有孩子结点或者孩子节点都已被访问过
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

#endif // __ISFIRST_FOR_POSTPRDER

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
            debug <<"the length of PRE and IN should be smae" <<endl;
            return NULL;
        }

        // 长度不能为0
        int size = pre.size( );
        if(size == 0)
        {
            debug <<"it's a NULL tree(length = 0)" <<endl;
            return NULL;
        }

        int length = pre.size( );
        debug <<"the length of your tree = " <<length <<endl;
        int value = pre[0];      //  前序遍历的第一个结点是根节点
        TreeNode *root = new TreeNode(value);

        debug <<"the root is" <<root->val <<endl;
        //  在中序遍历中查找到根的位置
        int rootIndex = 0;
        for(rootIndex = 0; rootIndex < length; rootIndex++)
        {
            if(in[rootIndex] == value)
            {
                debug <<"find the root at " <<rootIndex <<" in IN" <<endl;
                break;
            }
        }
        if(rootIndex >= length)
        {
            debug <<"can't find root (value = " <<value <<") in IN" <<endl;
            return NULL;
        }

        ///  区分左子树和右子树
        ///  中序遍历中, 根左边的就是左子数, 右边的就是右子树
        ///  前序遍历中, 根后面是先遍历左子树, 然后是右子树

        ///  首先确定左右子树的长度, 从中序遍历in中确定
        int leftLength = rootIndex;
        int rightLength = length - 1 - rootIndex;
        debug <<"left length = " <<leftLength <<", rightLength = " <<rightLength <<endl;
        vector<int> preLeft(leftLength), inLeft(leftLength);
        vector<int> preRight(rightLength), inRight(rightLength);
        for(int i = 0; i < length; i++)
        {
            if(i < rootIndex)
            {
                //  前序遍历的第一个是根节点, 根后面的(leftLegnth = rootIndex) - 1个节点是左子树, 因此是i+1
                preLeft[i] = pre[i + 1];
                //  中序遍历前(leftLength = rootIndex) - 1个节点是左子树, 第rootIndex个节点是根
                inLeft[i] = in[i];
                debug <<preLeft[i] <<inLeft[i] <<" ";

            }
            else if(i > rootIndex)
            {
                //  前序遍历的第一个是根节点, 根后面的(leftLegnth = rootIndex) - 1个节点是左子树, 后面是右子树
                preRight[i - rootIndex - 1] = pre[i];
                //  中序遍历前(leftLength = rootIndex) - 1个节点是左子树, 第rootIndex个节点是根, 然后是右子树
                inRight[i - rootIndex - 1] = in[i];
                debug <<preRight[i - rootIndex - 1] <<inRight[i - rootIndex - 1] <<" ";

            }
        }
        debug <<endl <<"the left tree" <<endl;
        for(int i = 0; i < leftLength; i++)
        {
            debug <<preLeft[i] <<inLeft[i] <<" ";
        }
        debug <<endl;
        debug <<"the right tree" <<endl;
        for(int i = 0; i < rightLength; i++)
        {
            debug <<preRight[i] <<inRight[i] <<" ";
        }
        debug <<endl;


        root->left = reConstructBinaryTree(preLeft, inLeft);
        root->right = reConstructBinaryTree(preRight, inRight);

        return root;
    }





};

int __tmain( )
{
    int pre[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
    int in[] = { 4, 7, 2, 1, 5, 3, 8, 6 };

    vector<int> preOrder(pre, pre + 8);
    vector<int>  inOrder( in,  in + 8);

    Solution solu;
    TreeNode *root = solu.reConstructBinaryTree(preOrder, inOrder);

    cout <<"PreOrder" <<endl;   //  12345678
    TreeNode::PreOrder(root);
    cout <<endl;
    TreeNode::PreOrderDev(root);
    cout <<endl;

    cout <<"InOrder " <<endl;   //  47215386
    TreeNode::InOrder(root);
    cout <<endl;
    TreeNode::InOrderDev(root);
    cout <<endl;


    cout <<"PostOrder " <<endl; //
    TreeNode::PostOrder(root);
    cout <<endl;
    TreeNode::PostOrderDev(root);
    cout <<endl;

    return 0;
}
