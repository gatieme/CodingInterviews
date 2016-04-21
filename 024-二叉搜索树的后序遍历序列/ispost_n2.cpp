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
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if(sequence.size( ) == 0)
        {
            return false;
        }
        int count = 0;
        int left = 0, right = sequence.size( ) - 1;
        while(right > 0)
        {
            //  前一半的元素都小于size
            while(sequence[left] < sequence[right])
            {
                left++;
                count++;

            }
            // 循环结束时, left是第一个大于根的元素的位置
            // 其后面的元素都应该比根大
            while(sequence[left] > sequence[right])
            {
                left++;
                count++;
            }
            //  正常情况下, 循环结束时, left应该等于right
            debug <<left <<" " <<right <<endl;
            if(left < right)
            {
                return false;
            }
            right--;
            left = 0;
        }
        cout <<count <<endl;
        //  如果循环一直走到right == 0才终止, 说明满足后序遍历的定义
        return true;
    }
};


int __tmain( )
{
//     10
//   6    14
//  8   12  16
//4



    int a[] = { 2, 9, 5, 16, 17, 15, 19, 18, 12, };

    vector<int> vec(a, a + 9);

    Solution solu;
    cout <<solu.VerifySquenceOfBST(vec) <<endl;
    return 0;
}
