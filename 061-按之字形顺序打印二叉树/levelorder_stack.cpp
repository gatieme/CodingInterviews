#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>


using namespace std;

#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain


#define undebug 0 && cout


#ifdef __tmain

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x = 0)
    :val(x), left(NULL), right(NULL)
    {
    }
};

#endif // __tmain


class Solution
{
public:

    vector< vector<int> > Print(TreeNode* pRoot)
    {
        vector< vector<int> > res;

        if(pRoot == NULL)
        {
            return res;
        }
        vector<int> curr;

        stack<TreeNode *> levels[2];
        #define LEFT_TO_RIGHT 1 //  先左后右访问, 意味着先右后左入栈
        #define RIGHT_TO_LEFT 0 //  先右后左访问, 意味着先左后右入栈

        int current = LEFT_TO_RIGHT;  
        int next = RIGHT_TO_LEFT;
        levels[current].push(pRoot);

        while(levels[LEFT_TO_RIGHT].empty( ) != true 
           || levels[RIGHT_TO_LEFT].empty( ) != true)
        {
            TreeNode *pNode = levels[current].top( );
            levels[current].pop( );

            curr.push_back(pNode->val);

            /*  当前层次current是先左后右访问
             *  则下一层次应该先右后左访问
             *  即next从左往右入栈
             */
            if(current == LEFT_TO_RIGHT)  
            {
                if(pNode->left != NULL)
                {
                    levels[next].push(pNode->left);
                }
                if(pNode->right != NULL)
                {
                    levels[next].push(pNode->right);
                }
            }
            else                //  先右后左入栈
            {

                if(pNode->right != NULL)
                {
                    levels[next].push(pNode->right);
                }
                if(pNode->left != NULL)
                {
                    levels[next].push(pNode->left);
                }
            }

            if(levels[current].empty( ) == true)
            {
                res.push_back(curr);
                curr.clear( );
                current =  1 - current;
                next = 1 - next;
            }
        }

        return res;
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
    vector< vector<int> > res = solu.Print(tree);
    for(int i = 0; i < res.size( ); i++)
    {
        for(int j = 0; j < res[i].size( ); j++)
        {
            cout <<res[i][j];
        }
        cout <<endl;
    }

    return 0;
}

