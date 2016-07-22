#include <iostream>
#include <cmath>

using namespace std;

//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain



class Solutin
{
public :
    void Print(int n)
    {
        int max = pow(10, n);
        for(int i = 1; i < max; i++)
        {
            cout <<i <<endl;
        }
    }

};


int __tmain( )
{
    Solutin solu;

    int n;
    while(cin >> n)
    {

        solu.Print(n);
    }
    return 0;
}
