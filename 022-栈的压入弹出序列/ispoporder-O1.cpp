#include <iostream>
#include <stack>
#include <vector>

using namespace std;

//  µ÷ÊÔ¿ª¹Ø
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain


class Solution
{
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV)
    {

        if(pushV.size( ) == 0 || popV.size( ) == 0 || pushV.size( ) != popV.size( ))
        {
            return false;
        }

        int  top = -1, push = 0, pop = 0;
        for(pop = 0; pop < popV.size( ); pop++)
        {
            while(push >= popV.size( )
               || pushV[push] != popV[pop]
               && (top == -1 || pushV[top] != popV[pop]))
            {
                if(pop >= popV.size( ))
                {
                    return false;
                }
                pushV[++top] = pushV[push++];
            }

            if(top != -1 && pushV[top] == popV[pop])
            {
                top--;
            }
            else
            {
                push++;
            }
        }

        return true;
    }
};

int __tmain( )
{
	int nPush[5] = {1,2,3,4,5};
	int nPop1[5] = {4,5,3,2,1};
	int nPop2[5] = {4,3,5,1,2};
    int nPop3[5] = {5,4,3,2,1};
	int nPop4[5] = {4,5,2,3,1};

	Solution solu;

	cout <<solu.IsPopOrder(vector<int>(nPush, nPush + 5), vector<int>(nPop1, nPop1 + 5)) << endl;
	cout <<solu.IsPopOrder(vector<int>(nPush, nPush + 5), vector<int>(nPop2, nPop2 + 5)) << endl;
	cout <<solu.IsPopOrder(vector<int>(nPush, nPush + 5), vector<int>(nPop3, nPop3 + 5)) << endl;
	cout <<solu.IsPopOrder(vector<int>(nPush, nPush + 5), vector<int>(nPop4, nPop4 + 5)) << endl;

	return 0;
}
