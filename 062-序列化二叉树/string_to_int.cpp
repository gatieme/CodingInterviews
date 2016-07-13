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
//  使用atoi将char*转换为整数
int StringToIntByatoi(string str)
{
    int num = atoi(str.c_str());
    debug <<"str(" <<str <<") to "<<"int("<<num <<")" <<endl;
    return num;
}

//  使用sscanf将字符串转换为任意格式的信息
int StringToIntBysscanf(string str)
{
    int num;
    sscanf(str.c_str(), "%d", &num);
    debug <<"str(" <<str <<") to "<<"int("<<num <<")" <<endl;
    return num;
}

//  使用stringstream进行字符串的格式化(输入)
int StringToIntBystringstream(string str)
{
    int num;
    stringstream ss;

    ss <<str;
    ss >>num;

    debug <<"str(" <<str <<") to "<<"int("<<num <<")" <<endl;

    return num;
}

//  使用istringstream将字符串转换为整数
int StringToIntByistringstream(string str)
{
    int num;
    istringstream ss;

    ss.str(str);
    ss >>num;

    debug <<"str(" <<str <<") to "<<"int("<<num <<")" <<endl;

    return num;
}

int __tmain( )
{
    StringToIntByatoi("25");
    StringToIntBysscanf("25");
    StringToIntBystringstream("25");
    StringToIntByistringstream("25");



    return EXIT_SUCCESS;
}
