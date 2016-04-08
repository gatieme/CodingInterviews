#include <iostream>

using namespace std;

#define __tmain main


class Solution
{
public:
	void replaceSpace(char *str,int length)
    {
        int i, j;
        int count = 0;
        int len = length;
        for(int i = 0; i < length; i++)
        {
            if(str[i] == ' ')
            {
                count++;
            }
        }

        len = length + count * 2;
        for(i = length - 1, j = len - 1;
            i >= 0 && j >= 0;)
        {
            if(str[i] == ' ')
            {
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
                i--;
            }
            else
            {
                str[j--]  = str[i--];
            }
        }
        str[len] = '0';

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
