#include <iostream>
#include <vector>
#include <iterator>

#include <climits>

using namespace std;


#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain


class Solution
{
    int dp[1000];
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
        int start, end;
#endif  // __tmain

        int maxSum = INT_MIN;
        dp[0] = array[0];
#ifdef  __tmain
        start = 0;
        //debug <<"start = " <<0 <<endl;
#endif  // __tmain

        for(int i = 1; i < array.size( ); i++)
        {
            debug <<"dp[" <<i - 1 <<"] = " <<dp[i - 1] <<endl;
            if(dp[i - 1] <= 0)
            {
                dp[i] = array[i];
#ifdef __tmain
                //debug <<"start = " <<i <<endl;
                start = i;
#endif  // __tmain
            }
            else        // 否则累加 > 0, 继续与下一个数累加
            {
                dp[i] = array[i] + dp[i - 1];
            }

            //  判断当前最大值
            if(dp[i] > maxSum)
            {
                maxSum = dp[i];
#ifdef __tmain
                end = i;
                //debug <<"end = " <<i <<endl;
                debug <<"[" <<start <<", " <<end <<"] = " <<maxSum <<endl;
#endif  // __tmain
            }
        }

        return maxSum;
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
