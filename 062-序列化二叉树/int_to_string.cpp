#include <iostream>
#include <vector>
#include <sstream>

#include <cstring>
#include <cstdio>
#include <cstdlib>


using namespace std;


//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain



/*
 * string to int
 */
#ifndef __GNUC__                        /*  GCC or G++  */


//  itoa不是标准C语言函数所以不能在所有的编译器中使用(比如gcc)
string IntToStringByitoa(int num)
{
    char *pstr = itoa(num);
    string str(pstr);
    debug <<"int(" <<num <<") to "<<"str("<<str <<")" <<endl;
    return str;
}
#endif


//  使用sprintf将任意的格式化信息输出到char *中
string IntToStringBysprintf(int num)
{
    char pstr[81];
    sprintf(pstr, "%d", num);

    string str(pstr);

    debug <<"int(" <<num <<") to "<<"str("<<str <<")" <<endl;
    return str;
}


//  使用stringstream进行字符串的格式化
string IntToStringBystringstream(int num)
{
    string str;
    stringstream ss;

    ss <<num;
    ss >>str;

    debug <<"int(" <<num <<") to "<<"str("<<str <<")" <<endl;
    return str;
}

//  使用ostringstream将任意格式的信息转换为字符串(输出)
string IntToStringByostringstream(int num)
{
    string str;
    ostringstream ss;

    ss <<num;
    str = ss.str( );
    debug <<"int(" <<num <<") to "<<"str("<<str <<")" <<endl;
    return str;
}

int __tmain( )
{
#ifndef __GNUC__                        /*  GCC or G++  */
    IntToStringByitoa(25);
#endif
    IntToStringBysprintf(25);
    IntToStringBystringstream(25);
    IntToStringByostringstream(25);



    return EXIT_SUCCESS;
}
