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
    bool IsContinuous(vector<int> numbers)
    {
        if(numbers.size( ) == 0)
        {
            return false;
        }
        sort(numbers.begin( ), numbers.end( ));

        /// 统计前面0的个数
        int left = 0;
        while(numbers[left] == 0)
        {
            left++;
        }
        debug <<"left = " <<left <<endl;

        ///  然后看0能不能填补两个数之间的空缺
        for(int i = left + 1; i < numbers.size( ); i++)
        {
            debug <<numbers[i - 1] <<", " <<numbers[i] <<endl;

            // 如果数组中的非0数字重复出现，则该数组不是连续的。
            if(numbers[i] == numbers[i - 1])
            {
                return false;
            }
            else        //  否则填补空缺, 无空缺的情况不用单独判断(空缺为0)
            {
                left -= (numbers[i] - numbers[i - 1] - 1);
            }
        }
        debug <<"left = " <<left <<endl;
        if(left >= 0)
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
