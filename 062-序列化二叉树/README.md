#1    ﻿链接
------- 

>牛客OJ：[序列化二叉树](http://www.nowcoder.com/practice/cf7e25aa97c04cc1a68c8f040e71fb84?tpId=13&tqId=11214&rp=4)
> 
>九度OJ：未收录
> 
>GitHub代码： [062-序列化二叉树](https://github.com/gatieme/CodingInterviews/tree/master/062-序列化二叉树)
>
>CSDN题解：[剑指Offer--062-序列化二叉树](http://blog.csdn.net/gatieme/article/details/51901268)

| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 | 
 |:-----:| -----:| -----:| -----:|
|[062-序列化二叉树](http://www.nowcoder.com/practice/cf7e25aa97c04cc1a68c8f040e71fb84?tpId=13&tqId=11214&rp=4) | 未收录 | [剑指Offer--062-序列化二叉树](http://blog.csdn.net/gatieme/article/details/51901268) | [062-序列化二叉树](https://github.com/gatieme/CodingInterviews/tree/master/062-序列化二叉树) |



#2    ﻿题意

-------



**题目描述**



>请实现两个函数，分别用来序列化和反序列化二叉树。这里没有规定序列化的方式





#3    ﻿分析

-------



##3.1    ﻿遍历二叉树

-------

其实这道题约定的序列化没有固定的格式, 只要你序列化后的结果, 再反序列化后与原树相同即可, 

因此我们可以随意指定自己的格式, 



比如空节点用$表示,或则#表示, 

然后遍历采用先序, 中序, 后序或者层次都可以,



我们的示例程序中采用空结点用#表示, 结点与结点用逗号,分隔





<font color = 0x00ffff>
选择了合适的遍历算法, 那么剩下的问题就是字符串序列和整数权值的相互转换问题
</font>

*   <font color = 0x00ffff>序列化的关键, 其实就是将树的权值(整数)转换为字符串序列, 可以采用ostringstream, sprintf和itoa</font>


*   <font color = 0x00ffff>反序列化的关键, 则正好相反, 将字符串转换为整数, 可以使用istringstream, sscanf和atoi</font>



##3.2    ﻿序列化(整数转换为字符串)
-------
﻿
```c
#include <iostream>
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
```

##3.3    ﻿反序列化(字符串转换为整数)
-------

```c
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
```
﻿

#4  先序方式
-------



用递归实现

序列化二叉树，按照先序遍历二叉树的顺序，先左节点，后右节点，当到‘#’时候，说明左节点或者右节点为NULL，同样反序列二叉树也一个道理，需要注意的是在序列和反序列二叉树的时候，注意字符串与整数的转换，一般字符串转换为整数，用迭代循环实现


```c

#include <iostream>
#include <vector>
#include <sstream>

#include <cstring>
#include <cstdio>


using namespace std;


//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain


#ifdef __tmain

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x = 0) :
    val(x), left(NULL), right(NULL)
    {
    }
};

#endif


class Solution
{
public:
    /*  序列化二叉树  */
    char* Serialize(TreeNode *root)
    {
        if(root == NULL)
        {
            char *serial = new char[3];
            strcpy(serial, "#,");
            return serial;
        }

        string str;
        Serialize(root, str);

        const char  *c_str = str.c_str( );
        char        *serial = new char[str.length( ) + 1];
        strcpy(serial, c_str);

        return serial;
    }

    TreeNode* Deserialize(char *str)
    {
        if(str == NULL|| *str == '\0')
        {
            return NULL;
        }

        int index = 0;

        return Deserialize(str, index);
    }

private :
    void Serialize(TreeNode *root, string &str)
    {
        if(root == NULL)
        {
            str += "#,";
            return;
        }

        /*  先序遍历的方式, 序列化二叉树  */
        str += (toString(root->val) + ",");
        Serialize(root->left, str);
        Serialize(root->right, str);
    }


    /*  反序列化二叉树
     *  将一个序列化的字符串转换成二叉树  */
    TreeNode* Deserialize(char *str, int &index)
    {
        if(str[index] == '#')
        {
            index += 2;
            return NULL;
        }

        /*  获取到节点的数字权值  */
        int num = 0;
        while(str[index] != ',' && str[index] != '\0')
        {
            num = num * 10 + (str[index] - '0');
            index++;
        }
        index++;

        TreeNode *root = new TreeNode(num);
        root->left = Deserialize(str, index);
        root->right = Deserialize(str, index);

        return root;
    }

    string toString(int num)
    {
#if 0
        char ch[10];
        sprintf(ch,"%d,",root->val);
#endif // 0
        stringstream ss;
        ss <<num;
        return ss.str( );
    }
};


int __tmain( )
{
    TreeNode tree[7];

    tree[0].val = 8;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];


    tree[1].val = 6;
    tree[1].left = &tree[3];
    tree[1].right = &tree[4];


    tree[2].val = 10;
    tree[2].left = &tree[5];
    tree[2].right = &tree[6];


    tree[3].val = 5;
    tree[3].left = NULL;
    tree[3].right = NULL;

    tree[4].val = 7;
    tree[4].left = NULL;
    tree[4].right = NULL;

    tree[5].val = 9;
    tree[5].left = NULL;
    tree[5].right = NULL;

    tree[6].val = 11;
    tree[6].left = NULL;
    tree[6].right = NULL;


    Solution solu;
    cout <<solu.Serialize(tree) <<endl;
    cout <<solu.Serialize(solu.Deserialize(solu.Serialize(tree))) <<endl;


    return 0;
}
```









示例程序中将整数转换为字符串使用了stringstream, 当然我们可以充分的使用stringstream

来完成序列化的读取, 如下所示



```c
#define DELIMITERS  " "
class Solution
{
    /*  先序遍历  */
    void PreOrder(TreeNode *node, stringstream &out)
    {
        if (node == NULL)
        {
            out <<"#" <<DELIMITERS;
            return;
        }

        out <<node->val <<DELIMITERS;
        PreOrder(node->left, out);
        PreOrder(node->right, out);
    }

    /*   从字符流in中读取出数字num
     *   成功返回true
     *   失败返回false  */
    bool GetNumber(stringstream &in, int &number)
    {
        char buf[20];

        /* 这里会有个问题, 只能以空格或者换行符分割
         * 然后直接in >>buf读入单个节点的数据 */
        in >>buf;
        if (buf[0] == '#')
        {
            return false;
        }

        number = atoi(buf);

        return true;
    }

    TreeNode* Construct(stringstream &in)
    {
        int val;

        if (GetNumber(in, val))
        {
            TreeNode *node = new TreeNode(val);

            node->left = Construct(in);
            node->right = Construct(in);
            return node;
        }
        return NULL;
    }

public:

    char* Serialize(TreeNode *root)
    {
        stringstream ss;

        PreOrder(root, ss);
        const char *c_str = ss.str().c_str();
        char *serial = new char[ss.str().length() + 1];
        strcpy(serial, c_str);
        return serial;
    }
    TreeNode* Deserialize(char *c_str) {
        if (!c_str) return NULL;
        string str(c_str);
        stringstream ss(str);
        return Construct(ss);
    }
};
```



