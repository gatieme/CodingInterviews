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
public :
    typedef pair<int, int> Pair;

    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int>             res;
        if(size == 0 || num.size( ) == 0 || size > num.size( ))
        {
            return res;
        }

        priority_queue<Pair>    Q;     //优先级队列保存窗口里面的值
        for (int i = 0; i < size; i++)
        {
            Q.push(Pair(num[i], i));  //构建size个元素的最大堆
        }

        for (int i = size;
            i < num.size( );
            i++)
        {
            //Q.push(Pair(num[i], i));  //构建size个元素的最大堆
            Pair p = Q.top( );
            res.push_back(p.first); //res[i - size] = p.first;
            while (p.second <= (i - size))
            {
                Q.pop( );
                p = Q.top( );
            }
            Q.push(Pair(num[i], i));  //res[num.size( ) - size] = Q.top( ).first;
        }
        res.push_back(Q.top( ).first);  //res[num.size( ) - size] = Q.top( ).first;

        return res;
    }
};

int __tmain( )
{
    Solution solu;

    int array[] = { 2, 3, 4, 6};
    vector<int> vec(array, array + 4);

    vector<int> res = solu.maxInWindows(vec, 3);
    copy(res.begin( ), res.end( ), ostream_iterator<int>(cout," "));

    return 0;
}
