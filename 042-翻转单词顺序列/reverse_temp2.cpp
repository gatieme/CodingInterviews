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
    string ReverseSentence(string str)
    {
        if(str.size( ) == 0)
        {
            return str;
        }
        string res = "", tmp = "";
        for(unsigned int i = 0; i < str.size(); ++i)
        {
            if(str[i] == ' ')       //  发现一个单词
            {
                debug <<tmp <<endl;
                res = " " + tmp + res;      //  顺序的拼接, 前面需要一个空格
                tmp = "";
            }
            else
            {
                tmp += str[i];
            }
        }
        if(tmp.size() != 0)     //  拼接最后一个单子, 前面无需空格
        {
            res = tmp + res;
        }
        return res;
    }
};

int __tmain( )
{
    Solution solu;
    cout <<solu.ReverseSentence("student. a am I") <<endl;

    return 0;
}
