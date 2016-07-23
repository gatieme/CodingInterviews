#include <iostream>
#include <cstring>
using namespace std;

//  调试开关
#define DEBUG
#define __tmain main

#ifdef DEBUG

#define debug cout

#else

#define debug 0 && cout

#endif // DEBUG



class Solutin
{
public :
    void PrintToMaxOfNDigits(int n)
    {
        if(n <= 0)
        {
            return ;
        }

        char *number = new char[n + 1];
        number[n] = '\0';

        PrintToMaxOfNDigitsRecursively(number, n, -1);
        //  最地位循环0~9
        /*
        for(int i = 0; i < 10; i++)
        {
            debug <<"now list all " <<i <<"in the low position" <<endl;
            number[0] = i + '0';
            PrintToMaxOfNDigitsRecursively(number, n, 0);
        }*/

        delete[] number;
    }

    void PrintToMaxOfNDigitsRecursively(char *number, int length, int index)
    {
        if(index == length - 1)
        {
            debug <<"we find a number" <<endl;
            PrintNumber(number);
            return ;
        }

        //  当前位循环0~9
        for(int i = 0; i < 10; i++)
        {
            number[index + 1] = i + '0';
            debug <<"now, index = " <<index <<", digit = " << number[index + 1] <<endl;
            PrintToMaxOfNDigitsRecursively(number, length , index + 1);
        }
    }

    void PrintNumber(char *number)
    {
        int i = 0;
        int length = strlen(number);
        for(i = 0; i < length; i++)
        {
            if(number[i] != '0')
            {
                break;
            }
        }
        if(i != length)         //  开始的0不应该输出
        {
            cout <<&number[i] <<endl;
        }

    }
};


int __tmain( )
{


    int n;\
    Solutin solu;

    while(cin >> n)
    {
        solu.PrintToMaxOfNDigits(n);
    }
    return 0;
}
