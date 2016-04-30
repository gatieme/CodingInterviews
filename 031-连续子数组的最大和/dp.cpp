#include <iostream>
#include <vector>

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
        int temp, start, end;
#endif  // __tmain

        int maxSum = INT_MIN;
        dp[0] = array[0];
        
        for(unsigned int i = 1; i < array.size( ); i++)
        {
            if(dp[i - 1] <= 0)
            {
                dp[i] = array[i];
#ifdef __tmain
                temp = i;
#endif  // __tmain
            }
            else
            {
                dp[i] = array[i] + dp[i - 1];
            }
            
            if(dp[i] > maxSum)
            {
                maxSum = dp[i];
#ifdef __tmain
                start = temp;
                end = i;
#endif  // __tmain
            }        
        }

        debug <<"[" <<start <<", " <<end <<"] = " <<maxSum <<endl;
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
