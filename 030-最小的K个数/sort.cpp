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
//        m_res.clear( );
//        LeastKNumbers_BySort(numbers, k);
//
//        m_res.clear( );
//        LeastKNumbers_BySelectSort(numbers, k);
//
//        m_res.clear( );
//        LeastKNumbers_ByBubbleSort(numbers, k);

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

    ///  采用选择排序法, K趟找出前K个数字
    ///  由于选择排序每趟结束后前i个数字都有序，因此K趟即可找出前K小的数字
    vector<int> LeastKNumbers_BySelectSort(vector<int> numbers, int k)
    {
        debug <<endl <<"line " <<__LINE__ <<" in function : "<<__func__ <<endl <<endl;

        vector<int> res;

        int i, j, index;
        int length = numbers.size( ) -1;
        for(i = 0; i < k/*length*/; i++)             // 循环每趟排序
        {
            index = i;
            for(j = i + 1; j < length; j++)
            {
                if(numbers[j] < numbers[index])
                {
                    index  = j;                 // 找到当前极值元素的下标
                }
            }
            if(index != i)
            {
                swap(numbers[i], numbers[index]);     // 将极值保存到应该填入的位置
            }
            m_res.push_back(numbers[i]);

#ifdef __tmain

            debug <<"pos = " <<index <<", num = " <<numbers[i] <<endl;
            debug <<"when " <<i <<" select sort, the least " <<i <<" numbers is sorted" <<endl;

            for(int pos = 0; pos <= i; pos++)
            {
                debug <<numbers[pos] <<" ";
            }
            debug <<endl;

#endif  //  __tmain

        }

        return m_res;
    }

    ///  采用冒泡排序法, K趟找出前K个数字
    vector<int> LeastKNumbers_ByBubbleSort(vector<int> numbers, int k)
    {
        debug <<endl <<"line " <<__LINE__ <<" in function : "<<__func__ <<endl <<endl;

        int j/*控制每趟循环*/, i/*控制相邻数据的比较循环*/;
        // 排序过程
        int length = numbers.size( );
        for(i = 0; i < k/*length - 1*/; i++)        // 共计进行length-1趟循环
        {
            for(j = length - i - 1; j > 0; j--)   // 每趟循环比较length-1-j次
            {
                if(numbers[j - 1] > numbers[j])    // 如果当前的元素与后一个元素不满足排序规则
                {
                    swap(numbers[j - 1], numbers[j]);
                }

            }
            m_res.push_back(numbers[i]);

#ifdef __tmain
            debug <<"pos = " <<i <<", num = " <<numbers[i] <<endl;
            debug <<"when " <<i <<" bubble sort, the least " <<i <<" numbers is sorted" <<endl;

            for(int pos = 0; pos <= i; pos++)
            {
                debug <<numbers[pos] <<" ";
            }
            debug <<endl;

#endif  //  __tmain
        }

        return m_res;
    }

    class greater_class
    {
    public:
        bool operator()(int a, int b)
        {
            return a > b;
        }
    };


};


int __tmain( )
{

    int arr[ ] = { 4, 5, 1, 6, 2, 7, 3, 8 };
    std::vector<int> vec(arr, arr + 8);

    Solution solu;
    solu.GetLeastNumbers_Solution(vec, 4);
    return 0;
}
