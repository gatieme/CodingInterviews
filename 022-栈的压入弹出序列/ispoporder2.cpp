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

#endif // __tmain


class Solution
{
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV)
    {
        if(pushV.size( ) == 0 || popV.size( ) == 0)
        {
            return false;
        }
        int top = -1, push = 0, pop = 0;

        ++top;
        debug <<"push" <<pushV[top] <<endl;


        while(push < pushV.size() && pop < popV.size( ))
        {
            if(top != -1 && pushV[top] == popV[pop])        //  当前栈顶元素正好是出栈序列中的元素
            {
                debug <<"pop"<<popV[pop] <<endl;
                // 模拟出栈的过程
                top--;
                pop++;

            }
            else
            {

                //  模拟入栈的过程
                pushV[++top] = pushV[++push];
                debug <<"push" <<pushV[push] <<endl;
            }
#ifdef  __tmain
            cout <<"STACK : ";
            copy(pushV.begin( ), pushV.begin( ) + top + 1, ostream_iterator<int>(cout," "));
            cout <<endl;
#endif
        }
        debug <<top <<", " <<push <<", " <<pop <<endl;
        return (top == -1);
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
