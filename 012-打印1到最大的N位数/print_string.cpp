#include <iostream>
#include <cstring>
using namespace std;

//  调试开关
//#define DEBUG
#define __tmain main

#ifdef DEBUG

#define debug cout

#else

#define debug 0 && cout

#endif // DEBUG



class Solutin
{
public :
    Solutin(int n)
    {
        this->m_N = n;
        this->m_isOverFlow = false;

        this->m_number = new char[n + 1];
        memset(m_number, '\0', n + 1);
        this->m_number[n - 1] = '1';
        this->m_length = 1;

        //  m_N 总是 >= m_length
        //  真正的信息串存储在m_number[m_N - length, m_N);
    }

    void Print( )
    {
        if(m_N <= 0)
        {
            return;
        }
        while(this->m_isOverFlow != true)
        {
            PrintNumber( );
            Increment( );

        }




    }

    void PrintNumber( )
    {
        //  m_N 总是 >= m_length
        //  真正的信息串存储在m_number[m_N - length, m_N);
        debug <<"number is stroge in [" <<m_N - m_length <<", " <<m_N <<")" <<endl;
        for(int i = m_N - m_length; i < m_N; i++)
        {
            cout<<m_number[i];
        }
        cout <<endl;
    }


    bool Increment( )
    {
        int nSum = 0;               //  当前位
        int takeOver = 0;           //  进位
        for(int i = m_N - 1; i >= m_N - m_length; i--)
        {
            if(m_number[i] != '\0')
            {
                nSum = m_number[i] - '0' + takeOver;
            }
            else
            {
                nSum = 0;
            }
            nSum++;
            debug <<"nSum = " <<nSum <<endl;

            if(nSum >= 10)      //  需要进位
            {
                if(i == 0)      //  溢出了, 则循环终止
                {
                    m_isOverFlow = true;
                    debug <<"Over Flow now" <<endl;
                    delete m_number;
                }
                else
                {
                    nSum -= 10;
                    m_number[i] = '0' + nSum;

                    takeOver = 1;                   //  需要进位, 继续循环
                    if(i == m_N - m_length)           //  此时说明进位在最高位, 长度会增加1
                    {
                        m_length++;
                        debug <<"take over now ( length = " <<m_length <<" )";
                    }
                }
            }
            else                //  没有进位, 则当前位增加1以后循环立即结束
            {
                if(takeOver == 1)
                {
                    debug <<"it's a take over" <<endl;
                }
                m_number[i] = '0' + nSum;
                break;
            }
        }
    }

private :
    int             m_N;                    //  N位数
    char            *m_number;              //  存储数据的字符串
    bool            m_isOverFlow;           //  是否溢出, 溢出时说明无需继续输出
    volatile int    m_length;               //  当前数字的位数

};


int __tmain( )
{


    int n;
    while(cin >> n)
    {
        Solutin solu(n);
        solu.Print( );
    }
    return 0;
}
