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
        vector<int>::iterator left = array.begin( );
        vector<int>::iterator right = array.end( ) - 1;

        // 三种顺序容器中只有deque和vector容器的迭代器支持大小的比较和算术运算。

        while(left < right)
        //while(left != right)
        {
            debug <<"left = " <<*left <<", right = " <<*right <<endl;
            //system("PAUSE");

            if(((*left & 1) == 0)
              && ((*right & 1) == 1))
            {
                swap(*left, *right);
            }
            left++;

//            if(left == right)
//            {
//                break;
//            }
            right--;
        }

    }
};


int __tmain( )
{
    int array[] = {2, 4, 6, 1, 3, 5};
    vector<int> vec(array, array + 6);
    for(int i = 0; i < 6; i++)
    {
        cout <<vec[i] <<" ";
    }
    cout <<endl;
    Solution solu;
    solu.reOrderArray(vec);

    for(int i = 0; i < 6; i++)
    {
        cout <<vec[i] <<" ";
    }
    cout <<endl;
    return 0;
}
