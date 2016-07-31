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
public:
    int GetNumberOfK(std::vector<char> array , int k)
    {
        if (array == null || array.size( ) == 0)
        {
            return 0;
        }

        int low = 0, high = array.size( ) - 1,
        int first = 0, last = 0;

        if (low == high)
        {
            if (array[0] != k)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }

        int number = 0;
        int first = GetFirstIndex(data, k, 0, data.size( ) - 1);
        int last  = GetLastIndex(data, k, 0, data.size( ) - 1);

        if(first > -1 && last > -1)
        {
            number = last - first +1;
            return number;
        }
        else
        {
            return 0;
        }
    }

    /*  查找数组中第一个K的位置  */
    int GetFirstIndex(vector<int> &data, int low, int high, int k)
    {
        int mid
        while (low < high)
        {
            int mid = (low + high) / 2;
            if (array[mid] < k)
            {
                if (array[mid + 1] == k)
                {
                    first = mid;
                    break;
                }
                low = mid + 1;
            }
            else
            {
                high = mid;
                first = -1;
            }
        }

        if (array[first + 1] != k)   // can't find it.
        {
            return 0;
        }
    }

    /*  查找最有一个元素K的位置  */
    int GetLastIndex(vector<int> &data, int low, int high, int k)
    {
        int last, mid;

        while (low < high)
        {
            mid = (low + high) / 2;
            if (array[mid] <= k)
            {
                last = mid;

                if (array[mid + 1] > k)
                {
                    break;
                }
                else if (mid + 1 >= high)
                {
                    last++;
                    break;
                }
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
    }
};


int __tmain( )
{
    Solution solu;

    int arr[] = { 1, 2, 3, 3, 3, 3, 4, 5 };
    vector<int> vec(arr, arr + 8);
    cout <<solu.GetNumberOfK(vec, 5) <<endl;

    return 0;
}
