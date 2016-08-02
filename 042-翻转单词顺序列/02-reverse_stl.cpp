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
        if (str.size( ) == 0)
        {
            return str;
        }

        reverse(str.begin(), str.end());

        size_t left = 0;
        size_t right = 0;
        while(right != string::npos)
        {
            left = str.find_first_not_of(' ', left);  //  第一个非空格字符是单词的起始位置
            right = str.find_first_of(' ', left);      //  第一个空格位置标识了单词的结束

            //  处理末尾是空格(原字符串开头是空格的情况)
            //  当最后全是空格的时候，此时可以结束循环
            if (left == string::npos)
            {
                break;
            }
            //  如果查找不到空格, 到了字符串的末尾
            //  此时[degin, str.size( )]是末尾的字符串
            if (right == string::npos)
            {
                reverse(str.begin( ) + left, str.end( ));
            }
            else        //  否则[left, end]是一个单词
            {
                reverse(str.begin( ) + left, str.begin() + right);
                left = right + 1;
            }
        }

        return str;
    }
};

int __tmain( )
{
    Solution solu;
    cout <<solu.ReverseSentence("student. a am I") <<endl;

    return 0;
}
