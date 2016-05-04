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
        bool flag = true;
        for(i = 0; i < length; i++)
        {
            flag = true;
            if(str[i] == '\0')
            {
                continue;
            }
            debug <<"str[" <<setfill('0')<<setw(2)<<i <<"] = " <<str[i] <<endl;

            for(j = i + 1; j < length; j++)
            {
                debug <<"str[" <<i <<"] = " <<str[i] <<", ";
                debug <<"str[" <<j <<"] = " <<str[j] <<endl;;

                if(str[j] == '\0')
                {
                    continue;
                }
                else if(str[i] == str[j])
                {
                    debug <<str[i] <<str[j] <<endl;
                    str[j] = '\0';
                    flag = false;
                    //break;
                }

            }
            if(flag == true)
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
