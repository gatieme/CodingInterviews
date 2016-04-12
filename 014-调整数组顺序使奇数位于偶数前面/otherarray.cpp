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
    void reOrderArray(vector<int> &array)
    {
        if(array.size( ) <= 1)
        {
            return ;
        }

        vector<int> array_temp;
        vector<int>::iterator ib1, ie1;
        ib1 = array.begin();


        for (; ib1 != array.end();)
        {            //遇见偶数，就保存到新数组，同时从原数组中删除
            if (*ib1 % 2 == 0)
            {
                array_temp.push_back(*ib1);
                ib1 = array.erase(ib1);
            }
            else{
                ib1++;
            }

        }
        vector<int>::iterator ib2, ie2;
        ib2 = array_temp.begin();
        ie2 = array_temp.end();

        for (; ib2 != ie2; ib2++)             //将新数组的数添加到老数组
        {
            array.push_back(*ib2);
        }


    }
};


int __tmain( )
{
    int array[] = { 1, 2, 3, 4, 5, 6, 7};
    vector<int> vec(array, array + 7);
    for(int i = 0; i < 7; i++)
    {
        cout <<vec[i] <<" ";
    }
    cout <<endl;
    Solution solu;
    solu.reOrderArray(vec);

    for(int i = 0; i < 7; i++)
    {
        cout <<vec[i] <<" ";
    }
    cout <<endl;
    return 0;
}
