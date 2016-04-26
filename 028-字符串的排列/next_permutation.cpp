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
public:
    vector<string> Permutation(string str)
    {
        vector<string> res;

        if(str.empty( ) == true)
        {
            return res;
        }
        sort(str.begin( ), str.end( ));

        do
        {
            res.push_back(str);
            debug <<str <<endl;
        }
        while(next_permutation(str.begin( ), str.end( )));


        return res;

    }
};

int __tmain( )
{
    Solution solu;
    solu.Permutation("abc");
    return 0;
}
