#include <iostream>
#include <vector>
#include <deque>
#include <iterator>

#include <climits>

using namespace std;


//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

/*  单调队列，O(n)
 *  引用马客（Mark）的解题思路，马客没加注释，我用自己的理解加下注释，希望对你们有用，
 *  如有错误，见谅，我会及时修改
 *  deque s中存储的是num的下标  */

class Solution
{
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        if(num.size() == 0 || size == 0)
        {
            return res;
        }

        for(int start = 0;
            start <= (int)(num.size( ) - size);
            start++)
        {
            int end = start + size;
            int max = INT_MIN;
            for(int index = start; index < end; index++)
            {
                if(num[index] > max)
                {
                    max = num[index];
                }
            }

            debug <<"[" <<start <<", " <<end <<"], max = " <<max <<endl;
            res.push_back(max);
        }

        return res;
    }

};



int __tmain( )
{
    Solution solu;

    int array[] = { 2, 3, 4, 2, 6, 2, 5, 1 };
    vector<int> vec(array, array + 8);

    vector<int> res = solu.maxInWindows(vec, 3);
    copy(res.begin( ), res.end( ), ostream_iterator<int>(cout," "));

    return 0;
}
