#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

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
        map<int, int> hmap;  //  建立数字到出现次数的映射

        int nsize = numbers.size( );

        for(int i = 0; i < nsize; i++)
        {
            if(hmap.find(numbers[i]) != hmap.end( ))
            {
                hmap[numbers[i]] += 1;
            }
            else
            {
                hmap[numbers[i]] = 1;
            }
        }

        //  查找到出现次数最多的那个元素
        for(map<int,int>::iterator it = hmap.begin( );
            it != hmap.end( );
            ++it)
        {
            debug <<it->first <<", " <<it->second <<endl;
            if(it->second * 2 > nsize)
            {
                return it->first;
            }
        }
        return 0;
    }
};


int __tmain( )
{
    int arr1[] = { 1,2,3,2,2,2,5,4,2};

    vector<int> vec1(arr1, arr1 + 9);

    Solution solu;
    cout <<solu.MoreThanHalfNum_Solution(vec1) <<endl;


    int arr2[] = { 1, 2 };

    vector<int> vec2(arr2, arr2 + 2);
    cout <<solu.MoreThanHalfNum_Solution(vec2) <<endl;

    return 0;
}
