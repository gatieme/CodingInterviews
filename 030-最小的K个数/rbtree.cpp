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
protected:
public:


    vector<int> GetLeastNumbers_Solution(vector<int> numbers, int k)
    {
        return LeastKNumbers_ByMinHeap(numbers, k);
    }

    vector<int> LeastKNumbers_ByMinHeap(vector<int> numbers, int k)
    {
        vector<int> res;

        if(numbers.size( ) ==0 || numbers.size( ) < k)
        {
            return res;
        }

        multiset< int, greater<int> > leastSet;
        multiset< int, greater<int> >::iterator leastIter;
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
                if(*iter < *(leastSet.begin( )))
                {
                    leastSet.erase(leastIter);
                    leastSet.insert(*iter);
                }
            }
        }

        //copy(leastSet.begin(),leastSet.end(),ostream_iterator<int>(cout," "));
        for(leastIter = leastSet.end( );
            leastIter != leastSet.begin( );
            leastIter--)
        {
            res.push_back(*leastIter);
        }
        return res;
    }
};


int __tmain( )
{

    int arr[ ] = { 4, 5, 1, 6, 2, 7, 3, 8 };
    std::vector<int> vec(arr, arr + 8);

    Solution solu;
    solu.GetLeastNumbers_Solution(vec, 4);
    return 0;
}
