#include <iostream>
#include <cstring>


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
        int x[26] = {0}, y[26] = {0};

        for(unsigned int i = 0; i < str.size(); ++i)
        {
            //  小写字母
            if('a' <= str[i] && str[i] <= 'z')
            {
                if(x[str[i] - 'a'] == 0)
                {
                    //  首次出现保存出现位置
                    x[str[i] - 'a'] = i + 1;
                }
                else
                {
                    //  出现多次, 就置标识-1
                    x[str[i] - 'a'] = -1;
                }
                debug <<str[i] <<", " <<x[str[i] - 'a'] <<endl;
            }
            else if('A' <= str[i] && str[i] <= 'Z')      // 大写字母
            {
                if(y[str[i] - 'A'] == 0)
                {
                     //  首次出现保存出现位置
                     y[str[i] - 'A']= i + 1;
                }
                else
                {
                    //  出现多次, 就置标识-1
                    y[str[i] - 'A'] = -1;
                }
                debug <<str[i] <<", " <<y[str[i] - 'A'] <<endl;

            }
        }

        //  由于标识数组中
        //  只出现一次的字符会存储出现的位置
        //  出现多次的字符就存储标识-1
        //  因此查找数组中非-1的最小值即可
        int res = INT_MAX;
        for(int i = 0; i < 26; ++i)
        {
            if(x[i] != 0 && x[i] != -1)
            {
                res = min(res, x[i]);
            }
            if(y[i] != 0 && y[i] != -1)
            {
                res = min(res, y[i]);
            }
        }
        return res > str.size() ? -1 : res - 1;
    }
};

int __tmain( )
{

    Solution solu;
    cout <<solu.FirstNotRepeatingChar("ABACCDEFF") <<endl;

    return 0;
}
