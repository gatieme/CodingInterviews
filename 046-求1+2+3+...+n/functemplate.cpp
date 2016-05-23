#include <iostream>

using namespace std;


//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain


template < unsigned int n>
struct Sum
{
    enum Value
    {
        N = Sum< n - 1 >::N + n
    };
};

template <>
struct Sum<1>
{
    enum Value
    {
        N = 1
    };
};


int main( )
{

    cout <<Sum<100>::N <<endl;

    return 0;
}



