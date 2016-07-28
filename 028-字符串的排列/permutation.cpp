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

    vector<string> Permutation(string str)
    {
        m_res.clear( );

        if(str.empty( ) == true)
        {
            return m_res;
        }

        sort(m_res.begin( ), m_res.end( ));
        PermutationRecursion(str, 0);

        return m_res;
    }


    void PermutationRecursion(string str, int begin)
    {
        if(str[begin] == '\0')
        {
            debug <<str <<endl;
            m_res.push_back(str);
        }
        else
        {
            for(int i = begin;
                str[i] != '\0';
                i++)
            {
                //debug <<str[i] <<str[begin] <<endl;
                if(i == begin || str[i] != str[begin])
                {
                    swap(str[i], str[begin]);
                    debug <<"swap " <<str[i] <<"(" <<i <<")" <<" and " <<str[begin] <<"(" <<begin <<")" <<endl;
                    PermutationRecursion(str, begin + 1);
                    //copy(str.begin( ), str.degin( ) + i, ostream_iterator<char>(cout," "));
                    swap(str[i], str[begin]);
                }
            }
        }
    }

};

int __tmain( )
{
    Solution solu;
    solu.Permutation("abcd");

    return 0;
}
