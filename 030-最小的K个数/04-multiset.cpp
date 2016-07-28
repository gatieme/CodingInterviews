#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator> //istream_iterator,ostream_iterator,back_inserter

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
    vector<int> GetLeastNumbers_Solution(vector<int> numbers, int k)
    {
        return LeastKNumbers_ByMultisetGreater(numbers, k);
    }

    vector<int> LeastKNumbers_ByMultisetGreater(vector<int> numbers, unsigned int k)
    {
        vector<int> res;

        if(numbers.size( ) ==0 || numbers.size( ) < k)
        {
            return res;
        }

        multiset< int, greater<int> >               leastSet;
        multiset< int, greater<int> >::iterator     leastIter;
        for(vector<int>::iterator iter = numbers.begin( );
            iter != numbers.end( );
            iter++)
        {
            if(leastSet.size( ) < k)
            {
                leastSet.insert(*iter);
            }
            else
            {
                leastIter = leastSet.begin( );
                if(*iter < *leastIter)
                {
                    leastSet.erase(leastIter);
                    leastSet.insert(*iter);
                }
            }
        }

        debug <<"set = ";
        copy(leastSet.begin( ), leastSet.end( ), ostream_iterator<int>(cout," "));
        debug <<endl <<"res = ";
        for(leastIter = --leastSet.end( );
            leastIter != --leastSet.begin( );
            leastIter--)
        {
            res.push_back(*leastIter);
        }

        return res;
    }



    vector<int> LeastKNumbers_ByMultisetLess(vector<int> numbers, unsigned int k)
    {
        vector<int> res;

        if(numbers.size( ) == 0 || numbers.size( ) < k)
        {
            return res;
        }

        multiset< int, less<int> >               leastSet;
        multiset< int, less<int> >::iterator     leastIter;
        for(vector<int>::iterator iter = numbers.begin( );
            iter != numbers.end( );
            iter++)
        {
            if(leastSet.size( ) < k)
            {
                leastSet.insert(*iter);
            }
            else
            {
                leastIter = --leastSet.end( );
                if(*iter < *leastIter)
                {
                    leastSet.erase(leastIter);
                    leastSet.insert(*iter);
                }
            }
        }
        debug <<"set = ";
        copy(leastSet.begin( ), leastSet.end( ), ostream_iterator<int>(cout," "));
        debug <<endl <<"res = ";
        for(leastIter = leastSet.begin( );
            leastIter != leastSet.end( );
            leastIter++)
        {
            res.push_back(*leastIter);
        }

        return res;
    }
};


int __tmain( )
{

    int arr[ ] = { 4, 5, 1, 6, 2, 7, 3, 8 };
    std::vector<int>    vec(arr, arr + 8);

    vector<int>         res;

    Solution solu;

    cout <<"MultiSet Greater : " <<endl;
    res = solu.LeastKNumbers_ByMultisetGreater(vec, 4);
    copy(res.begin( ), res.end(), ostream_iterator<int>(cout," "));
    cout <<endl;

    cout <<"MultiSet Less    : " <<endl;
    res = solu.LeastKNumbers_ByMultisetLess(vec, 4);
    copy(res.begin( ), res.end(), ostream_iterator<int>(cout," "));
    cout <<endl;

    return 0;
}
