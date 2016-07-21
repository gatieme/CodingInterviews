#include <iostream>

using namespace std;

//  µ÷ÊÔ¿ª¹Ø
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain


class Solution
{
public:
    int NumberOf1(int n)
    {
        int count = 0;
        int i = 0;
        unsigned int flag = 1;

        while(flag != 0)
        {
            debug <<n <<" & " <<flag <<" == "<<(n & flag) <<endl;
            if((n & flag) != 0)
            {
                count++;
            }
            flag <<= 1;
        }
        debug <<n <<" & " <<flag <<" == "<<(n & flag) <<endl;

        return count;
    }

};


#include <cmath>

int __tmain( )
{
    cout <<sizeof(long) <<endl;
    Solution solu;
    cout <<solu.NumberOf1(1) <<endl;;
    cout <<solu.NumberOf1(2) <<endl;;
    cout <<solu.NumberOf1(-3) <<endl;;
    cout <<solu.NumberOf1(-2147483648) <<endl;;

    return 0;
}
