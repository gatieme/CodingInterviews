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

        sort(numbers.begin( ), numbers.end( ));

        int res = 0;
        int count = 1;
        for(int i = 0; i < numbers.size( ) - 1; i++)
        {
            if(numbers[i] == numbers[i + 1])
            {
                count++;        //  numbers[i]又在下一个位置i + 1出现了
            }
            else                //  i是numbers[i]是最后出现的位置了
            {
                debug <<numbers[i] <<", count = " <<count <<endl;
                count = 1;
            }
            ///  最后一个数的个数需要特殊处理下
#ifdef __tmain
            if(i == numbers.size( ) - 2)
            {
                debug <<numbers[i + 1] <<", count = " <<count <<endl;
            }
#endif // __tmain

            /// 个数超过数组的一半时候说明已经找到了，就终止
            if(count > numbers.size( ) / 2)
            {
                res = numbers[i];
                break;
            }
        }

        ///
        ///   如果数组中必然存在那个出现次超过一班的数字
        ///   那么我们直接返回numbers[numbers.size( ) / 2]就可以
        ///   但是我们这里这个数可能不存在, 因此需要统计
        ///
        return res;
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
