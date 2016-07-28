#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

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
protected:
    vector<string> m_res;

public:
    /*  依次从字符串中取出一个字符作为最终排列的第一个字符，
     *  对剩余字符组成的字符串生成全排列，
     *  最终结果为取出的字符和剩余子串全排列的组合  */
    void Permutation(string prefix, string str)
    {

        if(str.length() == 0)
        {
            //cout << prefix << endl;
            m_res.push_back(prefix);
        }
        else
        {
            for(int i = 0; i < str.length( ); i++)
            {
                debug <<"prefix = " <<prefix + str[i] <<endl;
                debug <<"substr = " <<str.substr(0, i) <<endl;
                debug <<"substr = " <<str.substr(i + 1, str.length( )) <<endl;
                Permutation(prefix + str[i], str.substr(0, i) + str.substr(i + 1, str.length( )));
            }
        }
    }

    vector<string> Permutation(string s)
    {
        m_res.clear( );
        if(s.empty( ) == true)
        {
            return m_res;
        }
        Permutation("",s);

        return m_res;
    }
};

int __tmain( )
{
    Solution solu;
    solu.Permutation("abc");
    return 0;
}
