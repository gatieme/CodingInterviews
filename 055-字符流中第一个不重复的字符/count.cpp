#include <iostream>
#include <cstring>
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
    Solution()
    {
        str = "";
        memset(count, '\0', sizeof(count));
    }

    //  Insert one char from stringstream
    void Insert(char ch)
    {
        str += ch;
        count[(int)ch]++;
    }

    //  Return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int len = str.size( );

        for(int i = 0; i < len; i++)
        {
            if(count[(int)str[i]] == 1)
            {
                return str[i];
            }
        }

        return '#';
    }

private:
    std::string     str;
    int             count[256];


};

int __tmain( )
{
    Solution solu;

    solu.Insert('g');
    cout <<solu.FirstAppearingOnce( ) <<endl;

    solu.Insert('o');
    cout <<solu.FirstAppearingOnce( ) <<endl;

    solu.Insert('o');
    cout <<solu.FirstAppearingOnce( ) <<endl;

    solu.Insert('g');
    cout <<solu.FirstAppearingOnce( ) <<endl;

    solu.Insert('l');
    cout <<solu.FirstAppearingOnce( ) <<endl;

    solu.Insert('e');
    cout <<solu.FirstAppearingOnce( ) <<endl;


    return 0;
}
