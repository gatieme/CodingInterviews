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
    /**
     * [NumberOf1Between1AndN_Solution 统计1到n的整数中1出现的次数]
     * @Author   gatieme
     * @DateTime 2016-05-01T22:03:43+0800
     * @param    n                        [整数n]
     * @return                            [1到n的整数中1出现的次数]
     */
    int NumberOf1Between1AndN_Solution(int n)
    {
        int count = 0;

        for(int i = 1;
            i <= n;
            i++)
        {
            count += NumberOf1(i);
        }

        return count;
    }

protected:
    /**
     * [NumberOf1 统计number中1出现的次数]
     * @Author    gatieme
     * @DateTime 2016-05-01T22:01:08+0800
     * @param    number                   [待处理的数字]
     * @return                            [number中1出现的次数]
     */
    int NumberOf1(int number)
    {
        int count = 0;
        while(number != 0)
        {
            if(number % 10 == 1)
            {
                count++;
            }

            number /= 10;
        }

        return count;
    }
};



int __tmain( )
{
    Solution solu;
    cout <<solu.NumberOf1Between1AndN_Solution(12) <<endl;
    cout <<solu.NumberOf1Between1AndN_Solution(100) <<endl;
    cout <<solu.NumberOf1Between1AndN_Solution(1000) <<endl;
    return 0;
}
