#include <iostream>
#include <bitset>

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
    double Power(double base, int exponent)
    {
        //  指数为0的情况，不管底数是多少都应该是0
        if(exponent == 0)
        {
            return 1.0;
        }

        //  指数为负数的情况下，底数不能为0
        if(Equal(base, 0.0) == true && exponent < 0)
        {
            debug <<"异常, 指数为负数的情况下，底数不能为0" <<endl;
            return 0.0;
        }

        double res = 1.0;
        if(exponent > 0.0)
        {
            res = PowerNormal(base, exponent);
        }
        else
        {
            res = PowerNormal(base, -exponent);
            res = 1 / res;
        }

        return res;
    }

private :
    double PowerNormal(double base, int exponent)
    {
        if(exponent == 0)
        {
            return 1;
        }
        else if(exponent == 1)
        {
            return base;
        }

        int res = 1, temp = base;
        while(exponent != 0)
        {
            if((exponent & 1) == 1) //  当前指数为不为0
            {
                res *= temp;        //  就计算一个乘积
                debug <<"temp = " <<temp <<", " <<bitset<32>(exponent) <<endl;
            }

            //  移位后, curr需要翻倍
            temp *= temp;           // 翻倍
            exponent >>= 1;         // 右移一位
        }
        return res;
    }


    double Equal(double left, double right)
    {
        if(fabs(left - right) <  0.0000001)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};



int __tmain( )
{
    Solution solu;

    cout <<solu.Power(10, 8) <<endl;
    return 0;
}
