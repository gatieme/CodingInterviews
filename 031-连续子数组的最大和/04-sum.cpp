#include <iostream>
#include <vector>

#include <climits>

using namespace std;

//  µ÷ÊÔ¿ª¹Ø
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

        int sum = 0, maxSum = INT_MIN;
        for(unsigned int i = 0; i < array.size( ); i++)
        {
            if(sum <= 0)
            {
                sum = array[i];
            }
            else
            {
                sum += array[i];
            }
            debug <<"num = " <<array[i] <<", sum = " <<sum <<endl;

            if(sum > maxSum)
            {
                maxSum = sum;
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
