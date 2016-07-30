#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>


using namespace std;


//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain



template<class T>
string ToString(const T& t)
{

    ostringstream oss;  //  创建一个流

    oss <<t;            //  把值传递如流中
    return oss.str( );  //  获取转换后的字符转并将其写入result
}


class Solution
{
public:

    ///  比较函数
    //  我们比较的不是两个字符串本身的大小，而是他们拼接后的两个数字的大小
    //  在比较时，采用特别的思路----把两个字符串进行拼接，
    //  如果字符串1排在前面的数小，那么就把字符串1放到前面。


    static bool Compare(const string &left, const string &right)
    {
        string leftright = left + right;
        string rightleft = right + left;
        if(leftright > rightleft)
        {
            debug <<leftright <<" > " <<rightleft <<" -- " <<rightleft <<endl;
        }
        else
        {
            debug <<leftright <<" < " <<rightleft <<" -- " <<leftright <<endl;
        }

        return leftright < rightleft;
    }


    string PrintMinNumber(vector<int> numbers)
    {
        string res = "";
        string str;

        vector<string> strNum;

        ///  将整数转换成字符串
        for(unsigned int i = 0; i < numbers.size( ); i++)
        {
            str = ToString(numbers[i]);
            strNum.push_back(str);
            debug <<str <<endl;
        }

        ///  对字符串按照拼接后的大小进行排序
        sort(strNum.begin( ), strNum.end( ), Compare);

        ///  拼接结果
        for(unsigned int i = 0; i < strNum.size( ); i++)
        {
            debug <<strNum[i];
            res += strNum[i];
        }
        debug <<endl;
        return res;
    }
};


int __tmain( )
{
    Solution solu;

    int arr[] = { 321, 32, 3 };
    vector<int> vec(arr, arr + 3);
    cout <<solu.PrintMinNumber(vec) <<endl;
    return 0;
}
