#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

class Solution {
public:
	/*
	step1：最后一个为根节点；
	step2：从根节点的左边开始往前遍历，找到第一个比它大的节点作为右子树，记为right
	step3：从右子树的左边开始往前遍历，找到第一个比它小的节点作为左子树，记为left
	step4：判断( left, right )中的值是否都比根节点大，如果有比根节点小的则返回false
	step5: 判断( 0, left )中的值是否都比根节点小，如果有比根节点大的则返回false
	step6: 返回true

	时间复杂度：O(n), 空间复杂度: O(1)
	没有证明过，但是代码通过了，求反例，心里没底
	*/
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty()) return true;
		int len = sequence.size();

		int left = -1, right = -1;
		for (int i = len - 2; i >= 0; --i)
		{
			if (right == -1 && sequence[i] > sequence[len - 1])
                right = i;
			if (left == -1 && sequence[i] < sequence[len - 1])
                left = i;
		}
        cout <<"left = " <<left <<", right = " <<right <<endl;
		for (int i = right - 1; i > left; --i)
        {
            if (sequence[i] < sequence[len - 1])
            {
                return false;
            }
        }
		for (int i = left - 1; i > 0; --i)
		{
			if (sequence[i] > sequence[len - 1])
            {

                return false;
            }

        }
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
