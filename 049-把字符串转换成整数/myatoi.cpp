/*************************************************************************
     > File Name: atoi.c
     > Author: GatieMe
     > Mail: gatieme@163.com
     > Created Time: 2016年04月02日 星期六 22时22分06秒
 ************************************************************************/

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
    int StrToInt(string str)
    {
        string::iterator pstr = str.begin( );
        //  排除前导的空格
        while (*pstr == ' ')          //  排除前导的空格
        {
            pstr++;
        }

        bool minus = false;

        //  判断符号位+ -
        if (*pstr == '+')
        {
            pstr++;
        }
        else if (*pstr == '-')
        {
            pstr++;
            minus = true;
        }


        long long int value = 0;
        for (; pstr != str.end( ); pstr++)
        {
            if ('0' <= *pstr && *pstr <= '9')
            {
                value *= 10;
                value += *pstr - '0';
                debug <<"value = "<<value <<endl;
            }
            else
            {
                break;
            }

            //  解决OVER_FLOW的问题
            //  INT_MAX     2147483647
            //  INT_MIN     -2147483648  minus = true
            if((minus == true  && value > (unsigned long)(INT_MAX) + 1)     //  负数绝对值最大为INT_MAX + 1
            || (minus == false && value > INT_MAX))                         //  正数最大值为INT_MAX
            {
                debug <<value <<", " <<INT_MAX + 1 <<endl;
                debug <<"to max than int" <<endl;
                break;
            }

        }
        if(pstr != str.end( ))
        {
            return 0;
        }
        else
        {

            if (minus == true)
            {
                value = -value;
            }

            if (value >= INT_MAX)
            {
                value = INT_MAX;
            }
            else if (value <= INT_MIN)
            {
                value = INT_MIN;
            }

            return (int)value;

        }
    }
};


int __tmain(void)
{
    Solution solu;
    cout <<"INT_MAX" <<INT_MAX <<endl;
    cout <<"INT_MIN" <<INT_MIN <<endl;
    cout <<solu.StrToInt("1a33") <<endl;
    cout <<solu.StrToInt("-2147483648") <<endl;


    return EXIT_SUCCESS;
}
