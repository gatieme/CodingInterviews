#include <iostream>
#include <vector>
#include <iterator>

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
    int LastRemaining_Solution(unsigned int n, unsigned int m)
    {
        if(n < 1 || m < 1)
        {
            return -1;
        }


        vector<int> numbers;

        for(int i = 0; i < n; i++)
        {
            numbers.push_back(i);
            debug <<i <<" ";
        }
        debug <<endl;

        unsigned int cntN = 0;
        unsigned int cntM = -1;
        while(numbers.size( ) > 1)
        {
            debug <<"count = " <<1 <<", num[" <<cntN <<"] = " <<numbers[cntN] <<endl;
            for(int cntM = 1; cntM < m; cntM++)
            {
                ++cntN;
                cntN %= numbers.size( );
                debug <<"count = " <<cntN + 1 <<", num[" <<cntN <<"] = " <<numbers[cntN] <<endl;
            }

            debug <<numbers[cntN] <<" leave the list" <<endl;
            numbers.erase(numbers.begin( ) + cntN);

#ifdef debug
            copy(numbers.begin( ),
                 numbers.end( ),
                 ostream_iterator< int >(cout, " "));
            debug <<endl;
#endif // debug

        }

        //  循环结束的时候, cntN = 1
        debug <<"count = " <<1 <<", num[" <<cntN <<"] = " <<numbers[cntN] <<endl;
        return numbers[0];
    }
};

int __tmain( )
{
    Solution solu;

    cout <<solu.LastRemaining_Solution(5, 2) <<endl;

    //cout <<solu.LastRemaining_Solution(8, 5) <<endl;;

    //cout <<solu.LastRemaining_Solution(6, 6) <<endl;;

    return 0;
}
