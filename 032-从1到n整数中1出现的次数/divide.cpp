#include <iostream>
#include <cmath>
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
        return CountOne(n);
    }

    int CountOne(int n)
    {
        long count = 0;

        if (n == 0)
        {
            count = 0;
        }
        else if (n > 1 && n < 10)
        {
            count =  1;
        }
        else
        {
            // 计算n的位数
            long highest = n;       //表示最高位的数字
            int bit = 0;
            while (highest >= 10)
            {
                highest = highest / 10;
                bit++;
            }
            //  循环结束时, bit表示n的位数, 而highest是其最高位的数字

            //int weight = (int)Math.Pow(10, bit);//代表最高位的权重，即最高位一个1代表的大小
            int weight = pow(10, bit);//代表最高位的权重，即最高位一个1代表的大小

            if (highest == 1)
            {
                count = CountOne(weight - 1)
                      + CountOne(n - weight)
                      + (n - weight + 1);
            }
            else
            {
                count = highest * CountOne(weight - 1)
                      + CountOne(n - highest * weight)
                      + weight;
            }
        }

        return count;
    }
};



int __tmain( )
{
    Solution solu;
    cout <<solu.NumberOf1Between1AndN_Solution(12) <<endl;
    cout <<solu.NumberOf1Between1AndN_Solution(100) <<endl;
    cout <<solu.NumberOf1Between1AndN_Solution(1000000000) <<endl;
    return 0;
}
