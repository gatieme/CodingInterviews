#include <iostream>
#include <vector>
#include <queue>
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

        queue<int>      window;
        queue<int>      max;
        for(int i = 0; i < (int)num.size( ); i++)
        {
            if(window.size( ) < size)
            {
                window.push(num[i]);
            }
            else
            {
                /*  最前面元素划出窗口  */
                window.pop( );
                max.pop( );

                /*  新元素入队  */
                window.push(num[i]);
                if(num[i] > max.back( ))
                {
                    max.push(num[i]);
                }
                else
                {
                    max.push(max.back( ));
                }
            }
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
