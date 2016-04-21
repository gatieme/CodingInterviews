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

        return judge(sequence, 0, sequence.size( ) - 1);
    }

    /// 2, 9, 5, 16, 17, 15, 19, 18, 12
    bool judge(vector<int>  &sequence, int left, int right)
    {
        if(left >= right)
        {
            return true;
        }

        /// 后一半的元素都比根元素大
        int mid = right - 1;
        while (sequence[mid] > sequence[right])
        {
            mid--;
        }
        /// 那么前面的元素都应该比根小
        int i = left;
        while (i < mid && sequence[i] < sequence[right])
        {
            i++;
        }
        if (i < mid)
        {
            return false;
        }
#ifdef __tmain
        printf("left : ");
        for(int i = left; i <= mid; i++)
        {
            cout <<sequence[i] <<" ";
        }
        cout <<endl;
        printf("right : ");
        for(int i = mid + 1; i < right; i++)
        {
            cout <<sequence[i] <<" ";
        }
        cout <<endl;
        cout <<"root : " <<sequence[right] <<endl;
#endif // __tmain

        ///  这样我们就划分出区间
        ///  [left, mid] 是左子树
        ///  [mid + 1, right - 1] 是右子树
        ///  right 是根节点
        return judge(sequence, left, mid) && judge(sequence, mid + 1, right - 1);
    }
};


int __tmain( )
{

    int a[] = { 2, 9, 5, 16, 17, 15, 19, 18, 12, };

    vector<int> vec(a, a + 9);

    Solution solu;
    cout <<solu.VerifySquenceOfBST(vec) <<endl;
    return 0;
}
