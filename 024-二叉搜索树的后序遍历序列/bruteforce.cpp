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
    //下面这种迭代的方法时间复杂度为O(n^2)
    bool VerifySquenceOfBST_Iteratively(const vector<int>& sequence) {
		int left = 0, right = sequence.size() - 1;
		while (left < right && right != 0) {
			//循环结束时，left是第一个大于根的元素的位置，即右子树首元素下标
			while (sequence[left] < sequence[right])
				left++;
			//循环结束时，left越过右子树末节点，到达根节点
			while (sequence[left] > sequence[right])
				left++;

			//如果没有到达根节点，说明不满足左子树所有节点小于根节点，右子树所有节点大于根节点的条件
			if (left < right)
				return false;
			left = 0;

			right--;
		}

		//如果循环一直到right == 0才终止, 说明以所有节点为根节点，左侧序列均满足后序遍历序列的条件
		return (right == 0) ? true : false;
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
