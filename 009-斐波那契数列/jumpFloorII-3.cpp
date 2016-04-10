#include <iostream>

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

public :
    int jumpFloorII(int target)
    {
        long long ret;
		if(target >= 32)//大于8字节后，需要分两次移位，否则出错
		{
			ret = 1 << 30;
			ret = ret << (target - 31);
		}
		else
        {
			ret = 1 << (target - 1);
        }

        return ret;
    }
};



int __tmain( )
{
    Solution solu;
    cout <<solu.jumpFloorII(2) <<endl;;

    return 0;
}
