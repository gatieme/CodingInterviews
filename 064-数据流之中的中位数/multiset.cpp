#include <iostream>
#include <vector>
#include <set>
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
protected :
    multiset<int>   left;       /*  左半部分  */
    multiset<int>   right;      /*  右半部分  */

public    :

    void Insert(int n)
    {
        int tmp = n;
        if(((left.size( ) + right.size( )) & 1) == 0)
        {
            if (right.empty( ) != true && n > *right.begin())
            {
                right.insert(n);
                tmp = *right.begin( );
                right.erase(right.find(tmp));
            }
            left.insert(tmp);
        }
        else
        {
            if (left.empty() != true && n < *left.rbegin())
            {
                left.insert(n);
                tmp = *left.rbegin();
                left.erase(left.find(tmp));
            }
            right.insert(tmp);
        }

    }

    double GetMedian( )
    {
#ifdef __tmain
        cout <<"left[" <<left.size( ) <<"] : ";
        copy(left.begin( ), left.end( ), ostream_iterator<int>(cout," "));
        cout <<"right[" <<right.size( ) <<"] : ";
        copy(right.begin( ), right.end( ), ostream_iterator<int>(cout," "));
        cout <<endl;
#endif

        if(((left.size( ) + right.size( )) & 1) == 0)
        {
            debug <<*left.rbegin( ) <<", " <<*right.begin( ) <<endl;
            return (double)(*left.rbegin( ) + *right.begin( )) / 2.0;
        }
        else
        {
            debug <<(double)*left.rbegin( ) <<endl;
            return (double)*left.rbegin( );
        }
    }
};


int __tmain( )
{
    Solution s;
    int array[] = {5, 2, 3, 4, 1, 6, 7, 0, 8};
    vector<int> vec(array, array + 9);

    /*
    vector<int> res = s.GetMedian(vec);
    for(int i = 0; i < (int)res.size( ); i++)
    {
        cout <<res[i];
    }
    cout <<endl;*/

    for (int i = 0; i < (int)vec.size( ); i++)
    {
        s.Insert(vec[i]);
        cout << s.GetMedian( ) << endl;
    }

    return 0;
}
