#include <iostream>
#include <vector>
#include <set>


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
    int GetNumberOfK(vector<int> data ,int k)
    {
        multiset<int> mData;
        for(int i = 0; i < data.size( ); i++)
        {
            mData.insert(data[i]);
        }

        return mData.count(k);
    }
};

int __tmain( )
{
    Solution solu;

    int arr[] = { 1, 2, 3, 3, 3, 3, 4, 5 };
    vector<int> vec(arr, arr + 8);
    cout <<solu.GetNumberOfK(vec, 3) <<endl;

    return 0;
}
