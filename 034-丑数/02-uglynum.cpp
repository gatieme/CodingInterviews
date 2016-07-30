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
protected:
    int ugly[10000];
    int min(int a, int b, int c)
    {
        int temp = (a < b ? a : b);

        return (temp < c ? temp : c);
    }

public:
    int GetUglyNumber_Solution(int N)
    {
        int index2  = 0;
        int index3  = 0;
        int index5  = 0;
        int index   = 0;
        int val, result;

        ugly[index++]     = 1;
        debug <<"the ugly num at index(" <<index <<") is " <<1 <<endl;

        while (index < N)
        {
            //竞争产生下一个丑数
            val = min(ugly[index2]*2,
                          ugly[index3]*3,
                          ugly[index5]*5);

            if (val == ugly[index2] * 2) //将产生这个丑数的index*向后挪一位；
            {
                ++index2;
            }
            if (val == ugly[index3] * 3)   //这里不能用elseif，因为可能有两个最小值，这时都要挪动；
            {
                ++index3;
            }
            if (val == ugly[index5] * 5)
            {
                ++index5;
            }
            ugly[index++] = val;
            debug <<"the ugly num at index(" <<index <<") is " <<val <<endl;
        }

        result = ugly[N - 1];

        return result;
    }
};

int __tmain( )
{
    Solution solu;

    cout <<solu.GetUglyNumber_Solution(3) <<endl;

    return 0;
}
