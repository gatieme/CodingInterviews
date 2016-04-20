#include <iostream>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain


#define undebug 0 && cout


#ifdef __tmain
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;

	TreeNode(int x)
	:val(x), left(NULL), right(NULL)
    {
	}
};
#endif // __tmain



class Solution
{
    vector<int> res;
public:
    vector<int> PrintFromTopToBottom(TreeNode *root)
    {
        ///  方法1  -=>  循环调用递归打印每一层
        LevelOrder(root);

        ///  方法2  -=>  使用两个双端队列
        LevelOrderDev(root);

        ///  方法3  -=>  使用双指针标识当前指针和结束
        LevelOrderUsePoint(root);

        ///  方法4  -=>  使用aprent和childzsizesize标识前一层和当前层的节点个数
        LevelOrderUseSize(root);

        ///  方法4  -=>  在队列中插入结束标识来标识当前层结束
        LevelOrderUseEnd(root);
        return this->res;
    }

    /// 打印某一层的节点，递归实现
    int PrintLevel(TreeNode *root, int level)
    {
        if(root == NULL || level < 0)
        {
            return 0;
        }
        else if(level == 0)
        {
            debug <<root->val;
            res.push_back(root->val);        /// add for result in vector

            return 1;
        }
        else
        {
            return PrintLevel(root->left, level - 1) + PrintLevel(root->right, level - 1);
        }
    }

    ///  循环每层输出其节点，调用递归函数
    void LevelOrder(TreeNode *root)
    {
        res.clear( );           /// add for result in vector
        if(root == NULL)
        {
            return;
        }
        for(int level = 0; ; level++)
        {
            if(PrintLevel(root, level) == 0)
            {
                break;
            }
            debug <<endl;
        }
    }

    //////////////////////////
    ///  使用两个双端队列
    //////////////////////////
    void LevelOrderDev(TreeNode *root)
    {
        res.clear( );           /// add for result in vector

        /// deque双端队列，
        /// 支持迭代器，有push_back()方法，
        /// 跟vector差不多，比vector多了个pop_front,push_front方法

        deque<TreeNode *> qFirst, qSecond;
        qFirst.push_back(root);

        while(qFirst.empty( ) != true)
        {
            while (qFirst.empty( ) != true)
            {
                TreeNode *temp = qFirst.front( );
                qFirst.pop_front( );

                debug << temp->val;
                res.push_back(temp->val);        /// add for result in vector


                if (temp->left != NULL)
                {
                    qSecond.push_back(temp->left);
                }
                if (temp->right != NULL)
                {
                    qSecond.push_back(temp->right);
                }
            }
            debug << endl;
            qFirst.swap(qSecond);

        }
    }


    //////////////////////////
    ///  使用双指针标识当前指针和结束
    //////////////////////////
    void LevelOrderUsePoint(TreeNode *root)
    {
        res.clear( );           /// add for result in vector

        vector<TreeNode*> vec;
        vec.push_back(root);

        int cur = 0;
        int end = 1;

        while (cur < vec.size())
        {
            end = vec.size();       ///  新的一行访问开始，重新定位end于当前行最后一个节点的下一个位置

            while (cur < end)
            {
                debug << vec[cur]->val;  ///  访问节点
                res.push_back(vec[cur]->val);        /// add for result in vector

                if (vec[cur]->left != NULL) ///  压入左节点
                {
                    vec.push_back(vec[cur]->left);

                }
                if (vec[cur]->right != NULL)    ///  压入右节点
                {
                    vec.push_back(vec[cur]->right);
                }
                cur++;
            }
            debug << endl;
        }
    }


    //////////////////////////
    ///  使用aprent和childzsizesize标识前一层和当前层的节点个数
    //////////////////////////
    void LevelOrderUseSize(TreeNode *root)
    {
        res.clear( );           /// add for result in vector

        int parentSize = 1, childSize = 0;
        TreeNode *temp = NULL;

        queue<TreeNode *> q;
        q.push(root);
        while(q.empty( ) != true)
        {
            temp = q.front( );
            debug <<temp->val;
            res.push_back(temp->val);        /// add for result in vector

            q.pop( );

            if (temp->left != NULL)
            {
                q.push(temp->left);

                childSize++;
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
                childSize++;
            }

            parentSize--;
            if (parentSize == 0)
            {
                parentSize = childSize;
                childSize = 0;
                debug << endl;
            }

        }
    }

    //////////////////////////
    ///  在队列中插入结束标识来标识当前层结束
    //////////////////////////
    void LevelOrderUseEnd(TreeNode *root)
    {
        res.clear( );           /// add for result in vector

        queue<TreeNode *> q;

        q.push(root);
        q.push(NULL);

        while(q.empty( ) != true)
        {
            TreeNode* node = q.front();
            q.pop();

            if (node)
            {
                debug << node->val;
                res.push_back(node->val);        /// add for result in vector

                if (node->left != NULL)
                {
                    q.push(node->left);
                }
                if (node->right != NULL)
                {
                    q.push(node->right);
                }
            }
            else if (q.empty( ) != true)
            {
                q.push(NULL);
                debug << endl;
            }
        }
    }


    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in)
    {
        //  前序遍历的长度跟中序遍历的长度应该相同
        if(pre.size( ) != in.size( ))
        {
            undebug <<"the length of PRE and IN should be smae" <<endl;
            return NULL;
        }

        // 长度不能为0
        int size = pre.size( );
        if(size == 0)
        {
            undebug <<"it's a NULL tree(length = 0)" <<endl;
            return NULL;
        }

        int length = pre.size( );
        undebug <<"the length of your tree = " <<length <<endl;
        int value = pre[0];      //  前序遍历的第一个结点是根节点
        TreeNode *root = new TreeNode(value);

        undebug <<"the root is" <<root->val <<endl;
        //  在中序遍历中查找到根的位置
        int rootIndex = 0;
        for(rootIndex = 0; rootIndex < length; rootIndex++)
        {
            if(in[rootIndex] == value)
            {
                undebug <<"find the root at " <<rootIndex <<" in IN" <<endl;
                break;
            }
        }
        if(rootIndex >= length)
        {
            undebug <<"can't find root (value = " <<value <<") in IN" <<endl;
            return NULL;
        }

        ///  区分左子树和右子树
        ///  中序遍历中, 根左边的就是左子数, 右边的就是右子树
        ///  前序遍历中, 根后面是先遍历左子树, 然后是右子树

        ///  首先确定左右子树的长度, 从中序遍历in中确定
        int leftLength = rootIndex;
        int rightLength = length - 1 - rootIndex;
        undebug <<"left length = " <<leftLength <<", rightLength = " <<rightLength <<endl;
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
                undebug <<preLeft[i] <<inLeft[i] <<" ";

            }
            else if(i > rootIndex)
            {
                //  前序遍历的第一个是根节点, 根后面的(leftLegnth = rootIndex) - 1个节点是左子树, 后面是右子树
                preRight[i - rootIndex - 1] = pre[i];
                //  中序遍历前(leftLength = rootIndex) - 1个节点是左子树, 第rootIndex个节点是根, 然后是右子树
                inRight[i - rootIndex - 1] = in[i];
                undebug <<preRight[i - rootIndex - 1] <<inRight[i - rootIndex - 1] <<" ";

            }
        }
        undebug <<endl <<"the left tree" <<endl;
        for(int i = 0; i < leftLength; i++)
        {
            undebug <<preLeft[i] <<inLeft[i] <<" ";
        }
        undebug <<endl;
        undebug <<"the right tree" <<endl;
        for(int i = 0; i < rightLength; i++)
        {
            undebug <<preRight[i] <<inRight[i] <<" ";
        }
        undebug <<endl;


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
    solu.PrintFromTopToBottom(root);

    return 0;
}

