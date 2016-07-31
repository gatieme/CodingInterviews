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

///////////////////////////////////
// error
///////////////////////////////////
class Solution
{
public:
    //从data末端开始，对每个数进行插入排序 其插入入的位置与其当前位置之差 即为当前数字的逆序个数
    int InversePairs(vector<int> elem)
    {
         // 排序部分
        int i, j, temp;
        int count = 0, length = elem.size( );

        for(i = 1; i < length; i++)      // 循环第1个数据以后的每个数据
        {
            temp = elem[i];         // 保存第i个数据,
            for(j = i - 1; j >= 0 && temp < elem[j]; j--)      // 将比保存的数据都往后移
            {
                elem[j + 1] = elem[j];
                count++;
            }
            // 循环结束后就在有序的0-i的位置中找到了temp应该插入的位置(j + 1)
            elem[j + 1] = temp;         // 将保存的数据插进来
        }

        copy(elem.begin(), elem.end(), ostream_iterator<int>(cout," "));
        return count;
    }
};

int __tmain( )
{
    Solution solu;

    int arr[] = { 7, 6, 5, 4};
    vector<int> vec(arr, arr + 4);

    cout <<solu.InversePairs(vec) <<endl;
    return 0;
}
