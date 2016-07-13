#include <iostream>
#include <vector>
#include <sstream>

#include <cstring>
#include <cstdio>


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



/*
用递归实现：
序列化二叉树，按照先序遍历二叉树的顺序，先左节点，后右节点，当到‘#’时
候，说明左节点或者右节点为NULL，同样反序列二叉树也一个道理，需要注意的
是在序列和反序列二叉树的时候，注意字符串与整数的转换，一般字符串转换为
整数，用迭代循环实现，整数转换为字符串可以用sprintf实现或者itoa实现

*/
class Solution
{
public:
    /*  序列化二叉树  */
    char* Serialize(TreeNode *root)
    {
        if(root == NULL)
        {
            char *serial = new char[3];
            strcpy(serial, "#,");
            return serial;
        }

        string str;
        Serialize(root, str);

        const char  *c_str = str.c_str( );
        char        *serial = new char[str.length( ) + 1];
        strcpy(serial, c_str);

        return serial;
    }

    TreeNode* Deserialize(char *str)
    {
        if(str == NULL|| *str == '\0')
        {
            return NULL;
        }

        int index = 0;

        return Deserialize(str, index);
    }

private :
    void Serialize(TreeNode *root, string &str)
    {
        if(root == NULL)
        {
            str += "#,";
            return;
        }

        /*  先序遍历的方式, 序列化二叉树  */
        str += (toString(root->val) + ",");
        Serialize(root->left, str);
        Serialize(root->right, str);
    }


    /*  反序列化二叉树
     *  将一个序列化的字符串转换成二叉树  */
    TreeNode* Deserialize(char *str, int &index)
    {
        if(str[index] == '#')
        {
            index += 2;
            return NULL;
        }

        /*  获取到节点的数字权值  */
        int num = 0;
        while(str[index] != ',' && str[index] != '\0')
        {
            num = num * 10 + (str[index] - '0');
            index++;
        }
        index++;

        TreeNode *root = new TreeNode(num);
        root->left = Deserialize(str, index);
        root->right = Deserialize(str, index);

        return root;
    }

    string toString(int num)
    {
#if 0
        char ch[10];
        sprintf(ch,"%d,",root->val);
#endif // 0
        stringstream ss;
        ss <<num;
        return ss.str( );
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
