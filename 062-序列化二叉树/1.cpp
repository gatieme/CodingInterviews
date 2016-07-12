#include <iostream>
#include <vector>
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
序列化二叉树，按照中序遍历二叉树的顺序，先左节点，后右节点，当到‘#’时
候，说明左节点或者右节点为NULL，同样反序列二叉树也一个道理，需要注意的
是在序列和反序列二叉树的时候，注意字符串与整数的转换，一般字符串转换为
整数，用迭代循环实现，整数转换为字符串可以用sprintf实现或者itoa实现

*/
class Solution
{
public:
    char* Serialize(TreeNode *root)
    {
        if(root==NULL)
        {
            return NULL;
        }

        string str;
        Serialize(root,str);

        return const_cast<char*>(str.c_str());
    }

    TreeNode* Deserialize(char *str) {
        if(str==NULL||*str=='\0')
            return NULL;
        int num=0;
        return Deserialize(str,num);
    }
    void Serialize(TreeNode *root,string &str)
    {
        if(root==NULL)
        {
            str+="#,";
            return ;
        }
        char ch[10];
        sprintf(ch,"%d",root->val);
        str+=",";
        Serialize(root->left,str);
        Serialize(root->right,str);
    }
    /*  */
    TreeNode* Deserialize(char *str, int &num)
    {
        int val = 0;
        if(str[num] == '#')
        {
            num+=2;
            return NULL;
        }
        while(str[num] != ',' && str[num] != '\0')
        {
            val = val * 10 + str[num] - '0';
            num++;
        }
        num++;

        TreeNode *root=new TreeNode(val);
        root->left = Deserialize(str,num);
        root->right = Deserialize(str,num);
        
        return root;
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


    return 0;
}
