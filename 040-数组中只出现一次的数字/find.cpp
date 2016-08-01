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
    #define INT_SIZE ((int)sizeof(int) * 8)

    #define IS_BIT(number, index) (((number) & (1 << (index))) >>index)

    //  查找数组中只出现一个的两个数
    void FindNumsAppearOnce(vector<int> array, int *num1, int *num2)
    {
        *num1 = *num2 = 0;
        if(array.size( ) < 2)
        {
            return ;
        }

        //  计算数组中所有元素异或的结果
        //  结果将是只出现一次的两个元素的异或结果
        //  其他元素均出现了两次, 异或后结果是0
        int XOR = array[0];
        for(int i = 1; i < (int)array.size( ); i++)
        {
            XOR ^= array[i];
        }
        debug <<"XOR  = "<<bitset<INT_SIZE>(XOR) <<endl;

        //  查找到最终的异或结果中1的位置
        int index = 0, temp = 1;
        for(; index < INT_SIZE; index++)
        {
            if((XOR & temp) == temp)
            {
                break;
            }
            temp <<= 1;
        }

        debug <<"1 find at index = " <<index <<endl;
        if(index == INT_SIZE)
        {
            debug <<"no two numbers which once" <<endl;
            return;
        }
        debug <<"find 1 in index = " <<index <<endl;

        //debug <<IS_BIT(XOR, index) <<endl;

        //  于是我们知道那两个只出现一次的数字, 第index位必然不相同
        //  因此 我们将数组划分成两部分
        //  一部分index位是0
        //  另外一部分index位是1
        *num1 = *num2 = 0;// 也可以等于XOR
        for(int i = 0; i < (int)array.size( ); i++)
        {
            if(IS_BIT(array[i], index) == 1)
            {
                *num1 ^= array[i];
            }
            else
            {
                *num2 ^= array[i];
            }
        }
        debug <<"num1 = " <<num1 <<", num2 = " <<num2 <<endl;

        debug <<"XOR  = "<<bitset<INT_SIZE>(XOR) <<endl;
        debug <<"num1 = "<<bitset<INT_SIZE>(*num1) <<endl;
        debug <<"num2 = "<<bitset<INT_SIZE>(*num2) <<endl;
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
