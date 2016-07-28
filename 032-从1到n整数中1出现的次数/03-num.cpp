#include <iostream>

using namespace std;

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
        long count = 0;

        long i = 1;

        long current = 0,after = 0,before = 0;

        while((n / i) != 0)
        {
            before = n / (i * 10);
            current = (n / i) % 10;
            after = n - (n / i) * i;

            debug <<"n = " << n <<", " <<before <<" " <<current <<" " <<after <<endl;

            if (current >= 1)
            {
                // 如果current大于1，则出现1的次数为其高位before的数字加1
                count += (before + 1) * i;
                debug <<"count += (" <<before <<" + 1) * " <<i <<endl;
            }
            else if (current == 0)
            {
                //  如果current位数为0, 1出现位数出现是其高位数字before
                debug <<"count += " <<before <<" * " <<i <<endl;
                count += before * i;
            }

            else if(current == 1)
            {
                //  如果current等于1，则1出现的次数为其高位before + 其低位after
                debug <<"count += " <<before <<" * " <<i <<" + " <<after <<" + 1" <<endl;
                count += (before + after) + 1;
            }
            debug <<"count = " <<count <<endl;

            i = i * 10;

        }

        return count;

    }
};



int __tmain( )
{
    Solution solu;
    cout <<solu.NumberOf1Between1AndN_Solution(12) <<endl;
    cout <<solu.NumberOf1Between1AndN_Solution(132) <<endl;
    cout <<solu.NumberOf1Between1AndN_Solution(232) <<endl;
    return 0;
}
