#include <iostream>
#include <cstring>
using namespace std;


//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain



#define SET_SYMBOL_BIT(num)  ((num) |= (1 << 31))		/*  设置符号位为1 */
#define GET_ORIGIN_NUM(num)  ((num) & (~(1 << 31)))		/*	获取到源数据  */
#define GET_SYMBOL_BIT(num)  (((num) >> 31) & 1)		/*  获取符号位(标识)*/

class Solution
{
public:
    /*
    思路1 :
        对于每一个数据numbers[i]
        其源数据origin = GET_ORIGIN_NUM(numbers[i])的标识存储在numbers[origin]的符号位
        判断其标识是否为1即可
    */
    bool duplicate(int numbers[], int length, int* duplication)
    {
        *duplication = -1;

        if(CheckValidity(numbers, length) == false)
        {
            return false;
        }
        for(int i = 0; i < length; i++)
        {
            //  当前数字numbers[i]的标识即是numbers[numbers[i]]的符号位
            //  检查numbers[i]
            debug <<"origin = " <<GET_ORIGIN_NUM(numbers[i]) <<", flag = " <<GET_SYMBOL_BIT(numbers[GET_ORIGIN_NUM(numbers[i])]) <<endl;
            if(GET_SYMBOL_BIT(numbers[GET_ORIGIN_NUM(numbers[i])]) == 1)
            {
                *duplication = GET_ORIGIN_NUM(numbers[i]);
                return true;
            }
            else
            {
                SET_SYMBOL_BIT(numbers[GET_ORIGIN_NUM(numbers[i])]);
                debug <<"SET origin = " <<GET_ORIGIN_NUM(numbers[i]) <<", flag = " <<GET_SYMBOL_BIT(numbers[GET_ORIGIN_NUM(numbers[i])]) <<endl;
            }
        }

        return false;
    }

    bool CheckValidity(int *numbers, int length)
    {
        //  输入数据不合法
        if(numbers == NULL || length <= 0)
        {
            return false;
        }

        //  元素必须在[0, n-1]的范围
        for(int i = 0; i < length; i++)
        {
            if(numbers[i] < 0 || numbers[i] > length - 1)
            {
                return false;
            }
        }

        return true;
    }

};


int __tmain( )
{
    Solution solu;
    int result;

    int array[] = { 2, 1, 3, 1, 4};
    //int array[] = { 2, 1, 3, 0, 4 };
    if(solu.duplicate(array, 5, &result) == true)
    {
        cout <<result <<endl;
    }

    return 0;
}
