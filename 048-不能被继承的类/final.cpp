#include <iostream>

using namespace std;


//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain



template <typename T>
class CNoHeritance
{
    friend T;
private:
    CNoHeritance(){ }
    ~CNoHeritance(){ }
};



class SealedClass : virtual public CNoHeritance<SealedClass>
{
public:
    SealedClass( ){ }

    ~SealedClass( ){ }
};

/*
class Base : public SealedClass
{
public:
    Base():SealedClass( ){ }
    ~Base(){ }
};
*/

int __tmain( )
{
    SealedClass  sc;
    //Base base;

    return 0;
}
