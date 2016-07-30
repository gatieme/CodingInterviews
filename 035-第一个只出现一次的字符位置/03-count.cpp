#include <iostream>
#include <cstring>


using namespace std;


#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain



class Solution
{

protected:
    int count[256];

public:
    int FirstNotRepeatingChar(string str)
    {
        if(str.length( ) == 0)
        {
            return -1;
        }
        unsigned int i;
        //  将计数器数组清0
        memset(count, '\0', sizeof(count));

        //  对字符串中出现的每个字符进行计数
        for(i = 0; i < str.length( ); i++)
        {
            debug <<(unsigned int)str[i] <<endl;
            count[(unsigned int)str[i]]++;
        }


        //  第一个只出现一次的字符
        for(i = 0; i < str.length( ); i++)
        {
            debug <<str[i] <<", " <<count[(unsigned
                 int)str[i]] <<endl;
            if(count[(unsigned int)str[i]] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};

int __tmain( )
{
    int a = -1;
    unsigned int b = a;
    printf("%u\n", b);

    Solution solu;
    cout <<solu.FirstNotRepeatingChar("abcdefg") <<endl;

    return 0;
}
