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
        if(m_sc == NULL)
        {
            m_sc = new SealedClass( );
        }

        return m_sc;
    }
    static void Destroy( )
    {
        if(m_sc != NULL)
        {
            delete m_sc;
        }
    }
private :
    SealedClass( ){ }
    ~SealedClass( ){ }


    static SealedClass  *m_sc;
};


SealedClass* SealedClass::m_sc = NULL;


class Base : public SealedClass
{
};


int __tmain( )
{
    SealedClass *pb = SealedClass::GetInstance( );
    SealedClass::Destroy( );

    pb = NULL;

    //Base b;  //  error
    return 0;
}
