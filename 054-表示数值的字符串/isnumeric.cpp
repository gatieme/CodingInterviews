#include <iostream>

using namespace std;


//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

class Solution
{
public:
    bool isNumeric(char* str)
    {
        if(str == NULL)
        {
            return false;
        }

        //  可能遇见符号+/-
        if(*str == '+' || *str == '-')
        {
            ++str;
        }

        if(*str == '\0')
        {
            return false;
        }

        bool numberic = true;

        //  处理可能遇见的数字
        ScanDigits(&str);

        if(*str != '\0')
        {
            if(*str == '.')
            {
                ++str;
                ScanDigits(&str);

                if(*str == 'e' || *str == 'E')
                {
                    numberic = IsExponential(&str);
                }
            }
            else if(*str == 'e' || *str == 'E')
            {
                numberic = IsExponential(&str);
            }
            else
            {

                numberic = false;
            }
        }

        return numberic && *str == '\0';

    }


    void ScanDigits(char **str)
    {
        while(**str != '\0'
          && (**str >= '0' && **str <= '9'))
        {
            ++(*str);
        }
    }

    bool IsExponential(char **str)
    {
        if(**str != 'e' && **str != 'E')
        {
            return false;
        }

        ++(*str);

        if(**str == '+' || **str == '-')
        {
            ++(*str);
        }
        if(**str == '\0')
        {
            return false;
        }
        ScanDigits(str);

        return (**str == '\0') ? true : false;
    }



};


int __tmain( )
{
    Solution solu;

    cout <<solu.isNumeric("1a23") <<endl;

    return 0;
}
