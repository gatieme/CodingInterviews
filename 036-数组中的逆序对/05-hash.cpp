#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain


class Solution
{

    /*
    我的解法是O(10*n)，剑指offer是O(nlogn)

    思路如下：
    借助一个数组hash，统计array从后往前，到第i位时候，i后面每个数字出现的次数

    1. 从后往前遍历array， hash数组记录数字array[i]已出现的次数

    2. 对于数字array[i]，统计 array[x](此处 x>i)的的部分，小于array[i]的数字总数 count
      count 等于hash数组中 hash[x]的和（此处 x < array[i]）

    3. count即为 array 数组中， 以第i位开头往后的子数组的逆序数
    */

public  :
    int InversePairs(vector<int> array)
    {
        if(array.size( ) == 0)
        {
            return 0;
        }

        vector<int> hash(10/* 数据的最大值*/);
        int i = array.size( ) - 1;

        int count = 0;

        for(i = array.size( ) - 1;
            i >= 0;
            i--)
        {
            hash[array[i]]++;   //  hash表存储了当前元素位置i的后面所有数字出现的次数

            // 统计后面出现的数字中小于当前位置元素array[i]出现的次数
            // 其实就是当前位置i上元素的逆序次数
            // 后面的数组应该都比array[i]大
            // 而比array[i]小的元素出现在i位置后面
            // 很明显都应该是逆序
            for(int j = 0; j < array[i]; j++)
            {
                count += hash[j];
            }
        }

        return count;
    }
};



int __tmain( )
{
    Solution solu;

    int arr[] = { 7, 5, 6, 4 };
    vector<int> vec(arr, arr + 4);

    cout <<solu.InversePairs(vec) <<endl;

    return 0;
}
