#include <iostream>
#include <vector>
using namespace std;

//  µ÷ÊÔ¿ª¹Ø
#define __tmain main


#ifdef __tmain
    #define dout cout
#else
    #define dout 0 && cout
#endif // __tmain


class Solution
{
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        if(rotateArray.size() == 0)
        {
            return 0;
        }

        int min = INT_MAX;
        for(int i = 0; i < rotateArray.size( ); i++)
        {
            if(rotateArray[i] < min)
            {
                min = rotateArray[i];
            }
        }
        return min;
    }


};


int __tmain( )
{

    int a[] = { 3, 4, 5, 1, 2 };
    vector<int> vec(a, a + 5);

    Solution solu;
    cout <<solu.minNumberInRotateArray(vec) <<endl;

    return 0;
}
