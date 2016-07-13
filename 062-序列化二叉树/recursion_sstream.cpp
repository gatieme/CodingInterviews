#include <iostream>
#include <vector>
#include <sstream>

#include <cstring>
#include <cstdio>
#include <cstdlib>


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
    TreeNode(int x = 0) :
    val(x), left(NULL), right(NULL)
    {
    }
};

#endif




#define DELIMITERS  " "
class Solution
{
    /*  先序遍历  */
    void PreOrder(TreeNode *node, stringstream &out)
    {
        if (node == NULL)
        {
            out <<"#" <<DELIMITERS;
            return;
        }

        out <<node->val <<DELIMITERS;
        PreOrder(node->left, out);
        PreOrder(node->right, out);
    }

    /*   从字符流in中读取出数字num
     *   成功返回true
     *   失败返回false  */
    bool GetNumber(stringstream &in, int &number)
    {
        char buf[20];

        /* 这里会有个问题, 只能以空格或者换行符分割
         * 然后直接in >>buf读入单个节点的数据 */
        in >>buf;
        if (buf[0] == '#')
        {
            return false;
        }

        number = atoi(buf);

        return true;
    }

    TreeNode* Construct(stringstream &in)
    {
        int val;

        if (GetNumber(in, val))
        {
            TreeNode *node = new TreeNode(val);

            node->left = Construct(in);
            node->right = Construct(in);
            return node;
        }
        return NULL;
    }

public:

    char* Serialize(TreeNode *root)
    {
        stringstream ss;

        PreOrder(root, ss);
        const char *c_str = ss.str().c_str();
        char *serial = new char[ss.str().length() + 1];
        strcpy(serial, c_str);
        return serial;
    }
    TreeNode* Deserialize(char *c_str) {
        if (!c_str) return NULL;
        string str(c_str);
        stringstream ss(str);
        return Construct(ss);
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


    tree[2].val = 10;
    tree[2].left = &tree[5];
    tree[2].right = &tree[6];


    tree[3].val = 5;
    tree[3].left = NULL;
    tree[3].right = NULL;

    tree[4].val = 7;
    tree[4].left = NULL;
    tree[4].right = NULL;

    tree[5].val = 9;
    tree[5].left = NULL;
    tree[5].right = NULL;

    tree[6].val = 11;
    tree[6].left = NULL;
    tree[6].right = NULL;


    Solution solu;
    cout <<solu.Serialize(tree) <<endl;
    cout <<solu.Serialize(solu.Deserialize(solu.Serialize(tree))) <<endl;

    return 0;
}
