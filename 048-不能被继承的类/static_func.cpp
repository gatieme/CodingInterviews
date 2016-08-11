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
public  :
    static SealedClass* GetInstance( )
    {
        return new SealedClass( );
    }
private :
    SealedClass( ){ }
    ~SealedClass( ){ };

};

class Base : public SealedClass
{
};

int __tmain( )
{
    SealedClass *pb = Base::GetInstance( );
    Base base;

    return 0;
}
