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
    int GetNumberOfK(vector<int> data ,int k)
    {
        int upper = upper_bound(data.begin(),data.end(),k)£»
        int low = lower_bound(data.begin(),data.end(),k);
        return upper - low;
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
