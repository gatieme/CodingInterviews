#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

class Solution
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
//        return numbers.empty( ) ? 0 : *find_if(numbers.begin( ), numbers.end( ),[numbers](int x)
//            {
//                return (count(numbers.begin( ),numbers.end( ), x) * 2) > numbers.size();
//            });

        if(numbers.size( ) == 0)
        {
            return 0;
        }
        for(int i = 0 ; i < numbers.size( ); i++)
        {
            debug <<"num = " <<numbers[i] <<", count = " <<count(numbers.begin( ), numbers.end( ), numbers[i]) <<endl;
            if(count(numbers.begin( ), numbers.end( ), numbers[i]) * 2 > numbers.size( ))
            {
                return numbers[i];
            }
        }
        return 0;
    }
};


int __tmain( )
{
    int arr1[] = { 5, 5, 2, 2, 3, 3, 5, 5, 5};

    vector<int> vec1(arr1, arr1 + 9);

    Solution solu;
    cout <<solu.MoreThanHalfNum_Solution(vec1) <<endl;


    int arr2[] = { 1, 2 };

    vector<int> vec2(arr2, arr2 + 2);
    cout <<solu.MoreThanHalfNum_Solution(vec2) <<endl;

    return 0;
}
