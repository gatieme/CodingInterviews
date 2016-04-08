#include <iostream>

using namespace std;

#define __tmain main


class Solution
{
public:
	void replaceSpace(char *str,int length)
    {
        int i = length - 1, j;
        int len = length;

        //  从后往前遍历
        for(i = length - 1; i >= 0; i--)
        {

            //cout <<str[i] <<endl;
            //  如果当前字符是空格
            if(str[i] == ' ')
            {
                //  从空格变成%20长度增加了2
                len += 2;

                for(j = len - 1; j > i + 2; j--)
                {
                    str[j] = str[j - 2];
                }
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '\%';
            }
            //cout <<str <<endl;
        }
        str[len] = '\0';
	}
};


int __tmain( )
{
    char str[10 + 1] = "a b c d";

    Solution solu;
    solu.replaceSpace(str, 10);

    cout <<str <<endl;

    return 0;
}
