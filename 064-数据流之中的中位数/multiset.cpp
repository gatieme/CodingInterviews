#include <iostream>
#include <vector>
#include <set>

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
    vector<int> GetMedian(vector<int> &nums)
    {
        multiset<int> left, right;
        vector<int> res;
        bool flag = true;
    }

    void Insert(int n)
    {
        int tmp = n;
        if (flag)
        {
                if (!right.empty() && n > *right.begin())
                {
                    right.insert(n);
                    tmp = *right.begin();
                    right.erase(right.find(tmp));
                }
                left.insert(tmp);
            }
            else
            {
                if (!left.empty() && n < *left.rbegin())
                {
                    left.insert(n);
                    tmp = *left.rbegin();
                    left.erase(left.find(tmp));
                }
                right.insert(tmp);
            }
            flag = !flag;
            res.push_back(*left.rbegin());
        }
        return res;
    }
};


int __tmain( )
{
    Solution s;
    int array[] = {5, 2, 3, 4, 1, 6, 7, 0, 8};
    vector<int> vec(array, array + 9);

    cout << s.GetMedian( ) << endl;
    return 0;
}
