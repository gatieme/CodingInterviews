/*************************************************************************
    > File Name: dfs2.c
    > Author: GatieMe
    > Mail: gatieme@163.com
    > Created Time: 2016年04月03日 星期日 11时02分51秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



#define __tmain main

///if      p[j+1] == '*' -> (i + 1, j + 1)
///else if p[i] == p[j] -> (i + 1, j + 2) or (i, j+2)
///else -> (i, j+2)

bool isMatch(const char *s, const char *p)
{
    if (*p == '\0')         //  正则p到底末尾时
    {
        return !(*s);       //  如果串s页到达末尾，则匹配成功
    }

    int slen = strlen(s), plen = strlen(p);

    if (plen == 1           //  如果正则串只有一个长度
    || *(p + 1) != '*')     //  如果匹配×
    {
        return slen && (p[0] == '.' || *s == *p)
            && isMatch(s + 1, p + 1);
    }
    else
    {
        while (*s != '\0' && (*p == '.' || *s == *p))
        {

            if (isMatch(s++, p + 2))
            {
                return true;
            }
        }

    }

    return isMatch(s, p + 2);

}

int __tmain(void)
{


    return EXIT_SUCCESS;

}


