#include <iostream>
#include <vector>
#include <algorithm>

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
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if(numbers.size( ) == 0)
        {
            return 0;
        }
        else if(numbers.size( ) == 1)
        {
            return numbers[0];
        }

        int num = numbers[0], count = 1;

        //  阵地攻守
        for(int i = 1; i < numbers.size( ); i++)
        {
            if(numbers[i] == num)    /// 友军, 计数器增加
            {
                count++;
            }
            else                    /// 敌军, 一个士兵同归于尽
            {
                count--;
            }
            debug <<"numbers[i] = " <<numbers[i] <<", count = " <<count <<endl;

            // 所有士兵已经阵亡
            if(count == 0)
            {
                num = numbers[i];    //  重新设置镇守阵地的士兵
                count = 1;
            }
        }

        debug <<"find num = " <<num <<endl;
        ///  再加一次循环，记录这个士兵的个数看是否大于数组一般即可
        count = 0;
        for(int i = 0; i < numbers.size( ); i++)
        {
            if(numbers[i] == num)
            {
                count++;
            }
        }

        if(count > numbers.size( ) / 2)
        {
            debug <<"num = " <<num <<", count = " <<count <<endl;
            return num;
        }
        else
        {
            return 0;
        }
    }
};


int __tmain( )
{
    int arr1[] = { 5, 5, 2, 2, 3, 3, 5, 5, 5};

    vector<int> vec1(arr1, arr1 + 9);

    Solution solu;
    cout <<solu.MoreThanHalfNum_Solution(vec1) <<endl;


    int arr2[] = { 1, 2 };

    vector<int> vec2(arr2, arr2 + 2);
    cout <<solu.MoreThanHalfNum_Solution(vec2) <<endl;
    return 0;
}
