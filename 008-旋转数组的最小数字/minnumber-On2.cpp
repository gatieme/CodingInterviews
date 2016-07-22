#include <iostream>
#include <vector>
using namespace std;

//  调试开关
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
        for(int i = 0; i < rotateArray.size( ); i++)
        {
            //  最大的元素后面哪个就是最小的元素
            if(rotateArray[i] > rotateArray[i + 1])
            {
                return rotateArray[i + 1];
            }
        }
        //  否则的话, 旋转次数为0, 第一个元素即是最小元素
        return rotateArray[0];
    }

    int minNumberInRotateArray(int* rotateArray, int length)
    {
        int low = 0, high = length - 1;

        while(low < high)
        {
            if(rotateArray[low] < rotateArray[high])
            {

            }
        }

    }
};


int __tmain( )
{
    dout <<"test" <<endl;
    return 0;
}
