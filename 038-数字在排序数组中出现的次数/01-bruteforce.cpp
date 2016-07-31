#include <iostream>
#include <vector>


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

    int GetNumberOfK(vector<int> data,int k)
    {
        if(data.size( ) == 0)
        {
            return 0;
        }

        int count = 0;
        for(unsigned int i = 0;
            i < data.size( ) && data[i] <= k;
            i++)
        {
            if(data[i] == k)
            {
                count++;
            }
        }

        return count;
    }
};

int __tmain( )
{
    Solution solu;

    int arr[] = { 1, 2, 3, 3, 3, 3, 5, 6 };
    vector<int> vec(arr, arr + 8);
    cout <<solu.GetNumberOfK(vec, 3) <<endl;

    return 0;
}
