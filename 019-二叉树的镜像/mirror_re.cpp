#include <iostream>

using namespace std;

//  µ÷ÊÔ¿ª¹Ø
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
    void Mirror(TreeNode *pRoot)
    {
        if(pRoot == NULL)
        {
            return;
        }

        swap(pRoot->left, pRoot->right);

        Mirror(pRoot->left);
        Mirror(pRoot->right);

    }
};


int __tmain( )
{
    debug <<"test" <<endl;
    return 0;
}
