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
public:
    int Add(int left, int right)
    {
        int temp;
        while(right != 0)
        {
            temp = left ^ right;                //  计算不带进位的情况
            right = (left & right) <<1;         //  计算带进位的情况
            left = temp;
            //  now left = 不带进位的情况, right = 带进位的情况
        }

        return left;
    }


    int AddRecursion(int left, int right)
    {
        return right == 0 ? left : AddRecursion(left ^ right, (left & right) << 1);
    }
};

int __tmain( )
{
    Solution solu;


    cout <<solu.Add(3, 5) <<endl;
    return 0;
}
