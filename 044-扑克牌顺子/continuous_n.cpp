#include <iostream>
#include <vector>
#include <algorithm>

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
    #define BIT_GET(number, pos) ((number) >> (pos) & 1)     /// 用宏得到某数的某位
    #define BIT_SET(number, pos) ((number) |= 1 << (pos))    /// 把某位置1
    #define BIT_CLR(number, pos) ((number) &= ~(1 << (pos))) /// 把某位清0
    #define BIT_CPL(number, pos) ((number) ^= 1 << (pos))    /// 把number的POS位取反

    bool IsContinuous(vector<int> numbers)
    {
        if(numbers.size( ) != 5)
        {
            return false;
        }
        int min = INT_MAX;
        int max = INT_MIN;
        int flag = 0;

        for(int i = 0; i < numbers.size( ); i++)
        {
            int num = numbers[i];

            if(num < 0 || num > 13) //  牌只能在0~13之间
            {
                return false;
            }
            else if(num == 0)       //  0用来答题任何牌，因此不能参与最大最小牌的比对
            {
                continue;
            }

            //  非0元素不能重复
            if(BIT_GET(flag, num) == 1)     //  如果flag的第num位为1, 说明num重复
            {
                debug <<i <<", " <<num <<endl;
                return false;
            }
            else
            {
                BIT_SET(flag, num);     //  将标识flag的第num位置为0
            }
            //  寻找最大最小的牌
            if(num > max)
            {
                max = num;
            }
            if(num < min)
            {
                min = num;
            }
            debug <<"max = " <<max <<", min = " <<min <<endl;

            //  如果最大值和最小值的差值大于4, 那么必应不能补齐
            if(max - min > 4)
            {
                debug <<"max = " <<max <<", min = " <<min <<endl;
                return false;
            }
        }
        return true;


    }
};


int __tmain( )
{
    Solution solu;

    int arr1[] = { 1, 3, 2, 6, 4 };
    vector<int> vec1(arr1, arr1 + 5);
    cout <<solu.IsContinuous(vec1) <<endl;

    int arr2[] = { 3, 5, 1, 0, 4, };
    vector<int> vec2(arr2, arr2 + 5);
    cout <<solu.IsContinuous(vec2) <<endl;

    int arr3[] = { 1, 0, 0, 1, 0 };
    vector<int> vec3(arr3, arr3 + 5);
    cout <<solu.IsContinuous(vec3) <<endl;
    return 0;
}
