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

        int count = 0;
        for(unsigned int i = 0; i < elem.size( ); i++)  /// 循环每一个位置的数据
        {
            for(unsigned int j = i + 1; j < elem.size( ); j++)  /// 依次判断后面的数据与当前位置数据是否是逆序
            {
                if(elem[i] > elem[j])
                {
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

    int arr[] = { 7, 5, 6, 4 };
    vector<int> vec(arr, arr + 4);

    cout <<solu.InversePairs(vec) <<endl;
    return 0;
}
