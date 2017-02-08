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
                if(!HasDuplicate(str, begin, i))
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
    
private:
    //find duplicate of str[i] in str[k,i)
    bool HasDuplicate(string& str, int k, int i) const {
		for (int p = k; p < i; p++)
			if (str[p] == str[i]) return true;

		return false;
	}
};

int __tmain( )
{
    Solution solu;
    solu.Permutation("abcd");

    return 0;
}
