#include <iostream>
#include <vector>


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

public :

    vector<int> FindNumbersWithSum(vector<int> array,int sum)
    {
        vector<int> res;

        if (array.size( ) < 2)
        {
            return res;
        }

        int start = 0, end = array.size( ) - 1;
        long curSum;

        while (start < end)
        {
            curSum = array[start] + array[end];

            if (curSum == sum)
            {
                ///  左右夹逼
                ///  同时能保证乘积最小的
                /// 和为sum的最大的两个数最接近sqrt(sum)
                res.push_back(array[start]);
                res.push_back(array[end]);

                break;
            }
            else if (curSum < sum)
            {
                start++;
            }
            else
            {
                end--;
            }
        }

        return res;
    }
};

int __tmain( )
{
    debug <<"test" <<endl;
    return 0;
}
