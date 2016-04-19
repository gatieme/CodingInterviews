#include <iostream>
#include <stack>
#include <vector>

using namespace std;

//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif


class Solution
{
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV)
    {
        if(pushV.empty( ) || popV.empty( ) || pushV.size( )!= popV.size( ))
        {
            return false;
        }

        for(int i = 0;i < pushV.size();)
        {
            if(pushV[i] == popV[0])
            {
                pushV.erase(pushV.begin( ) + i);
                popV.erase(popV.begin( ));
                i--;                                // 模拟出栈
            }
            else
            {
                i++;                                //  模拟入栈
            }
        }

        return pushV.empty( );
    }

};




int __tmain( )
{
	int nPush[5] = { 1, 2, 3, 4, 5};
	int nPop1[5] = { 4, 5, 3, 2, 1};
	int nPop2[5] = { 4, 3, 5, 1, 2};
    int nPop3[5] = { 5, 4, 3, 2, 1};
	int nPop4[5] = { 4, 5, 2, 3, 1};

	Solution solu;

	cout <<solu.IsPopOrder(vector<int>(nPush, nPush + 5), vector<int>(nPop1, nPop1 + 5)) <<endl;
	cout <<solu.IsPopOrder(vector<int>(nPush, nPush + 5), vector<int>(nPop2, nPop2 + 5)) <<endl;
	cout <<solu.IsPopOrder(vector<int>(nPush, nPush + 5), vector<int>(nPop3, nPop3 + 5)) <<endl;
	cout <<solu.IsPopOrder(vector<int>(nPush, nPush + 5), vector<int>(nPop4, nPop4 + 5)) <<endl;

	return 0;
}
