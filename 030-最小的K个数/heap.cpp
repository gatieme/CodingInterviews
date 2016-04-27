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
protected:
    vector<int> m_res;
public:

    vector<int> GetLeastNumbers_Solution(vector<int> numbers, int k)
    {
        m_res.clear( );
        LeastKNumbers_ByMinHeap(numbers, k);
        return m_res;
    }

    ///  排序后输出前K个数字
    vector<int> LeastKNumbers_BySort(vector<int> numbers, int k)
    {
        debug <<endl <<"line " <<__LINE__ <<"in function : "<<__func__ <<endl <<endl;

        vector<int> res;

        sort(numbers.begin( ), numbers.end( ));
        for(int i = 0; i < k; i++)
        {
            debug <<numbers[i] <<" ";
            res.push_back(numbers[i]);
        }
        debug <<endl;

        return res;
    }

    vector<int> LeastKNumbers_ByMinHeap(vector<int> numbers, int k)
    {
        make_heap(numbers.begin( ), numbers.end( ), greater_class());

        for(int i = 0; i < k; i++)
        {

            //  最小的元素在栈顶
            debug <<numbers[0] <<" ";
            m_res.push_back(numbers[0]);

            ///  一下两种操作均可以
            // [1]  --  清除它, 然后重新排序堆
            //numbers.erase(numbers.begin( ));
            //sort_heap(numbers.begin( ), numbers.end( ));

            // [2]  --  当然从堆出弹出这个栈顶元素
            pop_heap(numbers.begin( ), numbers.end( ), greater_class( ));   // 弹出一个元素后，剩下的又重建了 heap，仍保持heap的性质
            numbers.pop_back();         // vector 删除末尾元素
        }
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
