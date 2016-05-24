/*************************************************************************
     > File Name: atoi.c
     > Author: GatieMe
     > Mail: gatieme@163.com
     > Created Time: 2016年04月02日 星期六 22时22分06秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>


#define __tmain main

int myAtoi(const char *str)
{
    // Start typing your C/C++ solution below
    // DO NOT write int main() function

    if (str == NULL)
    {
        return 0;
    }

    //  排除前导的空格
    while (*str == ' ')          //  排除前导的空格
    {
        str++;
    }

    bool minus = false;

    //  判断符号位+ -
    if (*str == '+')
    {
        str++;
    }
    else if (*str == '-')
    {
        str++;
        minus = true;
    }


    long long int value = 0;
    for (; *str != '\0'; str++)
    {

        if ('0' <= *str && *str <= '9')
        {
            value *= 10;
            value += *str - '0';
#ifdef DEBUG
            printf("value = %lld\n", value);
#endif
        }
        else
        {
            break;
        }

        //  解决OVER_FLOW的问题
        if(value > INT_MAX)
        {
            break;
        }

    }

    if (minus == true)
    {
        value = -value;
    }

    if (value > INT_MAX)
    {
        value = INT_MAX;
    }
    else if (value < INT_MIN)
    {
        value = INT_MIN;
    }

    return (int)value;

}


int __tmain(void)
{
     printf("%d", myAtoi("9223372036854775809"));


     return EXIT_SUCCESS;
}
