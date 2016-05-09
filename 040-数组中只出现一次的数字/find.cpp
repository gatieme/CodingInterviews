#include <iostream>

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
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
    {

    }
};


int __tmain( )
{
    debug <<"test" <<endl;
    return 0;
}
