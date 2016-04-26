#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

//  µ÷ÊÔ¿ª¹Ø
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
    void Permutation(string prefix, string str)
    {

        if(str.length() == 0)
        {
            //cout << prefix << endl;
            m_res.push_back(prefix);
        }
        else
        {
            for(int i = 0; i < str.length(); i++)
            {
                Permutation(prefix+str[i], str.substr(0,i)+str.substr(i+1,str.length()));
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
