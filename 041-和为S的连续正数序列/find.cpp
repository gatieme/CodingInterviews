#include <iostream>
#include <vector>


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
    vector< vector<int> > FindContinuousSequence(int sum)
    {
        vector< vector<int> > res;
        vector<int> currRes;

        if(sum < 3)
        {
            return res;
        }

        int begin = 1, end = 2, mid = (sum + 1) / 2;
        int currSum = begin + end;

        while(begin < mid && end < sum)
        {
            ///  和正好是sum的话, 就存储下来
            if(currSum == sum)
            {
                currRes.clear( );
                for(int i = begin; i <= end; i++)
                {
                    debug <<i <<" ";
                    currRes.push_back(i);
                }
                debug <<endl;
                res.push_back(currRes);

                ///  存储完以后, 进一步往下走
                end++;
                currSum += end;
            }
            else if(currSum > sum)  /// 如果和太大了, 缩短起始位置
            {
                currSum -= begin;
                begin++;
            }
            else if(currSum < sum)  ///  如果和太小了, 那么增加结束位置
            {
                end++;
                currSum += end;
            }
        }

        return res;
    }
};

int __tmain( )
{
    Solution solu;

    vector< vector<int> > res = solu.FindContinuousSequence(100);

    debug <<"Total Count = "<<res.size( ) <<endl;
    for(unsigned int i = 0; i < res.size( ); i++)
    {
        debug <<"Count = " <<i <<", Size = "<<res[i].size( ) <<endl;
        for(unsigned int j = 0; j < res[i].size( ); j++)
        {
            cout <<res[i][j] <<" ";
        }
        cout <<endl;
    }

    return 0;
}
