#include <iostream>
#include <stack>
#include <vector>
#include <iterator>


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
                debug <<"push  " <<pushV[i] <<endl;
#ifdef  __tmain
                cout <<"STACK : ";
                copy(pushV.begin( ), pushV.begin( ) + i + 1, ostream_iterator<int>(cout," "));
                cout <<endl;
#endif
                debug <<"pop  " <<pushV[i] <<endl;
                pushV.erase(pushV.begin( ) + i);
                popV.erase(popV.begin( ));
                i--;
                // 模拟出栈
#ifdef  __tmain
                cout <<"STACK : ";
                copy(pushV.begin( ), pushV.begin( ) + i + 1, ostream_iterator<int>(cout," "));
                cout <<endl;
#endif
                debug <<"stack top  " <<pushV[i] <<", popV[0]= " <<popV[0] <<endl;
            }
            else
            {
                debug <<"push " <<pushV[i] <<endl;
                i++;                                //  模拟入栈
#ifdef  __tmain
                cout <<"STACK : ";
                copy(pushV.begin( ), pushV.begin( ) + i, ostream_iterator<int>(cout," "));
                cout <<endl;
#endif
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

	//cout <<solu.IsPopOrder(vector<int>(nPush, nPush + 5), vector<int>(nPop1, nPop1 + 5)) <<endl;
	cout <<solu.IsPopOrder(vector<int>(nPush, nPush + 5), vector<int>(nPop2, nPop2 + 5)) <<endl;
	cout <<solu.IsPopOrder(vector<int>(nPush, nPush + 5), vector<int>(nPop3, nPop3 + 5)) <<endl;
	cout <<solu.IsPopOrder(vector<int>(nPush, nPush + 5), vector<int>(nPop4, nPop4 + 5)) <<endl;

	return 0;
}
