#include <iostream>

using namespace std;


//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

class Temp
{
public :
    Temp( )
    {
        ++N;
        Sum += N;
    }

    static void Reset( )
    {
        N = 0;
        Sum = 0;
    }

    static unsigned int GetSum( )
    {
        return Sum;
    }

private :
    static unsigned int N;
    static unsigned int Sum;
};

unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;



class Solution
{
public:
    int res;
    int Sum_Solution(int n)
    {
        Temp::Reset( );

        Temp *a = new Temp[n];
        delete[] a;
        a = NULL;

        return Temp::GetSum( );
    }
};

// 5 4 3 2 1
int __tmain(void)
{
    Solution solu;
    cout <<solu.Sum_Solution(3) <<endl;
    cout <<solu.Sum_Solution(5) <<endl;

}

