#include <iostream>

using namespace std;

#define __tmain main

class Solution
{
public:
    bool match(char* str, char* regex)
    {
        if(*str == NULL)    //  空串的情况, 可以匹配' ', '*'
        {
            if(*regex == NULL
            || (*(regex + 1) == '*' && match(str, regex + 2)))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(*regex == NULL)
        {
            return false;
        }

        if(*(regex + 1) != '*')
        {
            if(*str == *regex || *regex == '.') //  对应字符相等或者可以匹配
            {
                return match(str + 1, regex + 1);
            }
            else
            {
                return false;
            }
        }
        else
        {
            if(*str != *regex && *regex != '.')
            {
                //  匹配
                return match(str, regex + 2);
            }
            else
            {

                //try matches 0 char, skip p and p+1 ('*')
                if(match(str, regex + 2))
                {
                    return true;
                }

                int i = 0;
                while(*(str + i) == *regex || *regex == '.')
                {
                    //try all the length '*' matches
                    if(match(str + i + 1, regex + 2))
                    {
                        return true;
                    }

                    if(*(str + i + 1) == 0)
                    {
                        break;
                    }
                    i ++;
                }

                return false;

            }
        }
    }
};


int __tmain(void)
{


    return EXIT_SUCCESS;

}


