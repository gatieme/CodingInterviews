#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//  µ÷ÊÔ¿ª¹Ø
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
        int left = 0, right = sequence.size( ) - 1;
        while(left < right && right != 0)
        {
            //  前一半的元素都小于size
            while(sequence[left] < sequence[right])
            {
                left++;
            }
            // 循环结束时, left是第一个大于根的元素的位置
            //
            while(sequence[left] > sequence[right])
            {
                left++;
            }

            right--;
        }

        //  如果循环一直走到right == 0才终止, 说明满足后序遍历的定义
        if(right == 0)
        {
            return true;
        }
        else            //  否则说明不满足递归的定义
        {
            return false;
        }


    }
};


int __tmain( )
{
//     10
//   6    14
//  8   12  16
//4




    int a[] = { 1, 2, 3 };

    vector<int> vec(a, a + 3);

    Solution solu;
    cout <<solu.VerifySquenceOfBST(vec) <<endl;
    return 0;
}
