#include <iostream>
#include <vector>

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
    vector<int> multiply(const vector<int>& A)
    {
        int n = A.size();
        vector<int> res(n);
        // C[i] = A[0] * A[1] * ... *A[i - 1]
        for(int i = 0, temp = 1; i < n; i++)
        {
            res[i] = temp;
            temp *= A[i];
        }

        // D[i] = A[i + 1] * A[i + 2] * ... *A[n - 1]
        for(int i = n - 1, temp = 1; i >= 0; i--)
        {
            res[i] *= temp;
            temp *= A[i];

        }
        return res;
    }
};

int __tmain( )
{
    debug <<"test" <<endl;
    return 0;
}
