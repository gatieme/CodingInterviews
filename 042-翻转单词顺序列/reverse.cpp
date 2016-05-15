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
            return "";
        }

        //  首先翻转整个句子
        Reverse(str, 0, str.size( ) - 1);

        //  紧接着查找到每个单词, 然后翻转它
        int left = 0, right = 0;
        while(right <= str.size( ))
        {
            //  当遇见空格的时候说明找到了一个单词
            //  当走到字符串的最后一个位置, 那么前面如果不是空格, 那么最后也会有一个单词
            if((str[right] == ' ')
            || (right == str.size( ) && str[right - 1] != ' '))
            {
                /*
                for(int i = left; i < right; i++)
                {
                    debug <<str[i];
                }
                debug <<endl;
                */

                Reverse(str, left, right - 1);

                left = right + 1;
            }
            right++;
        }

        return str;
    }

    void Reverse(string &str, int left, int right)
    {
        while(left < right)
        {
            swap(str[left], str[right]);

            left++;
            right--;
        }
    }

    void Reverse(string::iterator left, string::iterator right)
    {
        while(left < right)
        {
            debug <<*left <<", " <<*right <<endl;
            swap(*left, *right);

            left++;
            right--;
        }
    }
};


int __tmain( )
{
    Solution solu;
    cout <<solu.ReverseSentence("student. a am I") <<endl;

    return 0;
}
