#include <iostream>

using namespace std;

//  µ÷ÊÔ¿ª¹Ø
#define __tmain main

#ifdef __tmain

#define dout cout

#else

#define dout 0 && cout

#endif // __tmain




int __tmain( )
{
    dout <<"test" <<endl;
    return 0;
}
