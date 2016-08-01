#include <iostream>
#include <vector>
#include <bitset>


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
    #define INT_SIZE (sizeof(int) * 8)

    #define IS_BIT(number, index) (((number) & (1 << (index))) >>index)

    void FindNumsAppearOnce(vector<int> array, int *num1, int *num2)
    {
        *num1 = *num2 = 0;
        if(array.size( ) < 2)
        {
            return ;
        }
        int XOR = array[0];
        for(int i = 1; i < (int)array.size( ); i++)
        {
            XOR ^= array[i];
        }


        ///  查找到1的位置
        int flag = XOR & (-XOR);

        debug <<" XOR = "<<bitset<INT_SIZE>(XOR) <<endl;
        debug <<"-XOR = "<<bitset<INT_SIZE>(-XOR) <<endl;
        debug <<"flag = "<<bitset<INT_SIZE>(flag) <<endl;

        *num1 = *num2 = XOR;        // 也可以等于XOR
        for(int i = 0; i < (int)array.size( ); i++)
        {
            if((array[i] & flag) == flag)
            {
                *num1 ^= array[i];
            }
            else
            {
                *num2 ^= array[i];
            }
        }
    }
};


int __tmain( )
{
    Solution solu;

    int arr[] = { 2, 4, 3, 6, 3, 2, 5, 5, };
    vector<int> vec(arr, arr + 8);

    int num1, num2;
    solu.FindNumsAppearOnce(vec, &num1, &num2);
    cout <<"RESULT : " <<num1 <<", " <<num2 <<endl;
    return 0;
}
