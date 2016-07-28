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
    class greater_class
    {
      public:
        bool operator()(int a, int b)
        {
            return a > b;
        }
    };

    vector<int> GetLeastNumbers_Solution(vector<int> numbers, int k)
    {
        return LeastKNumbers_ByMinHeap(numbers, k);
    }

    vector<int> LeastKNumbers_ByMinHeap(vector<int> numbers, int k)
    {
        vector<int> res;

        if(numbers.size( ) == 0 || numbers.size( ) < k)
        {
            return res;
        }
        make_heap(numbers.begin( ), numbers.end( ), greater_class());

        for(int i = 0; i < k; i++)
        {

            //  最小的元素在栈顶
            debug <<numbers[0] <<" ";
            res.push_back(numbers[0]);

            ///  一下两种操作均可以
            // [1]  --  清除它, 然后重新排序堆
            //numbers.erase(numbers.begin( ));
            //sort_heap(numbers.begin( ), numbers.end( ));

            // [2]  --  当然从堆出弹出这个栈顶元素
            pop_heap(numbers.begin( ), numbers.end( ), greater_class( ));   // 弹出一个元素后，剩下的又重建了 heap，仍保持heap的性质
            numbers.pop_back();         // vector 删除末尾元素

        }

        return res;
    }


};


int __tmain( )
{

    int arr[ ] = { 4, 5, 1, 6, 2, 7, 3, 8 };
    std::vector<int> vec(arr, arr + 8);

    Solution solu;
    solu.GetLeastNumbers_Solution(vec, 4);
    return 0;
}
