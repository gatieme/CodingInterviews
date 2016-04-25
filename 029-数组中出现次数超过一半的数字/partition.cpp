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
    /// 方法一
    /// 注意到目标数 超过数组长度的一半，
    /// 对数组同时去掉两个不同的数字，
    /// 到最后剩下的一个数就是该数字。
    /// 如果剩下两个，那么这两个也是一样的，就是结果），
    /// 在其基础上把最后剩下的一个数字或者两个回到原来数组中，
    /// 将数组遍历一遍统计一下数字出现次数进行最终判断。

    int MoreThanHalfNum_Solution(vector<int> numbers)
    {



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
