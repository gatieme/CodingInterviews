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
            // 极端情况按顺序排序, 第i个位置上的数numbers[i]应该等于其下标i
            while(numbers[i] != i)
            {
                debug <<"numbers[" <<i <<"] = " <<numbers[i] <<" isn't equal to it's index = " <<i <<endl;
                //  第numbers[i]位置上的数据numbers[numbers[i]应该是numbers[i]
                //  即数numbers[i]应该是数组第numbers[i]个数numbers[numbers[i]
                if(numbers[i] == numbers[numbers[i]])
                {
                    *duplication = numbers[i];
                    return true;
                }
                debug <<"swap numbers[" <<i <<"] and numbers[" <<numbers[i] <<"]" <<endl;
                swap(numbers[i], numbers[numbers[i]]);
            }
            debug <<"numbers[" <<i <<"] = " <<numbers[i] <<" is equal to it's index = " <<i <<endl;

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

    int array[] = {2, 3, 1, 0, 2, 5, 3};
    if(solu.duplicate(array, 7, &result) == true)
    {
        cout <<result <<endl;
    }

    return 0;
}
