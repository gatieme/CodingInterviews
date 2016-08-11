#include <iostream>

using namespace std;


//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain


class SealedClass
{
private :
    SealedClass( ){ }
    ~SealedClass( ){ }

public  :
    friend SealedClass* GetInstance( );

};


SealedClass* GetInstance( )
{
    return new SealedClass( );
}


class Base : public SealedClass
{
};

int __tmain( )
{
    SealedClass *p = GetInstance( );

    //Base base;    // error

    return 0;
}
