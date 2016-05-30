#include <iostream>
#include <set>
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
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication)
    {
        *duplication = -1;

        if(CheckValidity(numbers, length) == false)
        {
            return false;
        }

        for(int i = 0; i < length; i++)
        {
            if(numbers[numbers[i] % length] >= length)
            {
                *duplication = numbers[i] % length;
                return true;
            }
            else
            {
                numbers[numbers[i] % length] += length;
            }
        }

        return false;

    }

    bool CheckValidity(int *numbers, int length)
    {
        //  输入数据不合法
        if(numbers == NULL || length <= 0)
        {
            return false;
        }

        //  元素必须在[0, n-1]的范围
        for(int i = 0; i < length; i++)
        {
            if(numbers[i] < 0 || numbers[i] > length - 1)
            {
                return false;
            }
        }

        return true;
    }

};


int __tmain( )
{
    Solution solu;
    int result;

    //int array[] = {2, 3, 1, 0, 2, 5, 3};
    int array[] = { 2, 1, 3, 1, 4 };
    if(solu.duplicate(array, 5, &result) == true)
    {
        cout <<result <<endl;
    }

    return 0;
}
