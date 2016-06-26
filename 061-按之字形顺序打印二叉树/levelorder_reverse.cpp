#include <iostream>
#include <algorithm>
#include <vector>

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
    vector< vector<int> > ans;

    void LevelOrder(TreeNode *pRoot,int p )
    {
        if(pRoot == NULL)
        {
            return;

        }
        if(ans.size( ) == p)
        {
            ans.push_back(vector<int>( ));
        }

        ans[p].push_back(pRoot->val);

        LevelOrder(pRoot->left, p + 1);
        LevelOrder(pRoot->right, p + 1);

    }

    vector< vector<int> > Print(TreeNode* pRoot)
    {
        LevelOrder(pRoot,0);

        for(int i = 0; i <ans.size( ); i++)
        {
            if(i & 1)
            {
                reverse(ans[i].begin( ), ans[i].end( ));
            }
        }
        return ans;
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

