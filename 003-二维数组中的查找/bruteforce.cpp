#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    bool Find(vector<vector<int> > array,int target)
    {
        int row = 0, col = 0, t = 0;
        bool isFound = false;

        for(int i = 0; i < array.size( ) ; ++i)
        {
            for(int j = 0; j < array[i].size( ); ++j)
            {
                //边输入边验证
                if(false == isFound && target == array[i][j])
                {
                    //已经找到后就没必要再找了
                    isFound = true;
                }
            }
        }

        return isFound;

    }
};
