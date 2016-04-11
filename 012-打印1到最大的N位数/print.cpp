#include <iostream>
#include <cmath>

using namespace std;

//  µ÷ÊÔ¿ª¹Ø
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
        if(n <= 0)
        {
            return;
        }

    }


    void Increment(int n)
    {

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
