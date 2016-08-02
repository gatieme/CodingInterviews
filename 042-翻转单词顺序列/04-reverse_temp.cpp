#include <iostream>
#include <algorithm>
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
    string ReverseSentence(string str)
    {
        string result;
        while (str.rfind(" ") != -1)
        {
            unsigned long position = str.rfind(" ");
            string temp = str.substr(position + 1);
            //debug <<temp <<endl;
            result = result + temp + ' ';
            str = str.substr(0, position);
            debug <<"str = " <<str <<endl;
        }
        //debug <<str <<endl;
        result = result + str;

        return result;
    }
};


int __tmain( )
{
    Solution solu;
    cout <<solu.ReverseSentence("student. a am I") <<endl;

    return 0;
}
