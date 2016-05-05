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
public:
    int InversePairs(vector<int> elem)
    {
        if(elem.size( ) == 0)
        {
            return 0;
        }

        return BubbleSort(elem);
    }

    int BubbleSort(vector<int> elem)
    {
        bool flag = true;
        int count = 0;
        unsigned int length = elem.size( );

        for(unsigned int i = 0;
            i < length - 1 && flag == true;
            i++)  // 共计进行length-1趟循环
        {
            flag = false;           // 初始默认数据是无序的
            for(unsigned int j = 0;
                j < length - i - 1;
                j++)   // 每趟循环比较length-1-j次
            {
                if(elem[j] > elem[j + 1])    // 如果当前的元素与后一个元素不满足排序规则
                {
                    swap(elem[j], elem[j+1]);
                    flag = true;  // 仍然需要交换说明, 仍然无序
                    count++;
                }
            }
        }

        return count;
    }
};

int __tmain( )
{
    Solution solu;

    int arr[] = { 1,2,3,4,7,6,5 };
    vector<int> vec(arr, arr + 7);

    cout <<solu.BubbleSort(vec) <<endl;
    return 0;
}
