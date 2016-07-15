#include <iostream>
#include <vector>
#include <queue>
#include <iterator>


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
    typedef pair<int,int> Pair;
public :
    vector<int> maxInWindows(const vector<int> &num, unsigned int size)
    {
        vector<int> result;
        priority_queue<Pair> Q;
        if (num.size() < size || size < 1)
        {
            return result;
        }

        for (int i = 0; i < size-1; i++)
        {
            Q.push(Pair(num[i],i));
        }

        for (int i = size-1; i < num.size(); i++)
        {
            Q.push(Pair(num[i],i));
            Pair p = Q.top();
            while(p.second < i-(size-1)) {
                Q.pop();
                p = Q.top();
            }
            result.push_back(p.first);
        }
//        result.push_back(Q.top().first);
        return result;
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
