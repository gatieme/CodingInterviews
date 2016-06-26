#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

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
    TreeNode(int x = 0)
    :val(x), left(NULL), right(NULL)
    {
    }
};

#endif // __tmain


class Solution
{
public:
    vector<vector<int> > Print(TreeNode* pRoot)
    {
        vector< vector<int> > ret;
        if(pRoot == NULL)
        {
            return ret;
        }
        vector<int> curr;
        deque<TreeNode *> deq;
        deq.push_back(NULL);//层分隔符
        deq.push_back(pRoot);
        bool leftToRight = true;

        while (deq.size( ) != 1)
        {
            TreeNode* node = deq.front( );
            deq.pop_front();

            if(node == NULL)    //  到达每层分隔符
            {
                if (leftToRight == true)    //  从前完后遍历
                {
                    deque<TreeNode *>::iterator iter;
                    for(iter = deq.begin( );
                        iter != deq.end( );
                        iter++)
                    {
                        curr.push_back((*iter)->val);
                    }
                }
                else                        //  从后往前遍历
                {
                    deque<TreeNode *>::reverse_iterator riter;
                    for(riter = deq.rbegin( );
                        riter < deq.rend( );
                        riter++)
                    {
                        curr.push_back((*riter)->val);
                    }
                }
                leftToRight = !leftToRight;

                ret.push_back(curr);
                curr.clear();
                deq.push_back(NULL);//添加层分隔符
                continue;//一定要continue
            }
            if (node->left != NULL)
            {
                deq.push_back(node->left);
            }
            if (node->right != NULL)
            {
                deq.push_back(node->right);
            }
        }
        return ret;
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

