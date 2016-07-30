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
public  :

    //  输出第index个丑数
    int GetUglyNumber_Solution(int index)
    {
        if(index <= 0)
        {
            return -1;
        }

        int count = 1;
        int num = 0;

        while(count <= index)
        {
            num++;
            if(IsUglyNumber(num) == 1)
            {
                debug <<"count = "<<count <<", " <<num <<" is ugly number" <<endl;
                count++;        //  计算丑数的个数
            }
        }

        return num;
    }

protected:

    bool IsUglyNumber(int number)
    {
        while(number % 5 == 0)
        {
            number /= 5;
        }

        while(number % 3 == 0)
        {
            number /= 3;
        }

        while(number % 2 == 0)
        {
            number /= 2;
        }

        return (number == 1);
    }
};


int __tmain( )
{
    Solution solu;

    cout <<solu.GetUglyNumber_Solution(3) <<endl;

    return 0;
}
