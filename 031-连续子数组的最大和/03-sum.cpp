#include <iostream>
#include <vector>

#include <iterator>

#include <climits>


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
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        if(array.size( ) == 0)
        {
            return 0;
        }

#ifdef __tmain
        debug <<"vector : ";
        copy(array.begin( ), array.end( ), ostream_iterator<int>(cout, " "));
        debug <<endl;
#endif  // __tmain

        int maxNum = INT_MIN;
        int sum = 0, maxSum = INT_MIN;
        for(int i = 0; i < (int)array.size( ); i++)
        {
            sum += array[i];
            debug <<sum <<endl;

            if(sum < 0)     ///  如果当前和小于0, 就舍弃它, 重新开始累加
            {
                sum = 0;
            }
            else if(sum > maxSum)   ///  否则的话累计当前和
            {
                maxSum = sum;
            }

            ///  保存数据中的最大值
            ///  这种情况下是为了排除整个数组全为负数的特殊情况
            if(array[i] > maxNum)
            {
                maxNum = array[i];
            }
        }

        ///  如果数组最大值大于0, 那么我们就直接返回累计的最大和
        ///  如果数组最大值为负数, 说明整个数组都是负数, 那么就返回数组最大值
        return (maxNum > 0) ? maxSum : maxNum;
    }
};

int __tmain( )
{


    Solution solu;

    int arr1[] = { 6, -3, -2, 7, -15, 1, 2, 2};
    vector<int> vec1(arr1, arr1 + sizeof(arr1)/sizeof(arr1[0]));
    cout <<"maxSum = " <<solu.FindGreatestSumOfSubArray(vec1) <<endl;

    int arr2[] = { -2, -8, -1, -5, -9 };
    vector<int> vec2(arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]));
    cout <<"maxSum = " <<solu.FindGreatestSumOfSubArray(vec2) <<endl;

    return 0;
}
