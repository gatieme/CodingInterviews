#include <iostream>
#include <iomanip>


using namespace std;


#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain



class Solution
{

public:

    int FirstNotRepeatingChar(string str)
    {
        if(str.length( ) == 0)
        {
            return -1;
        }

        unsigned int length = str.length( );
        unsigned int i, j;
        bool isrepeat = false;


        for(i = 0; i < length; i++)
        {
            isrepeat = false;
            if(str[i] == '\0')
            {
                continue;
            }
            debug <<"str[" <<setfill('0')<<setw(2)<<i <<"] = " <<str[i] <<endl;

            //  堆每一个当前字符i判断其后面有没有跟它相同的字符
            for(j = i + 1; j < length; j++)
            {
                debug <<"str[" <<i <<"] = " <<str[i] <<", "
                      <<"str[" <<j <<"] = " <<str[j] <<endl;;

                if(str[j] == '\0')
                {
                    continue;
                }
                else if(str[i] == str[j])   // 将所有与当前i位置字符相同的字符都置为'\0'
                {
                    debug <<str[i] <<str[j] <<endl;
                    str[j] = '\0';
                    isrepeat = true;
                    //break;
                }
            }
            if(isrepeat == false)
            {
                return i;
            }
        }
        return -1;
    }
};

int __tmain( )
{
    Solution solu;
    cout <<solu.FirstNotRepeatingChar("google") <<endl;

    return 0;
}
