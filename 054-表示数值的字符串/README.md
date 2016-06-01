#链接
------- 
>牛客OJ：[表示数值的字符串](http://www.nowcoder.com/practice/6f8c901d091949a5837e24bb82a731f2?tpId=13&tqId=11206&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
> 
>九度OJ：未收录
> 
>GitHub代码： [054-表示数值的字符串](https://github.com/gatieme/CodingInterviews/tree/master/054-表示数值的字符串)
>
>CSDN题解：[剑指Offer--054-表示数值的字符串](http://blog.csdn.net/gatieme/article/details/51559282)
| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 | 
| ------------- |:-------------:| -----:| -----:|
|[054-表示数值的字符串](http://www.nowcoder.com/practice/6f8c901d091949a5837e24bb82a731f2?tpId=13&tqId=11206&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | 未收录 | [剑指Offer--054-表示数值的字符串](http://blog.csdn.net/gatieme/article/details/51559282) | [054-表示数值的字符串](https://github.com/gatieme/CodingInterviews/tree/master/054-表示数值的字符串) |



#题目描述
-------

>请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。

例如，
字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。

#分析
-------

我们首先分析一下子**可能是数值的字符串的格式**
在数值之前可能有一个表示正负的’-‘或者’+’。
接下来是若干个0到9的数位表示数值的整数部分（在某些小数里可能没有数值的整数部分）。
如果数值是一个小数，那么在小数点后面可能会有若干个0到9的数位表示数值的小数部分。如果数值用科学计数法表示，接下来是一个’e’或者‘E’，以及紧跟着的一个整数（可以有正负号）表示指数。 
　　
判断一个字符串是否符合上述模式时，
*    首先看第一个字符是不是正负号。
*    如果是，在字符串上移动一个字符，继续扫描剩余的字符串中0到9的数位。
*    如果是一个小数，则将遇到小数点。
*    另外，如果是用科学计数法表示的数值，在整数或者小数的后面还有可能遇到’e’或者’E’。

#代码
-------

```cpp
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
    bool isNumeric(char* str)
    {
        if(str == NULL)
        {
            return false;
        }

        //  可能遇见符号+/-
        if(*str == '+' || *str == '-')
        {
            ++str;
        }

        if(*str == '\0')
        {
            return false;
        }

        bool numberic = true;

        //  处理可能遇见的数字
        ScanDigits(&str);

        if(*str != '\0')
        {
            if(*str == '.')
            {
                ++str;
                ScanDigits(&str);

                if(*str == 'e' || *str == 'E')
                {
                    numberic = IsExponential(&str);
                }
            }
            else if(*str == 'e' || *str == 'E')
            {
                numberic = IsExponential(&str);
            }
            else
            {

                numberic = false;
            }
        }

        return numberic && *str == '\0';

    }


    void ScanDigits(char **str)
    {
        while(**str != '\0'
          && (**str >= '0' && **str <= '9'))
        {
            ++(*str);
        }
    }

    bool IsExponential(char **str)
    {
        if(**str != 'e' && **str != 'E')
        {
            return false;
        }

        ++(*str);

        if(**str == '+' || **str == '-')
        {
            ++(*str);
        }
        if(**str == '\0')
        {
            return false;
        }
        ScanDigits(str);

        return (**str == '\0') ? true : false;
    }



};


int __tmain( )
{
    Solution solu;

    cout <<solu.isNumeric("1a23") <<endl;

    return 0;
}
```